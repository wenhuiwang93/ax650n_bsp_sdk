/**************************************************************************************************
 *
 * Copyright (c) 2019-2023 Axera Semiconductor (Ningbo) Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor (Ningbo) Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor (Ningbo) Co., Ltd.
 *
 **************************************************************************************************/

#include "OS08b10.h"
#include "GlobalDef.h"

COS08b10::COS08b10(SENSOR_CONFIG_T tSensorConfig) : CBaseSensor(tSensorConfig) {
    m_eImgFormatSDR = AX_FORMAT_BAYER_RAW_12BPP;
    m_eImgFormatHDR = AX_FORMAT_BAYER_RAW_10BPP;
}

COS08b10::~COS08b10(AX_VOID) {
}

AX_SNS_HDR_MODE_E COS08b10::GetMaxHdrMode() {
    if (!GetAbilities().bSupportHDR) {
        return AX_SNS_LINEAR_MODE;
    }

    return AX_SNS_HDR_2X_MODE;
}

AX_VOID COS08b10::InitSnsLibraryInfo(AX_VOID) {
    m_tSnsLibInfo.strLibName = "libsns_os08b10.so";
    m_tSnsLibInfo.strObjName = "gSnsos08b10Obj";
}

AX_VOID COS08b10::InitSnsAttr() {
    /* Referenced by AX_VIN_SetSnsAttr */
    m_tSnsAttr.nWidth = 3840;
    m_tSnsAttr.nHeight = 2160;
    m_tSnsAttr.fFrameRate = m_tSnsCfg.fFrameRate;

    m_tSnsAttr.eSnsMode = m_tSnsCfg.eSensorMode;
    m_tSnsAttr.eRawType = AX_RT_RAW10;

    m_tSnsAttr.eBayerPattern = AX_BP_RGGB;
    m_tSnsAttr.bTestPatternEnable = AX_FALSE;
}

AX_VOID COS08b10::InitSnsClkAttr() {
    /* Referenced by AX_VIN_OpenSnsClk */
    m_tSnsClkAttr.nSnsClkIdx = m_tSnsCfg.nClkID;
    m_tSnsClkAttr.eSnsClkRate = AX_SNS_CLK_24M;
}

AX_VOID COS08b10::InitMipiRxAttr() {
    /* Referenced by AX_MIPI_RX_SetAttr */
    m_tMipiRxDev.eInputMode = AX_INPUT_MODE_MIPI;
    m_tMipiRxDev.tMipiAttr.ePhyMode = AX_MIPI_PHY_TYPE_DPHY;
    m_tMipiRxDev.tMipiAttr.eLaneNum = AX_MIPI_DATA_LANE_4;
    m_tMipiRxDev.tMipiAttr.nDataRate = 1440;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[0] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[1] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[2] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[3] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[4] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[5] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[6] = 0x00;
    m_tMipiRxDev.tMipiAttr.nDataLaneMap[7] = 0x00;
    m_tMipiRxDev.tMipiAttr.nClkLane[0] = 0x00;
    m_tMipiRxDev.tMipiAttr.nClkLane[1] = 0x00;
}

AX_VOID COS08b10::InitDevAttr() {
    /* Referenced by AX_VIN_SetDevAttr */
    m_tDevAttr.bImgDataEnable = AX_TRUE;
    m_tDevAttr.bNonImgDataEnable = AX_FALSE;
    m_tDevAttr.eDevMode = AX_VIN_DEV_OFFLINE;
    m_tDevAttr.eSnsIntfType = AX_SNS_INTF_TYPE_MIPI_RAW;
    for (AX_U8 i = 0; i < AX_HDR_CHN_NUM; i++) {
        m_tDevAttr.tDevImgRgn[i] = {0, 0, 3840, 2160};
    }
    m_tDevAttr.ePixelFmt = AX_FORMAT_BAYER_RAW_10BPP_PACKED;
    m_tDevAttr.eBayerPattern = AX_BP_RGGB;
    m_tDevAttr.eSnsMode = m_tSnsCfg.eSensorMode;
    /* Device compress info must be same as the one of each subsequent pipe */
    m_tDevAttr.tCompressInfo = m_tSnsCfg.arrPipeAttr[0].tIfeCompress;
    m_tDevAttr.eSnsOutputMode = m_tSnsCfg.eSensorMode > AX_SNS_LINEAR_MODE ? AX_SNS_DOL_HDR : AX_SNS_NORMAL;
}

AX_VOID COS08b10::InitPrivAttr() {
    m_tPrivAttr.bEnable = AX_FALSE;
    m_tPrivAttr.ePrivDataMode = AX_PRIVATE_DATA_MODE_BOTTOM;
    for (AX_U8 i = 0; i < AX_HDR_CHN_NUM; i++) {
        m_tPrivAttr.tPrivDataRoiRgn[i] = {0, 0 , 0, 0};
    }
}

AX_VOID COS08b10::InitPipeAttr() {
    /* Referenced by AX_VIN_SetPipeAttr */
    for (AX_U8 i = 0; i < m_tSnsCfg.nPipeCount; i++) {
        AX_U8 nPipe = m_tSnsCfg.arrPipeAttr[i].nPipeID;
        AX_VIN_PIPE_ATTR_T tPipeAttr;
        memset(&tPipeAttr, 0, sizeof(AX_VIN_PIPE_ATTR_T));
        tPipeAttr.tPipeImgRgn = {0, 0, 3840, 2160};
        tPipeAttr.eBayerPattern = AX_BP_RGGB;
        tPipeAttr.nWidthStride = 3840;
        tPipeAttr.ePixelFmt = m_tDevAttr.ePixelFmt;
        tPipeAttr.eSnsMode = m_tSnsCfg.eSensorMode;
        tPipeAttr.bAiIspEnable = m_tSnsCfg.arrPipeAttr[i].bAiEnable;
        tPipeAttr.tCompressInfo = m_tSnsCfg.arrPipeAttr[i].tIfeCompress;
        tPipeAttr.tNrAttr.t3DnrAttr.tCompressInfo = m_tSnsCfg.arrPipeAttr[i].t3DNrCompress;
        tPipeAttr.tNrAttr.tAinrAttr.tCompressInfo = m_tSnsCfg.arrPipeAttr[i].tAiNrCompress;
        tPipeAttr.tFrameRateCtrl.fSrcFrameRate = m_tSnsCfg.fFrameRate;
        tPipeAttr.tFrameRateCtrl.fDstFrameRate = m_tSnsCfg.arrPipeAttr[i].fPipeFramerate;
        m_mapPipe2Attr[nPipe] = tPipeAttr;
    }
}

AX_VOID COS08b10::InitChnAttr() {
    /* Referenced by AX_VIN_SetChnAttr */
    for (AX_U8 i = 0; i < m_tSnsCfg.nPipeCount; i++) {
        PIPE_CONFIG_T& tPipeAttr = m_tSnsCfg.arrPipeAttr[i];

        AX_VIN_CHN_ATTR_T arrChnAttr[AX_VIN_CHN_ID_MAX];
        memset(&arrChnAttr[0], 0, sizeof(AX_VIN_CHN_ATTR_T) * AX_VIN_CHN_ID_MAX);
        AX_F32 fChnDstFrameRate =
            tPipeAttr.arrChannelAttr[0].fFrameRate == 0 ? tPipeAttr.fPipeFramerate : tPipeAttr.arrChannelAttr[0].fFrameRate;
        arrChnAttr[0].nWidth = tPipeAttr.arrChannelAttr[0].nWidth;
        arrChnAttr[0].nHeight = tPipeAttr.arrChannelAttr[0].nHeight;
        arrChnAttr[0].ePixelFmt = AX_FORMAT_YUV420_SEMIPLANAR;
        arrChnAttr[0].nWidthStride =
            ALIGN_UP(arrChnAttr[0].nWidth,
                     tPipeAttr.arrChannelAttr[0].tChnCompressInfo.enCompressMode == AX_COMPRESS_MODE_NONE ? 2 : AX_VIN_FBC_WIDTH_ALIGN_VAL);
        arrChnAttr[0].nDepth = tPipeAttr.arrChannelAttr[0].nYuvDepth;
        arrChnAttr[0].tCompressInfo = tPipeAttr.arrChannelAttr[0].tChnCompressInfo;
        arrChnAttr[0].tFrameRateCtrl.fSrcFrameRate = tPipeAttr.fPipeFramerate;
        arrChnAttr[0].tFrameRateCtrl.fDstFrameRate = fChnDstFrameRate;

        fChnDstFrameRate = tPipeAttr.arrChannelAttr[1].fFrameRate == 0 ? tPipeAttr.fPipeFramerate : tPipeAttr.arrChannelAttr[1].fFrameRate;
        arrChnAttr[1].nWidth = tPipeAttr.arrChannelAttr[1].nWidth;
        arrChnAttr[1].nHeight = tPipeAttr.arrChannelAttr[1].nHeight;
        arrChnAttr[1].ePixelFmt = AX_FORMAT_YUV420_SEMIPLANAR;
        arrChnAttr[1].nWidthStride =
            ALIGN_UP(arrChnAttr[1].nWidth,
                     tPipeAttr.arrChannelAttr[1].tChnCompressInfo.enCompressMode == AX_COMPRESS_MODE_NONE ? 2 : AX_VIN_FBC_WIDTH_ALIGN_VAL);
        arrChnAttr[1].nDepth = tPipeAttr.arrChannelAttr[1].nYuvDepth;
        arrChnAttr[1].tCompressInfo = tPipeAttr.arrChannelAttr[1].tChnCompressInfo;
        arrChnAttr[1].tFrameRateCtrl.fSrcFrameRate = tPipeAttr.fPipeFramerate;
        arrChnAttr[1].tFrameRateCtrl.fDstFrameRate = fChnDstFrameRate;

        fChnDstFrameRate = tPipeAttr.arrChannelAttr[2].fFrameRate == 0 ? tPipeAttr.fPipeFramerate : tPipeAttr.arrChannelAttr[2].fFrameRate;
        arrChnAttr[2].nWidth = tPipeAttr.arrChannelAttr[2].nWidth;
        arrChnAttr[2].nHeight = tPipeAttr.arrChannelAttr[2].nHeight;
        arrChnAttr[2].ePixelFmt = AX_FORMAT_YUV420_SEMIPLANAR;
        arrChnAttr[2].nWidthStride =
            ALIGN_UP(arrChnAttr[2].nWidth,
                     tPipeAttr.arrChannelAttr[2].tChnCompressInfo.enCompressMode == AX_COMPRESS_MODE_NONE ? 2 : AX_VIN_FBC_WIDTH_ALIGN_VAL);
        arrChnAttr[2].nDepth = tPipeAttr.arrChannelAttr[2].nYuvDepth;
        arrChnAttr[2].tCompressInfo = tPipeAttr.arrChannelAttr[2].tChnCompressInfo;
        arrChnAttr[2].tFrameRateCtrl.fSrcFrameRate = tPipeAttr.fPipeFramerate;
        arrChnAttr[2].tFrameRateCtrl.fDstFrameRate = fChnDstFrameRate;

        m_mapPipe2ChnAttr[tPipeAttr.nPipeID][0] = arrChnAttr[0];
        m_mapPipe2ChnAttr[tPipeAttr.nPipeID][1] = arrChnAttr[1];
        m_mapPipe2ChnAttr[tPipeAttr.nPipeID][2] = arrChnAttr[2];
    }
}

AX_VOID COS08b10::InitAbilities() {
    m_tAbilities.bSupportHDR = AX_TRUE;
    m_tAbilities.bSupportHDRSplit = AX_TRUE;
}

AX_VOID COS08b10::InitTriggerAttr() {
    m_tSnapAttr.tPowerAttr.ePowerTriggerMode = AX_VIN_SYNC_OUTSIDE_ELEC_ADAPTIVE_TRIGGER;
    m_tSnapAttr.tPowerAttr.nGpioElecInPin = 22;
    m_tSnapAttr.tPowerAttr.nGpioSyncOutPin = 64;
    m_tSnapAttr.tPowerAttr.nFollowCycle = 3;
    m_tSnapAttr.tPowerAttr.nFreqTolLeft = -2;
    m_tSnapAttr.tPowerAttr.nFreqTolRight = 2;
    m_tSnapAttr.tPowerAttr.nElecFreq = 50;
    m_tSnapAttr.tPowerAttr.nSyncTriggerFreq = 50;
    m_tSnapAttr.tVsyncAttr = {0, AX_VIN_SYNC_POLARITY_HIGH, 2500, 1};
    m_tSnapAttr.tHsyncAttr = {0, AX_VIN_SYNC_POLARITY_HIGH, 16000, 1};
    m_tSnapAttr.tLightSyncAttr = {2500,
                                  16000,
                                  (2500 / (1000 / 25) * 10),
                                  500,
                                  0,
                                  .szShutterParam = {{1, AX_VIN_SHUTTER_MODE_PICTURE},
                                                     {0, AX_VIN_SHUTTER_MODE_VIDEO},
                                                     {1, AX_VIN_SHUTTER_MODE_PICTURE},
                                                     {0, AX_VIN_SHUTTER_MODE_VIDEO},
                                                     {1, AX_VIN_SHUTTER_MODE_PICTURE},
                                                     {0, AX_VIN_SHUTTER_MODE_VIDEO},
                                                     {1, AX_VIN_SHUTTER_MODE_PICTURE},
                                                     {0, AX_VIN_SHUTTER_MODE_VIDEO},
                                                     {1, AX_VIN_SHUTTER_MODE_PICTURE},
                                                     {0, AX_VIN_SHUTTER_MODE_VIDEO}}};
    m_tSnapAttr.tStrobeAttr = {AX_VIN_SYNC_POLARITY_HIGH, 499, 1};
    m_tSnapAttr.tFlashAttr = {AX_VIN_SYNC_POLARITY_HIGH, 50, 1};
}