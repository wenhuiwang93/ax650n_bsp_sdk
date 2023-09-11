/**************************************************************************************************
 *
 * Copyright (c) 2019-2023 Axera Semiconductor (Ningbo) Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor (Ningbo) Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor (Ningbo) Co., Ltd.
 *
 **************************************************************************************************/

#include <stdio.h>
#include <ax_base_type.h>
#include <ax_cipher_api.h>
#include <string.h>
#include <ax_sys_api.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    AX_CIPHER_MODE_E Mode;
    const AX_U8 *Key_p;
    const AX_U8 *Ptx_p;
    const AX_U8 *Ctx_p;
    const AX_U8 *Iv_p;
    AX_U32 KeyLen;
    AX_U32 PtxLen;
} TestVector_DES_Rec_t;
typedef const TestVector_DES_Rec_t *TestVector_DES_t;
#define TEST_VECTOR_DES(key, ptx, ctx, mode, iv) \
    {                                            \
        AX_CIPHER_MODE_CIPHER_##mode,                 \
        key, ptx, ctx, iv,                       \
        sizeof(key), sizeof(ptx)                 \
    }

static const AX_U8 App_A_key [] = {
    0x10, 0x31, 0x6e, 0x02, 0x8c, 0x8f, 0x3b, 0x4a
};

static const AX_U8 App_A_ptx [] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const AX_U8 App_A_ctx [] = {
    0x82, 0xdc, 0xba, 0xfb, 0xde, 0xab, 0x66, 0x02
};

static const AX_U8 IP_and_E_Test_key [] = {
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

static const AX_U8 IP_and_E_Test_ptx [] = {
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};

static const AX_U8 IP_and_E_Test_ctx [] = {
    0x95, 0xf8, 0xa5, 0xe5, 0xdd, 0x31, 0xd9, 0x00, 0xdd, 0x7f, 0x12, 0x1c,
    0xa5, 0x01, 0x56, 0x19, 0x2e, 0x86, 0x53, 0x10, 0x4f, 0x38, 0x34, 0xea,
    0x4b, 0xd3, 0x88, 0xff, 0x6c, 0xd8, 0x1d, 0x4f, 0x20, 0xb9, 0xe7, 0x67,
    0xb2, 0xfb, 0x14, 0x56, 0x55, 0x57, 0x93, 0x80, 0xd7, 0x71, 0x38, 0xef,
    0x6c, 0xc5, 0xde, 0xfa, 0xaf, 0x04, 0x51, 0x2f, 0x0d, 0x9f, 0x27, 0x9b,
    0xa5, 0xd8, 0x72, 0x60, 0xd9, 0x03, 0x1b, 0x02, 0x71, 0xbd, 0x5a, 0x0a,
    0x42, 0x42, 0x50, 0xb3, 0x7c, 0x3d, 0xd9, 0x51, 0xb8, 0x06, 0x1b, 0x7e,
    0xcd, 0x9a, 0x21, 0xe5, 0xf1, 0x5d, 0x0f, 0x28, 0x6b, 0x65, 0xbd, 0x28,
    0xad, 0xd0, 0xcc, 0x8d, 0x6e, 0x5d, 0xeb, 0xa1, 0xe6, 0xd5, 0xf8, 0x27,
    0x52, 0xad, 0x63, 0xd1, 0xec, 0xbf, 0xe3, 0xbd, 0x3f, 0x59, 0x1a, 0x5e,
    0xf3, 0x56, 0x83, 0x43, 0x79, 0xd1, 0x65, 0xcd, 0x2b, 0x9f, 0x98, 0x2f,
    0x20, 0x03, 0x7f, 0xa9, 0x88, 0x9d, 0xe0, 0x68, 0xa1, 0x6f, 0x0b, 0xe6,
    0xe1, 0x9e, 0x27, 0x5d, 0x84, 0x6a, 0x12, 0x98, 0x32, 0x9a, 0x8e, 0xd5,
    0x23, 0xd7, 0x1a, 0xec, 0xe7, 0xfc, 0xe2, 0x25, 0x57, 0xd2, 0x3c, 0x97,
    0x12, 0xa9, 0xf5, 0x81, 0x7f, 0xf2, 0xd6, 0x5d, 0xa4, 0x84, 0xc3, 0xad,
    0x38, 0xdc, 0x9c, 0x19, 0xfb, 0xe0, 0x0a, 0x8a, 0x1e, 0xf8, 0xad, 0x72,
    0x75, 0x0d, 0x07, 0x94, 0x07, 0x52, 0x13, 0x63, 0x64, 0xfe, 0xed, 0x9c,
    0x72, 0x4c, 0x2f, 0xaf, 0xf0, 0x2b, 0x26, 0x3b, 0x32, 0x8e, 0x2b, 0x60,
    0x9d, 0x64, 0x55, 0x5a, 0x9a, 0x10, 0xb8, 0x52, 0xd1, 0x06, 0xff, 0x0b,
    0xed, 0x52, 0x55, 0xd7, 0xe1, 0x65, 0x2c, 0x6b, 0x13, 0x8c, 0x64, 0xa5,
    0xe4, 0x28, 0x58, 0x11, 0x86, 0xec, 0x8f, 0x46, 0xae, 0xb5, 0xf5, 0xed,
    0xe2, 0x2d, 0x1a, 0x36, 0xe9, 0x43, 0xd7, 0x56, 0x8a, 0xec, 0x0c, 0x5c,
    0xdf, 0x98, 0xc8, 0x27, 0x6f, 0x54, 0xb0, 0x4b, 0xb1, 0x60, 0xe4, 0x68,
    0x0f, 0x6c, 0x69, 0x6f, 0xfa, 0x07, 0x52, 0xb0, 0x7d, 0x9c, 0x4a, 0xb8,
    0xca, 0x3a, 0x2b, 0x03, 0x6d, 0xbc, 0x85, 0x02, 0x5e, 0x09, 0x05, 0x51,
    0x7b, 0xb5, 0x9b, 0xcf, 0x81, 0x4e, 0xeb, 0x3b, 0x91, 0xd9, 0x07, 0x26,
    0x4d, 0x49, 0xdb, 0x15, 0x32, 0x91, 0x9c, 0x9f, 0x25, 0xeb, 0x5f, 0xc3,
    0xf8, 0xcf, 0x06, 0x21, 0xab, 0x6a, 0x20, 0xc0, 0x62, 0x0d, 0x1c, 0x6f,
    0x79, 0xe9, 0x0d, 0xbc, 0x98, 0xf9, 0x2c, 0xca, 0x86, 0x6e, 0xce, 0xdd,
    0x80, 0x72, 0xbb, 0x0e, 0x8b, 0x54, 0x53, 0x6f, 0x2f, 0x3e, 0x64, 0xa8,
    0xea, 0x51, 0xd3, 0x97, 0x55, 0x95, 0xb8, 0x6b, 0xca, 0xff, 0xc6, 0xac,
    0x45, 0x42, 0xde, 0x31, 0x8d, 0xd4, 0x5a, 0x2d, 0xdf, 0x90, 0x79, 0x6c,
    0x10, 0x29, 0xd5, 0x5e, 0x88, 0x0e, 0xc2, 0xd0, 0x5d, 0x86, 0xcb, 0x23,
    0x63, 0x9d, 0xbe, 0xa9, 0x1d, 0x1c, 0xa8, 0x53, 0xae, 0x7c, 0x0c, 0x5f,
    0xce, 0x33, 0x23, 0x29, 0x24, 0x8f, 0x32, 0x28, 0x84, 0x05, 0xd1, 0xab,
    0xe2, 0x4f, 0xb9, 0x42, 0xe6, 0x43, 0xd7, 0x80, 0x90, 0xca, 0x42, 0x07,
    0x48, 0x22, 0x1b, 0x99, 0x37, 0x74, 0x8a, 0x23, 0xdd, 0x7c, 0x0b, 0xbd,
    0x61, 0xfa, 0xfd, 0x54, 0x2f, 0xbc, 0x29, 0x1a, 0x57, 0x0d, 0xb5, 0xc4,
    0xe0, 0x7c, 0x30, 0xd7, 0xe4, 0xe2, 0x6e, 0x12, 0x09, 0x53, 0xe2, 0x25,
    0x8e, 0x8e, 0x90, 0xa1, 0x5b, 0x71, 0x1b, 0xc4, 0xce, 0xeb, 0xf2, 0xee,
    0xcc, 0x08, 0x3f, 0x1e, 0x6d, 0x9e, 0x85, 0xf6, 0xd2, 0xfd, 0x88, 0x67,
    0xd5, 0x0d, 0x2d, 0xfe, 0x06, 0xe7, 0xea, 0x22, 0xce, 0x92, 0x70, 0x8f,
    0x16, 0x6b, 0x40, 0xb4, 0x4a, 0xba, 0x4b, 0xd6
};

static const AX_U8 FIPS81_B1_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef
};

static const AX_U8 FIPS81_B1_ptx [] = {
    0x4e, 0x6f, 0x77, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x74,
    0x69, 0x6d, 0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x6c, 0x6c, 0x20
};

static const AX_U8 FIPS81_B1_ctx [] = {
    0x3f, 0xa4, 0x0e, 0x8a, 0x98, 0x4d, 0x48, 0x15, 0x6a, 0x27, 0x17, 0x87,
    0xab, 0x88, 0x83, 0xf9, 0x89, 0x3d, 0x51, 0xec, 0x4b, 0x56, 0x3b, 0x53
};

static const AX_U8 FIPS81_C1_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef
};

static const AX_U8 FIPS81_C1_ptx [] = {
    0x4e, 0x6f, 0x77, 0x20, 0x69, 0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x74,
    0x69, 0x6d, 0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x6c, 0x6c, 0x20
};

static const AX_U8 FIPS81_C1_ctx [] = {
    0xe5, 0xc7, 0xcd, 0xde, 0x87, 0x2b, 0xf2, 0x7c, 0x43, 0xe9, 0x34, 0x00,
    0x8c, 0x38, 0x9c, 0x0f, 0x68, 0x37, 0x88, 0x49, 0x9a, 0x7c, 0x05, 0xf6
};

static const AX_U8 FIPS81_C1_iv [] = {
    0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef
};

static const AX_U8 B_1_3DES_ECB_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x23, 0x45, 0x67, 0x89,
    0xab, 0xcd, 0xef, 0x01, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23
};

static const AX_U8 B_1_3DES_ECB_ptx [] = {
    0x54, 0x68, 0x65, 0x20, 0x71, 0x75, 0x66, 0x63, 0x6b, 0x20, 0x62, 0x72,
    0x6f, 0x77, 0x6e, 0x20, 0x66, 0x6f, 0x78, 0x20, 0x6a, 0x75, 0x6d, 0x70
};

static const AX_U8 B_1_3DES_ECB_ctx [] = {
    0xa8, 0x26, 0xfd, 0x8c, 0xe5, 0x3b, 0x85, 0x5f, 0xcc, 0xe2, 0x1c, 0x81,
    0x12, 0x25, 0x6f, 0xe6, 0x68, 0xd5, 0xc0, 0x5d, 0xd9, 0xb6, 0xb9, 0x00
};

static const AX_U8 TDES_ECB_Ex1_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x23, 0x45, 0x67, 0x89,
    0xab, 0xcd, 0xef, 0x01, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23
};

static const AX_U8 TDES_ECB_Ex1_ptx [] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51
};

static const AX_U8 TDES_ECB_Ex1_ctx [] = {
    0x71, 0x47, 0x72, 0xf3, 0x39, 0x84, 0x1d, 0x34, 0x26, 0x7f, 0xcc, 0x4b,
    0xd2, 0x94, 0x9c, 0xc3, 0xee, 0x11, 0xc2, 0x2a, 0x57, 0x6a, 0x30, 0x38,
    0x76, 0x18, 0x3f, 0x99, 0xc0, 0xb6, 0xde, 0x87
};

static const AX_U8 TDES_ECB_Ex2_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x23, 0x45, 0x67, 0x89,
    0xab, 0xcd, 0xef, 0x01, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef
};

static const AX_U8 TDES_ECB_Ex2_ptx [] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51
};

static const AX_U8 TDES_ECB_Ex2_ctx [] = {
    0x06, 0xed, 0xe3, 0xd8, 0x28, 0x84, 0x09, 0x0a, 0xff, 0x32, 0x2c, 0x19,
    0xf0, 0x51, 0x84, 0x86, 0x73, 0x05, 0x76, 0x97, 0x2a, 0x66, 0x6e, 0x58,
    0xb6, 0xc8, 0x8c, 0xf1, 0x07, 0x34, 0x0d, 0x3d
};

static const AX_U8 TDES_CBC_Ex1_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x23, 0x45, 0x67, 0x89,
    0xab, 0xcd, 0xef, 0x01, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23
};

static const AX_U8 TDES_CBC_Ex1_ptx [] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51
};

static const AX_U8 TDES_CBC_Ex1_ctx [] = {
    0x20, 0x79, 0xc3, 0xd5, 0x3a, 0xa7, 0x63, 0xe1, 0x93, 0xb7, 0x9e, 0x25,
    0x69, 0xab, 0x52, 0x62, 0x51, 0x65, 0x70, 0x48, 0x1f, 0x25, 0xb5, 0x0f,
    0x73, 0xc0, 0xbd, 0xa8, 0x5c, 0x8e, 0x0d, 0xa7
};

static const AX_U8 TDES_CBC_Ex1_iv [] = {
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17
};

static const AX_U8 TDES_CBC_Ex2_key [] = {
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x23, 0x45, 0x67, 0x89,
    0xab, 0xcd, 0xef, 0x01, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef
};

static const AX_U8 TDES_CBC_Ex2_ptx [] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11,
    0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
    0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51
};

static const AX_U8 TDES_CBC_Ex2_ctx [] = {
    0x74, 0x01, 0xce, 0x1e, 0xab, 0x6d, 0x00, 0x3c, 0xaf, 0xf8, 0x4b, 0xf4,
    0x7b, 0x36, 0xcc, 0x21, 0x54, 0xf0, 0x23, 0x8f, 0x9f, 0xfe, 0xcd, 0x8f,
    0x6a, 0xcf, 0x11, 0x83, 0x92, 0xb4, 0x55, 0x81
};

static const AX_U8 TDES_CBC_Ex2_iv [] = {
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17
};

static const TestVector_DES_Rec_t desVectors [] = {
    TEST_VECTOR_DES(App_A_key, App_A_ptx, App_A_ctx, ECB, NULL),
    TEST_VECTOR_DES(IP_and_E_Test_key, IP_and_E_Test_ptx, IP_and_E_Test_ctx, ECB, NULL),
    TEST_VECTOR_DES(FIPS81_B1_key, FIPS81_B1_ptx, FIPS81_B1_ctx, ECB, NULL),
    TEST_VECTOR_DES(FIPS81_C1_key, FIPS81_C1_ptx, FIPS81_C1_ctx, CBC, FIPS81_C1_iv),
    TEST_VECTOR_DES(B_1_3DES_ECB_key, B_1_3DES_ECB_ptx, B_1_3DES_ECB_ctx, ECB, NULL),
    TEST_VECTOR_DES(TDES_ECB_Ex1_key, TDES_ECB_Ex1_ptx, TDES_ECB_Ex1_ctx, ECB, NULL),
    TEST_VECTOR_DES(TDES_ECB_Ex2_key, TDES_ECB_Ex2_ptx, TDES_ECB_Ex2_ctx, ECB, NULL),
    TEST_VECTOR_DES(TDES_CBC_Ex1_key, TDES_CBC_Ex1_ptx, TDES_CBC_Ex1_ctx, CBC, TDES_CBC_Ex1_iv),
    TEST_VECTOR_DES(TDES_CBC_Ex2_key, TDES_CBC_Ex2_ptx, TDES_CBC_Ex2_ctx, CBC, TDES_CBC_Ex2_iv)
};

// *** Start add for performance test case ***
#define    INPUT_DATA_LEN   16
static const AX_U8 App_A_ptx_test [] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const AX_U8 App_A_ctx_test [] = {
    0x82, 0xdc, 0xba, 0xfb, 0xde, 0xab, 0x66, 0x02
};
static const TestVector_DES_Rec_t desVectorsPerformanceTest [] = {
    TEST_VECTOR_DES(App_A_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(IP_and_E_Test_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(FIPS81_B1_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(FIPS81_C1_key, App_A_ptx_test, App_A_ctx_test, CBC, FIPS81_C1_iv),
    TEST_VECTOR_DES(B_1_3DES_ECB_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(TDES_ECB_Ex1_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(TDES_ECB_Ex2_key, App_A_ptx_test, App_A_ctx_test, ECB, NULL),
    TEST_VECTOR_DES(TDES_CBC_Ex1_key, App_A_ptx_test, App_A_ctx_test, CBC, TDES_CBC_Ex1_iv),
    TEST_VECTOR_DES(TDES_CBC_Ex2_key, App_A_ptx_test, App_A_ctx_test, CBC, TDES_CBC_Ex2_iv)
};

// *** Start add for performance test case ***
int SAMPLE_DES_VectorNum(void)
{
    return sizeof(desVectors) / sizeof(desVectors[0]);
}

TestVector_DES_t SAMPLE_DES_VectorGet(int Index)
{
    if (Index >= SAMPLE_DES_VectorNum())
        return NULL;

    return &desVectors[Index];
}

// *** Start add for performance test ***
static char    g_Mode_Array[8] = {0};
static char    g_KeyBitsMode[64] = {0};

static char *SAMPLE_CIPHER_AES_Get_Mode(int index)
{
    memset(g_Mode_Array, 0, sizeof(g_Mode_Array));
    switch (index) {
    case 0:
        strcpy(g_Mode_Array, "ECB");
        break;
    case 1:
        strcpy(g_Mode_Array, "ECB");
        break;
    case 2:
        strcpy(g_Mode_Array, "ECB");
        break;
    case 3:
        strcpy(g_Mode_Array, "CBC");
        break;
    case 4:
        strcpy(g_Mode_Array, "ECB");
        break;
    case 5:
        strcpy(g_Mode_Array, "ECB"); /// ---6
        break;
    case 6:
        strcpy(g_Mode_Array, "ECB");
        break;
    case 7:
        strcpy(g_Mode_Array, "CBC");
        break;
    case 8:
        strcpy(g_Mode_Array, "CBC");
        break;
    default:
        strcpy(g_Mode_Array, "err!");
    }
    return g_Mode_Array;
}
static char *SAMPLE_CIPHER_AES_Get_KeyBitsMode(int index)
{
    memset(g_KeyBitsMode, 0, sizeof(g_KeyBitsMode));
    switch (index) {
    case 0:
        strcpy(g_KeyBitsMode, "App_A_key 64 bits ");
        break;
    case 1:
        strcpy(g_KeyBitsMode, "IP_and_E_Test_key 64 bits ");
        break;
    case 2:
        strcpy(g_KeyBitsMode, "FIPS81_B1_key 64 bits ");
        break;
    case 3:
        strcpy(g_KeyBitsMode, "FIPS81_C1_key 64 bits ");
        break;
    case 4:
        strcpy(g_KeyBitsMode, "(B_1_3DES_ECB_key 192 bits "); //--5
        break;
    case 5:
        strcpy(g_KeyBitsMode, "TDES_ECB_Ex1_key 192 bits ");
        break;
    case 6:
        strcpy(g_KeyBitsMode, "TDES_ECB_Ex2_key 192 bits ");
        break;
    case 7:
        strcpy(g_KeyBitsMode, "TDES_CBC_Ex1_key 192 bits ");
        break;
    case 8:
        strcpy(g_KeyBitsMode, "TDES_CBC_Ex2_key 192 bits ");
        break;
    default:
        strcpy(g_KeyBitsMode, "err!");
    }
    return g_KeyBitsMode;
}
static  AX_U64  t1 = 0, t2 = 0;
static  AX_F32  averageCost = 0;
static  AX_F32  mPerSecond = 0;

static AX_U64 get_time_us(AX_VOID)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
}
// **** End add for performance test ****
int SAMPLE_CIPHER_DES_Encrypt()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_DES_t tv_p;
    unsigned char resultText[512];
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_DES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_DES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(resultText, 0, sizeof(resultText));
            if (AX_CIPHER_Encrypt(handler, (AX_U8 *)tv_p->Ptx_p, resultText, tv_p->PtxLen) == AX_SUCCESS) {
                if (memcmp(resultText, tv_p->Ctx_p, tv_p->PtxLen) != 0) {
                    printf("Encrypt compare error, %d\n", Index);
                }
                Success++;
            } else {
                printf("encrypt error %d\n", Index);
                Failed++;
            }
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Process vector %d\n", Index);
            Failed++;
        }
    }
    if (Failed) {
        printf("DES_Encrypt wrong tests %d\n", Failed);
    } else {
        printf("DES_Encrypt PASS\n");
    }
    return 0;
}

int SAMPLE_CIPHER_DES_Decrypt()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_DES_t tv_p;
    unsigned char resultText[512];
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_DES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_DES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(resultText, 0, sizeof(resultText));
            if (AX_CIPHER_Decrypt(handler, (AX_U8 *)tv_p->Ctx_p, resultText, tv_p->PtxLen) == AX_SUCCESS) {
                if (memcmp(resultText, tv_p->Ptx_p, tv_p->PtxLen) != 0) {
                    printf("decrypt compare error %d\n", Index);
                }
                Success++;
            } else {
                printf("decrypt error %d\n", Index);
                Failed++;
            }
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Process vector %d\n", Index);
            Failed++;
        }
    }
    if (Failed) {
        printf("DES_Decrypt wrong tests %d\n", Failed);
    } else {
        printf("DES_Decrypt PASS\n");
    }
    return 0;
}
static int SAMPLE_CIPHER_DES_Encrypt_PerformanceTest()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_DES_t tv_p;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    ret1 = AX_SYS_MemAlloc(&phySrc, (AX_VOID **)&src, 1024 * 1024 * INPUT_DATA_LEN, 64, (AX_S8 *)"ce_sample");
    if (ret1 < 0) {
        printf("PhySrc Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }
    ret1 = AX_SYS_MemAlloc(&phyDst, (AX_VOID **)&dst, 1024 * 1024 * INPUT_DATA_LEN, 64, (AX_S8 *)"ce_sample");
    if (ret1 < 0) {
        AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
        printf("PhyDst Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }
    for (Index = 0; Index < sizeof(desVectorsPerformanceTest) / sizeof(desVectorsPerformanceTest[0]); Index++) {
        tv_p = &desVectorsPerformanceTest[Index];
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_DES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            t1 = get_time_us();
            for (int k = 0; k < 10; k++) {
                if (AX_CIPHER_EncryptPhy(handler, phySrc, phyDst, 1024 * 1024 * INPUT_DATA_LEN) == AX_SUCCESS) {
                    Success++;
                } else {
                    printf("phy addr encrypt error index = %d, k = %d .\n", Index, k);
                    Failed++;
                }
            }
            t2 = get_time_us();
            averageCost = (AX_F32)(t2 - t1) / 10 / 1000000;
            mPerSecond = (AX_F32)INPUT_DATA_LEN / averageCost;
            printf("DES Encrypt %s Mode, key bits %s Mode: perf encryt:%lfMB/s \n",
                   SAMPLE_CIPHER_AES_Get_Mode(Index), SAMPLE_CIPHER_AES_Get_KeyBitsMode(Index), mPerSecond);

            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Process vector %d ret = 0x%x \n", Index, ret);
            Failed++;
        }
    }
    AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
    AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);
    if (Failed) {
        printf("DES_Phy_Encrypt wrong tests %d\n", Failed);
    } else {
        printf("DES_Phy_Encrypt PASS\n\n");
    }
    return 0;
}
static int SAMPLE_CIPHER_DES_Decrypt_PerformanceTest()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_DES_t tv_p;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    ret1 = AX_SYS_MemAlloc(&phySrc, (AX_VOID **)&src, 1024 * 1024 * INPUT_DATA_LEN, 64, (AX_S8 *)"ce_sample");
    if (ret1 < 0) {
        printf("PhySrc Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }
    ret1 = AX_SYS_MemAlloc(&phyDst, (AX_VOID **)&dst, 1024 * 1024 * INPUT_DATA_LEN, 64, (AX_S8 *)"ce_sample");
    if (ret1 < 0) {
        AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
        printf("PhyDst Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }
    for (Index = 0; Index < sizeof(desVectorsPerformanceTest) / sizeof(desVectorsPerformanceTest[0]); Index++) {
        tv_p = &desVectorsPerformanceTest[Index];
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_DES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;

        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            t1 = get_time_us();
            for (int k = 0; k < 10; k++) {
                if (AX_CIPHER_DecryptPhy(handler, phySrc, phyDst, 1024 * 1024 * INPUT_DATA_LEN) == AX_SUCCESS) {
                    Success++;
                } else {
                    printf("DES Phy addr decrypt error index = %d, k = %d .\n", Index, k);
                    Failed++;
                }
            }
            t2 = get_time_us();
            averageCost = (AX_F32)(t2 - t1) / 10 / 1000000;
            mPerSecond = (AX_F32)INPUT_DATA_LEN / averageCost;
            printf("DES Decrypt %s Mode, key bits %s Mode: perf decrypt:%lfMB/s \n",
                   SAMPLE_CIPHER_AES_Get_Mode(Index), SAMPLE_CIPHER_AES_Get_KeyBitsMode(Index), mPerSecond);

            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Process vector %d\n", Index);
            Failed++;
        }
    }
    AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
    AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);

    if (Failed) {
        printf("DES_Phy_Decrypt wrong tests %d\n", Failed);
    } else {
        printf("DES_Phy_Decrypt PASS\n\n");
    }
    return 0;
}
int SAMPLE_CIPHER_DES_PerformanceTest()
{
    SAMPLE_CIPHER_DES_Encrypt_PerformanceTest();
    SAMPLE_CIPHER_DES_Decrypt_PerformanceTest();
    return 0;
}
