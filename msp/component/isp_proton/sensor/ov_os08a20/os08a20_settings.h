/**************************************************************************************************
 *
 * Copyright (c) 2019-2023 Axera Semiconductor (Ningbo) Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor (Ningbo) Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor (Ningbo) Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __OS08A20_SETTING_H__
#define __OS08A20_SETTING_H__

#include "isp_sensor_internal.h"


typedef enum {
    e_OS08A20_setting_sel_min = 0,
    e_OS08A20_4lane_3840x2160_Linear_10bit_25fps_1440Mbps,
    e_OS08A20_4lane_3840x2160_Linear_10bit_30fps_1440Mbps,
    e_OS08A20_4lane_3840x2160_hdr_10bit_25fps_1280Mbps,
    e_OS08A20_4lane_3840x2160_hdr_10bit_30fps_1280Mbps,
    e_OS08A20_4lane_3840x2160_Linear_10bit_50fps_1440Mbps,
    e_OS08A20_4lane_3840x2160_Linear_10bit_60fps_1440Mbps,
    e_OS08A20_4lane_3840x2160_Linear_12bit_25fps_1280Mbps,
    e_OS08A20_4lane_3840x2160_Linear_12bit_30fps_1280Mbps,
    e_OS08A20_2lane_3840x2160_Linear_10bit_30fps_1440Mbps,
    e_OS08A20_setting_sel_max
} OS08A20_SETTING_SEL_E;

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_12bit_30fps_1280Mbps[] = {

// OS08A_Res 3840X2160 4lane MIPI1278Mbps Linear12 30fps MCLK24M
    {0x0100, 0x00}, // stream off
    {0x0103, 0x01},
    {0x0303, 0x01},
    {0x0305, 0x50},
    {0x0306, 0x00},
    {0x0308, 0x03},
    {0x0309, 0x04},
    {0x032a, 0x00},
    {0x300f, 0x11},
    {0x3010, 0x01},
    {0x3011, 0x04},
    {0x3012, 0x41},
    {0x3016, 0xf0},
    {0x301e, 0x98},
    {0x3031, 0xa9},
    {0x3103, 0x92},
    {0x3104, 0x01},
    {0x3106, 0x10},
    {0x3400, 0x04},
    {0x3025, 0x03},
    {0x3425, 0x01},
    {0x3428, 0x01},
    {0x3406, 0x08},
    {0x3408, 0x03},
    {0x340c, 0xff},
    {0x340d, 0xff},
    {0x031e, 0x0a},
    {0x3501, 0x08},
    {0x3502, 0xe5},
    {0x3505, 0x83},
    {0x3508, 0x00},
    {0x3509, 0x80},
    {0x350a, 0x04},
    {0x350b, 0x00},
    {0x350c, 0x00},
    {0x350d, 0x80},
    {0x350e, 0x04},
    {0x350f, 0x00},
    {0x3600, 0x00},
    {0x3603, 0x2c},
    {0x3605, 0x50},
    {0x3609, 0xdb},
    {0x3610, 0x39},
    {0x360c, 0x01},
    {0x3628, 0xa4},
    {0x362d, 0x10},
    {0x3660, 0xd3},
    {0x3661, 0x06},
    {0x3662, 0x00},
    {0x3663, 0x28},
    {0x3664, 0x0d},
    {0x366a, 0x38},
    {0x366b, 0xa0},
    {0x366d, 0x00},
    {0x366e, 0x00},
    {0x3680, 0x00},
    {0x36c0, 0x00},
    {0x3701, 0x02},
    {0x373b, 0x02},
    {0x373c, 0x02},
    {0x3736, 0x02},
    {0x3737, 0x02},
    {0x3705, 0x00},
    {0x3706, 0x72},
    {0x370a, 0x01},
    {0x370b, 0x30},
    {0x3709, 0x48},
    {0x3714, 0x21},
    {0x371c, 0x00},
    {0x371d, 0x08},
    {0x3740, 0x1b},
    {0x3741, 0x04},
    {0x375e, 0x0b},
    {0x3760, 0x10},
    {0x3776, 0x10},
    {0x3781, 0x02},
    {0x3782, 0x04},
    {0x3783, 0x02},
    {0x3784, 0x08},
    {0x3785, 0x08},
    {0x3788, 0x01},
    {0x3789, 0x01},
    {0x3797, 0x04},
    {0x3762, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x6f},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x380c, 0x08},
    {0x380d, 0x18},
    {0x380e, 0x09},
    {0x380f, 0x00}, //vts
    {0x3813, 0x10},

    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x00},
    {0x3804, 0x0F},
    {0x3805, 0x1F},
    {0x3806, 0x08},
    {0x3807, 0x8F},
    {0x3808, 0x0F},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x3810, 0x00},
    {0x3811, 0x10},
    {0x3812, 0x00},
    {0x3813, 0x11},

    {0x3814, 0x01},
    {0x3815, 0x01},
    {0x3816, 0x01},
    {0x3817, 0x01},
    {0x381c, 0x00},
    {0x3820, 0x00},
    {0x3821, 0x04},
    {0x3823, 0x08},
    {0x3826, 0x00},
    {0x3827, 0x08},
    {0x382d, 0x08},
    {0x3832, 0x02},
    {0x3833, 0x00},
    {0x383c, 0x48},
    {0x383d, 0x60}, //0xff
    {0x3d85, 0x0b},
    {0x3d84, 0x40},
    {0x3d8c, 0x63},
    {0x3d8d, 0xd7},
    {0x4000, 0xf8},
    {0x4001, 0x2b},
    {0x4004, 0x00},
    {0x4005, 0x40},
    {0x400a, 0x01},
    {0x400f, 0xa0},
    {0x4010, 0x12},
    {0x4018, 0x00},
    {0x4008, 0x02},
    {0x4009, 0x0d},
    {0x401a, 0x58},
    {0x4050, 0x00},
    {0x4051, 0x01},
    {0x4028, 0x2f},
    {0x4052, 0x00},
    {0x4053, 0x80},
    {0x4054, 0x00},
    {0x4055, 0x80},
    {0x4056, 0x00},
    {0x4057, 0x80},
    {0x4058, 0x00},
    {0x4059, 0x80},
    {0x430b, 0xff},
    {0x430c, 0xff},
    {0x430d, 0x00},
    {0x430e, 0x00},
    {0x4501, 0x18},
    {0x4502, 0x00},
    {0x4600, 0x00},
    {0x4601, 0x20},
    {0x4603, 0x01},
    {0x4643, 0x00},
    {0x4640, 0x01},
    {0x4641, 0x04},
    {0x4800, 0x64}, //mipi ctrl0
    {0x4809, 0x2b},
    {0x4813, 0x90},
    {0x4817, 0x04},
    {0x4833, 0x18},
    {0x4837, 0x0b},
    {0x483b, 0x00},
    {0x484b, 0x03},
    {0x4850, 0x7c},
    {0x4852, 0x06},
    {0x4856, 0x58},
    {0x4857, 0xaa},
    {0x4862, 0x0a},
    {0x4869, 0x18},
    {0x486a, 0xaa},
    {0x486e, 0x03},
    {0x486f, 0x55},
    {0x4875, 0xf0},
    {0x5000, 0x89},
    {0x5001, 0x42},
    {0x5004, 0x40},
    {0x5005, 0x00},
    {0x5180, 0x00},
    {0x5181, 0x10},
    {0x580b, 0x03},
    {0x4d00, 0x03},
    {0x4d01, 0xc9},
    {0x4d02, 0xbc},
    {0x4d03, 0xc6},
    {0x4d04, 0x4a},
    {0x4d05, 0x25},
    {0x4700, 0x2b},
    {0x4e00, 0x2b},
    {0x3501, 0x09},
    {0x3502, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x00}, //stream off

};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_12bit_25fps_1280Mbps[] = {
// OS08A_Res 3840X2160 4lane MIPI1278Mbps Linear12 25fps MCLK24M
    {0x0100, 0x00}, // stream off
    {0x0103, 0x01},
    {0x0303, 0x01},
    {0x0305, 0x50},
    {0x0306, 0x00},
    {0x0308, 0x03},
    {0x0309, 0x04},
    {0x032a, 0x00},
    {0x300f, 0x11},
    {0x3010, 0x01},
    {0x3011, 0x04},
    {0x3012, 0x41},
    {0x3016, 0xf0},
    {0x301e, 0x98},
    {0x3031, 0xa9},
    {0x3103, 0x92},
    {0x3104, 0x01},
    {0x3106, 0x10},
    {0x3400, 0x04},
    {0x3025, 0x03},
    {0x3425, 0x01},
    {0x3428, 0x01},
    {0x3406, 0x08},
    {0x3408, 0x03},
    {0x340c, 0xff},
    {0x340d, 0xff},
    {0x031e, 0x0a},
    {0x3501, 0x08},
    {0x3502, 0xe5},
    {0x3505, 0x83},
    {0x3508, 0x00},
    {0x3509, 0x80},
    {0x350a, 0x04},
    {0x350b, 0x00},
    {0x350c, 0x00},
    {0x350d, 0x80},
    {0x350e, 0x04},
    {0x350f, 0x00},
    {0x3600, 0x00},
    {0x3603, 0x2c},
    {0x3605, 0x50},
    {0x3609, 0xdb},
    {0x3610, 0x39},
    {0x360c, 0x01},
    {0x3628, 0xa4},
    {0x362d, 0x10},
    {0x3660, 0xd3},
    {0x3661, 0x06},
    {0x3662, 0x00},
    {0x3663, 0x28},
    {0x3664, 0x0d},
    {0x366a, 0x38},
    {0x366b, 0xa0},
    {0x366d, 0x00},
    {0x366e, 0x00},
    {0x3680, 0x00},
    {0x36c0, 0x00},
    {0x3701, 0x02},
    {0x373b, 0x02},
    {0x373c, 0x02},
    {0x3736, 0x02},
    {0x3737, 0x02},
    {0x3705, 0x00},
    {0x3706, 0x72},
    {0x370a, 0x01},
    {0x370b, 0x30},
    {0x3709, 0x48},
    {0x3714, 0x21},
    {0x371c, 0x00},
    {0x371d, 0x08},
    {0x3740, 0x1b},
    {0x3741, 0x04},
    {0x375e, 0x0b},
    {0x3760, 0x10},
    {0x3776, 0x10},
    {0x3781, 0x02},
    {0x3782, 0x04},
    {0x3783, 0x02},
    {0x3784, 0x08},
    {0x3785, 0x08},
    {0x3788, 0x01},
    {0x3789, 0x01},
    {0x3797, 0x04},
    {0x3762, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x6f},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x380c, 0x08},
    {0x380d, 0x18},
    {0x380e, 0x0A},
    {0x380f, 0xD0}, //vts
    {0x3813, 0x10},

    {0x3800,  0x00},
    {0x3801,  0x00},
    {0x3802,  0x00},
    {0x3803,  0x00},
    {0x3804,  0x0F},
    {0x3805,  0x1F},
    {0x3806,  0x08},
    {0x3807,  0x8F},
    {0x3808,  0x0F},
    {0x3809,  0x00},
    {0x380a,  0x08},
    {0x380b,  0x70},
    {0x3810,  0x00},
    {0x3811,  0x10},
    {0x3812,  0x00},
    {0x3813,  0x11},

    {0x3814, 0x01},
    {0x3815, 0x01},
    {0x3816, 0x01},
    {0x3817, 0x01},
    {0x381c, 0x00},
    {0x3820, 0x00},
    {0x3821, 0x04},
    {0x3823, 0x08},
    {0x3826, 0x00},
    {0x3827, 0x08},
    {0x382d, 0x08},
    {0x3832, 0x02},
    {0x3833, 0x00},
    {0x383c, 0x48},
    {0x383d, 0x60}, //0xff
    {0x3d85, 0x0b},
    {0x3d84, 0x40},
    {0x3d8c, 0x63},
    {0x3d8d, 0xd7},
    {0x4000, 0xf8},
    {0x4001, 0x2b},
    {0x4004, 0x00},
    {0x4005, 0x40},
    {0x400a, 0x01},
    {0x400f, 0xa0},
    {0x4010, 0x12},
    {0x4018, 0x00},
    {0x4008, 0x02},
    {0x4009, 0x0d},
    {0x401a, 0x58},
    {0x4050, 0x00},
    {0x4051, 0x01},
    {0x4028, 0x2f},
    {0x4052, 0x00},
    {0x4053, 0x80},
    {0x4054, 0x00},
    {0x4055, 0x80},
    {0x4056, 0x00},
    {0x4057, 0x80},
    {0x4058, 0x00},
    {0x4059, 0x80},
    {0x430b, 0xff},
    {0x430c, 0xff},
    {0x430d, 0x00},
    {0x430e, 0x00},
    {0x4501, 0x18},
    {0x4502, 0x00},
    {0x4600, 0x00},
    {0x4601, 0x20},
    {0x4603, 0x01},
    {0x4643, 0x00},
    {0x4640, 0x01},
    {0x4641, 0x04},
    {0x4800, 0x64}, //mipi ctrl0
    {0x4809, 0x2b},
    {0x4813, 0x90},
    {0x4817, 0x04},
    {0x4833, 0x18},
    {0x4837, 0x0b},
    {0x483b, 0x00},
    {0x484b, 0x03},
    {0x4850, 0x7c},
    {0x4852, 0x06},
    {0x4856, 0x58},
    {0x4857, 0xaa},
    {0x4862, 0x0a},
    {0x4869, 0x18},
    {0x486a, 0xaa},
    {0x486e, 0x03},
    {0x486f, 0x55},
    {0x4875, 0xf0},
    {0x5000, 0x89},
    {0x5001, 0x42},
    {0x5004, 0x40},
    {0x5005, 0x00},
    {0x5180, 0x00},
    {0x5181, 0x10},
    {0x580b, 0x03},
    {0x4d00, 0x03},
    {0x4d01, 0xc9},
    {0x4d02, 0xbc},
    {0x4d03, 0xc6},
    {0x4d04, 0x4a},
    {0x4d05, 0x25},
    {0x4700, 0x2b},
    {0x4e00, 0x2b},
    {0x3501, 0x09},
    {0x3502, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x01},
    {0x0100, 0x00}, //stream off
};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_hdr_10bit_25fps_1280Mbps[] = {
// OS08A_Res 3840X2160 4lane MIPI1440Mbps HDRVC10 25fps MCLK24M

    {0x0100, 0x00}, //stream off
    {0x0103, 0x01},
    {0x0303, 0x01},
    {0x0305, 0x5A},
    {0x0306, 0x00},
    {0x0308, 0x03},
    {0x0309, 0x04},
    {0x0325, 0x48},
    {0x032a, 0x00},
    {0x300f, 0x11},
    {0x3010, 0x01},
    {0x3011, 0x04},
    {0x3012, 0x41},
    {0x3016, 0xf0},
    {0x301e, 0x98},
    {0x3031, 0xa9},
    {0x3103, 0x92},
    {0x3104, 0x01},
    {0x3106, 0x10},
    {0x340c, 0xff},
    {0x340d, 0xff},
    {0x031e, 0x09},
    {0x3501, 0x08},
    {0x3502, 0xe5},
    {0x3505, 0x83},
    {0x3508, 0x00},
    {0x3509, 0x80},
    {0x350a, 0x04},
    {0x350b, 0x00},
    {0x350c, 0x00},
    {0x350d, 0x80},
    {0x350e, 0x04},
    {0x350f, 0x00},
    {0x3600, 0x00},
    {0x3603, 0x2c},
    {0x3605, 0x50},
    {0x3609, 0xb5},
    {0x3610, 0x39},
    {0x360c, 0x01},
    {0x3628, 0xa4},
    {0x362d, 0x10},
    {0x3660, 0x42},
    {0x3661, 0x07},
    {0x3662, 0x00},
    {0x3663, 0x28},
    {0x3664, 0x0d},
    {0x366a, 0x38},
    {0x366b, 0xa0},
    {0x366d, 0x00},
    {0x366e, 0x00},
    {0x3680, 0x00},
    {0x36c0, 0x00},
    {0x3701, 0x02},
    {0x373b, 0x02},
    {0x373c, 0x02},
    {0x3736, 0x02},
    {0x3737, 0x02},
    {0x3705, 0x00},
    {0x3706, 0x39},
    {0x370a, 0x00},
    {0x370b, 0x98},
    {0x3709, 0x49},
    {0x3714, 0x21},
    {0x371c, 0x00},
    {0x371d, 0x08},
    {0x3740, 0x1b},
    {0x3741, 0x04},
    {0x375e, 0x0b},
    {0x3760, 0x10},
    {0x3776, 0x10},
    {0x3781, 0x02},
    {0x3782, 0x04},
    {0x3783, 0x02},
    {0x3784, 0x08},
    {0x3785, 0x08},
    {0x3788, 0x01},
    {0x3789, 0x01},
    {0x3797, 0x04},
    {0x3762, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x6f},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x380c, 0x04},
    {0x380d, 0x0c},
    {0x380e, 0x0a},
    {0x380f, 0xe0},  // increase vts from 0x90c(30fps) to 0xae0(25fps), to fix 2DOL no streaming issue
    {0x3813, 0x10},

    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x00},
    {0x3804, 0x0F},
    {0x3805, 0x1F},
    {0x3806, 0x08},
    {0x3807, 0x8F},
    {0x3808, 0x0F},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x3810, 0x00},
    {0x3811, 0x10},
    {0x3812, 0x00},
    {0x3813, 0x11},

    {0x3814, 0x01},
    {0x3815, 0x01},
    {0x3816, 0x01},
    {0x3817, 0x01},
    {0x381c, 0x08},
    {0x3820, 0x00},
    {0x3821, 0x24},
    {0x3823, 0x08},
    {0x3826, 0x00},
    {0x3827, 0x08},
    {0x382d, 0x08},
    {0x3832, 0x02},
    {0x3833, 0x01},
    {0x383c, 0x48},
    {0x383d, 0x60}, //ff
    {0x3d85, 0x0b},
    {0x3d84, 0x40},
    {0x3d8c, 0x63},
    {0x3d8d, 0xd7},
    {0x4000, 0xf8},
    {0x4001, 0x2b},
    {0x4004, 0x00},
    {0x4005, 0x40},
    {0x400a, 0x01},
    {0x400f, 0xa0},
    {0x4010, 0x12},
    {0x4018, 0x00},
    {0x4008, 0x02},
    {0x4009, 0x0d},
    {0x401a, 0x58},
    {0x4050, 0x00},
    {0x4051, 0x01},
    {0x4028, 0x2f},
    {0x4052, 0x00},
    {0x4053, 0x80},
    {0x4054, 0x00},
    {0x4055, 0x80},
    {0x4056, 0x00},
    {0x4057, 0x80},
    {0x4058, 0x00},
    {0x4059, 0x80},
    {0x430b, 0xff},
    {0x430c, 0xff},
    {0x430d, 0x00},
    {0x430e, 0x00},
    {0x4501, 0x18},
    {0x4502, 0x00},
    {0x4643, 0x00},
    {0x4640, 0x01},
    {0x4641, 0x04},
    {0x4800, 0x64},  // mipi ctrl0
    {0x4809, 0x2b},
    {0x4813, 0x98},
    {0x4817, 0x04},
    {0x4833, 0x18},
    {0x4837, 0x0b},
    {0x483b, 0x00},
    {0x484b, 0x03},
    {0x4850, 0x7c},
    {0x4852, 0x06},
    {0x4856, 0x58},
    {0x4857, 0xaa},
    {0x4862, 0x0a},
    {0x4869, 0x18},
    {0x486a, 0xaa},
    {0x486e, 0x07},
    {0x486f, 0x55},
    {0x4875, 0xf0},
    {0x5000, 0x89},
    {0x5001, 0x42},
    {0x5004, 0x40},
    {0x5005, 0x00},
    {0x5180, 0x00},
    {0x5181, 0x10},
    {0x580b, 0x03},
    {0x4d00, 0x03},
    {0x4d01, 0xc9},
    {0x4d02, 0xbc},
    {0x4d03, 0xc6},
    {0x4d04, 0x4a},
    {0x4d05, 0x25},
    {0x4700, 0x2b},
    {0x4e00, 0x2b},
    {0x3501, 0x08},
    {0x3502, 0xe1},
    {0x3511, 0x00},
    {0x3512, 0x20},
    {0x3833, 0x01},
    {0x0100, 0x00}, //stream off
};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_hdr_10bit_30fps_1280Mbps[] = {
// OS08A_Res 3840X2160 4lane MIPI1440Mbps HDRVC10 30fps MCLK24M
    {0x0100, 0x00}, //stream off
    {0x0103, 0x01},
    {0x0303, 0x01},
    {0x0305, 0x5A},
    {0x0306, 0x00},
    {0x0308, 0x03},
    {0x0309, 0x04},
    {0x0325, 0x48},
    {0x032a, 0x00},
    {0x300f, 0x11},
    {0x3010, 0x01},
    {0x3011, 0x04},
    {0x3012, 0x41},
    {0x3016, 0xf0},
    {0x301e, 0x98},
    {0x3031, 0xa9},
    {0x3103, 0x92},
    {0x3104, 0x01},
    {0x3106, 0x10},
    {0x340c, 0xff},
    {0x340d, 0xff},
    {0x031e, 0x09},
    {0x3501, 0x08},
    {0x3502, 0xe5},
    {0x3505, 0x83},
    {0x3508, 0x00},
    {0x3509, 0x80},
    {0x350a, 0x04},
    {0x350b, 0x00},
    {0x350c, 0x00},
    {0x350d, 0x80},
    {0x350e, 0x04},
    {0x350f, 0x00},
    {0x3600, 0x00},
    {0x3603, 0x2c},
    {0x3605, 0x50},
    {0x3609, 0xb5},
    {0x3610, 0x39},
    {0x360c, 0x01},
    {0x3628, 0xa4},
    {0x362d, 0x10},
    {0x3660, 0x42},
    {0x3661, 0x07},
    {0x3662, 0x00},
    {0x3663, 0x28},
    {0x3664, 0x0d},
    {0x366a, 0x38},
    {0x366b, 0xa0},
    {0x366d, 0x00},
    {0x366e, 0x00},
    {0x3680, 0x00},
    {0x36c0, 0x00},
    {0x3701, 0x02},
    {0x373b, 0x02},
    {0x373c, 0x02},
    {0x3736, 0x02},
    {0x3737, 0x02},
    {0x3705, 0x00},
    {0x3706, 0x39},
    {0x370a, 0x00},
    {0x370b, 0x98},
    {0x3709, 0x49},
    {0x3714, 0x21},
    {0x371c, 0x00},
    {0x371d, 0x08},
    {0x3740, 0x1b},
    {0x3741, 0x04},
    {0x375e, 0x0b},
    {0x3760, 0x10},
    {0x3776, 0x10},
    {0x3781, 0x02},
    {0x3782, 0x04},
    {0x3783, 0x02},
    {0x3784, 0x08},
    {0x3785, 0x08},
    {0x3788, 0x01},
    {0x3789, 0x01},
    {0x3797, 0x04},
    {0x3762, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x6f},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x380c, 0x04},
    {0x380d, 0x0c},
    {0x380e, 0x08},
    {0x380f, 0xd0},
    {0x3813, 0x10},

    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x00},
    {0x3804, 0x0F},
    {0x3805, 0x1F},
    {0x3806, 0x08},
    {0x3807, 0x8F},
    {0x3808, 0x0F},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x3810, 0x00},
    {0x3811, 0x10},
    {0x3812, 0x00},
    {0x3813, 0x11},

    {0x3814, 0x01},
    {0x3815, 0x01},
    {0x3816, 0x01},
    {0x3817, 0x01},
    {0x381c, 0x08},
    {0x3820, 0x00},
    {0x3821, 0x24},
    {0x3823, 0x08},
    {0x3826, 0x00},
    {0x3827, 0x08},
    {0x382d, 0x08},
    {0x3832, 0x02},
    {0x3833, 0x01},
    {0x383c, 0x48},
    {0x383d, 0x60}, //ff
    {0x3d85, 0x0b},
    {0x3d84, 0x40},
    {0x3d8c, 0x63},
    {0x3d8d, 0xd7},
    {0x4000, 0xf8},
    {0x4001, 0x2b},
    {0x4004, 0x00},
    {0x4005, 0x40},
    {0x400a, 0x01},
    {0x400f, 0xa0},
    {0x4010, 0x12},
    {0x4018, 0x00},
    {0x4008, 0x02},
    {0x4009, 0x0d},
    {0x401a, 0x58},
    {0x4050, 0x00},
    {0x4051, 0x01},
    {0x4028, 0x2f},
    {0x4052, 0x00},
    {0x4053, 0x80},
    {0x4054, 0x00},
    {0x4055, 0x80},
    {0x4056, 0x00},
    {0x4057, 0x80},
    {0x4058, 0x00},
    {0x4059, 0x80},
    {0x430b, 0xff},
    {0x430c, 0xff},
    {0x430d, 0x00},
    {0x430e, 0x00},
    {0x4501, 0x18},
    {0x4502, 0x00},
    {0x4643, 0x00},
    {0x4640, 0x01},
    {0x4641, 0x04},
    {0x4800, 0x64},  // mipi ctrl0
    {0x4809, 0x2b},
    {0x4813, 0x98},
    {0x4817, 0x04},
    {0x4833, 0x18},
    {0x4837, 0x0b},
    {0x483b, 0x00},
    {0x484b, 0x03},
    {0x4850, 0x7c},
    {0x4852, 0x06},
    {0x4856, 0x58},
    {0x4857, 0xaa},
    {0x4862, 0x0a},
    {0x4869, 0x18},
    {0x486a, 0xaa},
    {0x486e, 0x07},
    {0x486f, 0x55},
    {0x4875, 0xf0},
    {0x5000, 0x89},
    {0x5001, 0x42},
    {0x5004, 0x40},
    {0x5005, 0x00},
    {0x5180, 0x00},
    {0x5181, 0x10},
    {0x580b, 0x03},
    {0x4d00, 0x03},
    {0x4d01, 0xc9},
    {0x4d02, 0xbc},
    {0x4d03, 0xc6},
    {0x4d04, 0x4a},
    {0x4d05, 0x25},
    {0x4700, 0x2b},
    {0x4e00, 0x2b},
    {0x3501, 0x08},
    {0x3502, 0xe1},
    {0x3511, 0x00},
    {0x3512, 0x20},
    {0x3833, 0x01},
    {0x0100, 0x00}, //stream off

};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_10bit_50fps_1440Mbps[] = {
    // 3840X2160 4lane MIPI1440Mbps Linear 10 50fps MCLK24M
    {0x0100, 0x00},
    {0x0103, 0x01},
    {0x0303, 0x01},
    {0x0305, 0x5a},
    {0x0306, 0x00},
    {0x0308, 0x03},
    {0x0309, 0x04},
    {0x032a, 0x00},
    {0x300f, 0x11},
    {0x3010, 0x01},
    {0x3011, 0x04},
    {0x3012, 0x41},
    {0x3016, 0xf0},
    {0x301e, 0x98},
    {0x3031, 0xa9},
    {0x3103, 0x92},
    {0x3104, 0x01},
    {0x3106, 0x10},
    {0x3400, 0x04},
    {0x3025, 0x03},
    {0x3425, 0x01},
    {0x3428, 0x01},
    {0x3406, 0x08},
    {0x3408, 0x03},
    {0x340c, 0xff},
    {0x340d, 0xff},
    {0x031e, 0x09},
    {0x3501, 0x08},
    {0x3502, 0xe5},
    {0x3505, 0x83},
    {0x3508, 0x00},
    {0x3509, 0x80},
    {0x350a, 0x04},
    {0x350b, 0x00},
    {0x350c, 0x00},
    {0x350d, 0x80},
    {0x350e, 0x04},
    {0x350f, 0x00},
    {0x3600, 0x00},
    {0x3603, 0x2c},
    {0x3605, 0x50},
    {0x3609, 0xb5},
    {0x3610, 0x39},
    {0x360c, 0x01},
    {0x3628, 0xa4},
    {0x362d, 0x10},
    {0x3660, 0x43},
    {0x3661, 0x06},
    {0x3662, 0x00},
    {0x3663, 0x28},
    {0x3664, 0x0d},
    {0x366a, 0x38},
    {0x366b, 0xa0},
    {0x366d, 0x00},
    {0x366e, 0x00},
    {0x3680, 0x00},
    {0x36c0, 0x00},
    {0x3701, 0x02},
    {0x373b, 0x02},
    {0x373c, 0x02},
    {0x3736, 0x02},
    {0x3737, 0x02},
    {0x3705, 0x00},
    {0x3706, 0x39},
    {0x370a, 0x00},
    {0x370b, 0x98},
    {0x3709, 0x49},
    {0x3714, 0x21},
    {0x371c, 0x00},
    {0x371d, 0x08},
    {0x3740, 0x1b},
    {0x3741, 0x04},
    {0x375e, 0x0b},
    {0x3760, 0x10},
    {0x3776, 0x10},
    {0x3781, 0x02},
    {0x3782, 0x04},
    {0x3783, 0x02},
    {0x3784, 0x08},
    {0x3785, 0x08},
    {0x3788, 0x01},
    {0x3789, 0x01},
    {0x3797, 0x04},
    {0x3762, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x80},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x3810, 0x00},
    {0x3811, 0x09},
    {0x3812, 0x00},
    {0x3813, 0x09},
    {0x383d, 0x6f},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x6f},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x380a, 0x08},
    {0x380b, 0x70},
    {0x380c, 0x04},
    {0x380d, 0x0c},
    {0x380e, 0x0a},
    {0x380f, 0xdb},
    {0x3813, 0x10},
    {0x3814, 0x01},
    {0x3815, 0x01},
    {0x3816, 0x01},
    {0x3817, 0x01},
    {0x381c, 0x00},
    {0x3820, 0x00},
    {0x3821, 0x04},
    {0x3823, 0x08},
    {0x3826, 0x00},
    {0x3827, 0x08},
    {0x382d, 0x08},
    {0x3832, 0x02},
    {0x3833, 0x00},
    {0x383c, 0x48},
    {0x383d, 0xff},
    {0x3d85, 0x0b},
    {0x3d84, 0x40},
    {0x3d8c, 0x63},
    {0x3d8d, 0xd7},
    {0x4000, 0xf8},
    {0x4001, 0x2b},
    {0x4004, 0x00},
    {0x4005, 0x40},
    {0x400a, 0x01},
    {0x400f, 0xa0},
    {0x4010, 0x12},
    {0x4018, 0x00},
    {0x4008, 0x02},
    {0x4009, 0x0d},
    {0x401a, 0x58},
    {0x4050, 0x00},
    {0x4051, 0x01},
    {0x4028, 0x2f},
    {0x4052, 0x00},
    {0x4053, 0x80},
    {0x4054, 0x00},
    {0x4055, 0x80},
    {0x4056, 0x00},
    {0x4057, 0x80},
    {0x4058, 0x00},
    {0x4059, 0x80},
    {0x430b, 0xff},
    {0x430c, 0xff},
    {0x430d, 0x00},
    {0x430e, 0x00},
    {0x4501, 0x18},
    {0x4502, 0x00},
    {0x4643, 0x00},
    {0x4640, 0x01},
    {0x4641, 0x04},
    {0x4800, 0x64},
    {0x4809, 0x2b},
    {0x4813, 0x90},
    {0x4817, 0x04},
    {0x4833, 0x18},
    {0x4837, 0x0b},
    {0x483b, 0x00},
    {0x484b, 0x03},
    {0x4850, 0x7c},
    {0x4852, 0x06},
    {0x4856, 0x58},
    {0x4857, 0xaa},
    {0x4862, 0x0a},
    {0x4869, 0x18},
    {0x486a, 0xaa},
    {0x486e, 0x03},
    {0x486f, 0x55},
    {0x4875, 0xf0},
    {0x5000, 0x89},
    {0x5001, 0x42},
    {0x5004, 0x40},
    {0x5005, 0x00},
    {0x5180, 0x00},
    {0x5181, 0x10},
    {0x580b, 0x03},
    {0x4d00, 0x03},
    {0x4d01, 0xc9},
    {0x4d02, 0xbc},
    {0x4d03, 0xc6},
    {0x4d04, 0x4a},
    {0x4d05, 0x25},
    {0x4700, 0x2b},
    {0x4e00, 0x2b},
    {0x3501, 0x09},
    {0x3502, 0x01},
    {0x4028, 0x4f},
    {0x4029, 0x1f},
    {0x402a, 0x7f},
    {0x402b, 0x01},
    {0x383d, 0x6f},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x0c},
    {0x3804, 0x0e},
    {0x3805, 0xff},
    {0x3806, 0x08},
    {0x3807, 0x80},
    {0x3808, 0x0f},
    {0x3809, 0x00},
    {0x3810, 0x00},
    {0x3811, 0x10},
    {0x3812, 0x00},
    {0x3813, 0x09},
    {0x0100, 0x00},
};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_10bit_60fps_1440Mbps[] = {
// 3840X2160 4lane MIPI1440Mbps Linear10 60fps MCLK24M

    {0x0100,  0x00}, // stream 0ff
    {0x0103,  0x01},
    {0x0303,  0x01},
    {0x0305,  0x5a},
    {0x0306,  0x00},
    {0x0308,  0x03},
    {0x0309,  0x04},
    {0x032a,  0x00},
    {0x300f,  0x11},
    {0x3010,  0x01},
    {0x3011,  0x04},
    {0x3012,  0x41},
    {0x3016,  0xf0},
    {0x301e,  0x98},
    {0x3031,  0xa9},
    {0x3103,  0x92},
    {0x3104,  0x01},
    {0x3106,  0x10},
    {0x3400,  0x04},
    {0x3025,  0x03},
    {0x3425,  0x01},
    {0x3428,  0x01},
    {0x3406,  0x08},
    {0x3408,  0x03},
    {0x340c,  0xff},
    {0x340d,  0xff},
    {0x031e,  0x09},
    {0x3501,  0x08},
    {0x3502,  0xe5},
    {0x3505,  0x83},
    {0x3508,  0x00},
    {0x3509,  0x80},
    {0x350a,  0x04},
    {0x350b,  0x00},
    {0x350c,  0x00},
    {0x350d,  0x80},
    {0x350e,  0x04},
    {0x350f,  0x00},
    {0x3600,  0x00},
    {0x3603,  0x2c},
    {0x3605,  0x50},
    {0x3609,  0xb5},
    {0x3610,  0x39},
    {0x360c,  0x01},
    {0x3628,  0xa4},
    {0x362d,  0x10},
    {0x3660,  0x43},
    {0x3661,  0x06},
    {0x3662,  0x00},
    {0x3663,  0x28},
    {0x3664,  0x0d},
    {0x366a,  0x38},
    {0x366b,  0xa0},
    {0x366d,  0x00},
    {0x366e,  0x00},
    {0x3680,  0x00},
    {0x36c0,  0x00},
    {0x3701,  0x02},
    {0x373b,  0x02},
    {0x373c,  0x02},
    {0x3736,  0x02},
    {0x3737,  0x02},
    {0x3705,  0x00},
    {0x3706,  0x39},
    {0x370a,  0x00},
    {0x370b,  0x98},
    {0x3709,  0x49},
    {0x3714,  0x21},
    {0x371c,  0x00},
    {0x371d,  0x08},
    {0x3740,  0x1b},
    {0x3741,  0x04},
    {0x375e,  0x0b},
    {0x3760,  0x10},
    {0x3776,  0x10},
    {0x3781,  0x02},
    {0x3782,  0x04},
    {0x3783,  0x02},
    {0x3784,  0x08},
    {0x3785,  0x08},
    {0x3788,  0x01},
    {0x3789,  0x01},
    {0x3797,  0x04},
    {0x3762,  0x11},
    {0x3800,  0x00},
    {0x3801,  0x00},
    {0x3802,  0x00},
    {0x3803,  0x0c},
    {0x3804,  0x0e},
    {0x3805,  0xff},
    {0x3806,  0x08},
    {0x3807,  0x6f},
    {0x3808,  0x0f},
    {0x3809,  0x00},
    {0x380a,  0x08},
    {0x380b,  0x70},
    {0x380c,  0x04},
    {0x380d,  0x0c},
    {0x380e,  0x09},
    {0x380f,  0x0a},
    {0x3813,  0x10},

    {0x3800,  0x00},
    {0x3801,  0x00},
    {0x3802,  0x00},
    {0x3803,  0x00},
    {0x3804,  0x0F},
    {0x3805,  0x1F},
    {0x3806,  0x08},
    {0x3807,  0x8F},
    {0x3808,  0x0F},
    {0x3809,  0x00},
    {0x380a,  0x08},
    {0x380b,  0x70},
    {0x3810,  0x00},
    {0x3811,  0x10},
    {0x3813,  0x00},
    {0x3813,  0x11},

    {0x3814,  0x01},
    {0x3815,  0x01},
    {0x3816,  0x01},
    {0x3817,  0x01},
    {0x381c,  0x00},
    {0x3820,  0x00},
    {0x3821,  0x04},
    {0x3823,  0x08},
    {0x3826,  0x00},
    {0x3827,  0x08},
    {0x382d,  0x08},
    {0x3832,  0x02},
    {0x3833,  0x00},
    {0x383c,  0x48},
    {0x383d,  0x60}, //ff
    {0x3d85,  0x0b},
    {0x3d84,  0x40},
    {0x3d8c,  0x63},
    {0x3d8d,  0xd7},
    {0x4000,  0xf8},
    {0x4001,  0x2b},
    {0x4004,  0x00},
    {0x4005,  0x40},
    {0x400a,  0x01},
    {0x400f,  0xa0},
    {0x4010,  0x12},
    {0x4018,  0x00},
    {0x4008,  0x02},
    {0x4009,  0x0d},
    {0x401a,  0x58},
    {0x4050,  0x00},
    {0x4051,  0x01},
    {0x4028,  0x2f},
    {0x4052,  0x00},
    {0x4053,  0x80},
    {0x4054,  0x00},
    {0x4055,  0x80},
    {0x4056,  0x00},
    {0x4057,  0x80},
    {0x4058,  0x00},
    {0x4059,  0x80},
    {0x430b,  0xff},
    {0x430c,  0xff},
    {0x430d,  0x00},
    {0x430e,  0x00},
    {0x4501,  0x18},
    {0x4502,  0x00},
    {0x4643,  0x00},
    {0x4640,  0x01},
    {0x4641,  0x04},
    {0x4800,  0x64},
    {0x4809,  0x2b},
    {0x4813,  0x90},
    {0x4817,  0x04},
    {0x4833,  0x18},
    {0x4837,  0x0b},
    {0x483b,  0x00},
    {0x484b,  0x03},
    {0x4850,  0x7c},
    {0x4852,  0x06},
    {0x4856,  0x58},
    {0x4857,  0xaa},
    {0x4862,  0x0a},
    {0x4869,  0x18},
    {0x486a,  0xaa},
    {0x486e,  0x03},
    {0x486f,  0x55},
    {0x4875,  0xf0},
    {0x5000,  0x89},
    {0x5001,  0x42},
    {0x5004,  0x40},
    {0x5005,  0x00},
    {0x5180,  0x00},
    {0x5181,  0x10},
    {0x580b,  0x03},
    {0x4d00,  0x03},
    {0x4d01,  0xc9},
    {0x4d02,  0xbc},
    {0x4d03,  0xc6},
    {0x4d04,  0x4a},
    {0x4d05,  0x25},

    {0x4700,  0x2b},
    {0x4e00,  0x2b},

    {0x3501,  0x09},
    {0x3502,  0x01},

    //{0x0100,  0x01},
    //{0x0100,  0x01},
    //{0x0100,  0x01},
    //{0x0100,  0x01},

    {0x0100, 0x00}, //stream off
};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_10bit_25fps_1440Mbps[] =
// 3840X2160 4lane MIPI1440Mbps Linear10 25fps MCLK24M
{
        {0x0100, 0x00},
	{0x0103, 0x01},
	{0x0303, 0x01},
	{0x0305, 0x5a},
	{0x0306, 0x00},
	{0x0308, 0x03},
	{0x0309, 0x04},
	{0x032a, 0x00},
	{0x300f, 0x11},
	{0x3010, 0x01},
	{0x3011, 0x04},
	{0x3012, 0x41},
	{0x3016, 0xf0},
	{0x301e, 0x98},
	{0x3031, 0xa9},
	{0x3103, 0x92},
	{0x3104, 0x01},
	{0x3106, 0x10},
	{0x3400, 0x04},
	{0x3025, 0x03},
	{0x3425, 0x01},
	{0x3428, 0x01},
	{0x3406, 0x08},
	{0x3408, 0x03},
	{0x340c, 0xff},
	{0x340d, 0xff},
	{0x031e, 0x09},
	{0x3501, 0x08},
	{0x3502, 0xe5},
	{0x3505, 0x83},
	{0x3508, 0x00},
	{0x3509, 0x80},
	{0x350a, 0x04},
	{0x350b, 0x00},
	{0x350c, 0x00},
	{0x350d, 0x80},
	{0x350e, 0x04},
	{0x350f, 0x00},
	{0x3600, 0x00},
	{0x3603, 0x2c},
	{0x3605, 0x50},
	{0x3609, 0xb5},
	{0x3610, 0x39},
	{0x360c, 0x01},
	{0x3628, 0xa4},
	{0x362d, 0x10},
	{0x3660, 0x43},
	{0x3661, 0x06},
	{0x3662, 0x00},
	{0x3663, 0x28},
	{0x3664, 0x0d},
	{0x366a, 0x38},
	{0x366b, 0xa0},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x3680, 0x00},
	{0x36c0, 0x00},
	{0x3701, 0x02},
	{0x373b, 0x02},
	{0x373c, 0x02},
	{0x3736, 0x02},
	{0x3737, 0x02},
	{0x3705, 0x00},
	{0x3706, 0x39},
	{0x370a, 0x00},
	{0x370b, 0x98},
	{0x3709, 0x49},
	{0x3714, 0x21},
	{0x371c, 0x00},
	{0x371d, 0x08},
	{0x3740, 0x1b},
	{0x3741, 0x04},
	{0x375e, 0x0b},
	{0x3760, 0x10},
	{0x3776, 0x10},
	{0x3781, 0x02},
	{0x3782, 0x04},
	{0x3783, 0x02},
	{0x3784, 0x08},
	{0x3785, 0x08},
	{0x3788, 0x01},
	{0x3789, 0x01},
	{0x3797, 0x04},
	{0x3762, 0x11},
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0e},
	{0x3805, 0xff},
	{0x3806, 0x08},
	{0x3807, 0x6f},
	{0x3808, 0x0f},
	{0x3809, 0x00},
	{0x380a, 0x08},
	{0x380b, 0x70},
	{0x380c, 0x04},
	{0x380d, 0x0c},
	{0x380e, 0x15},//09
	{0x380f, 0xb1},//0a
	{0x3811, 0x10},
	{0x3813, 0x11}, //10
	{0x3814, 0x01},
	{0x3815, 0x01},
	{0x3816, 0x01},
	{0x3817, 0x01},
	{0x381c, 0x00},
	{0x3820, 0x00},
	{0x3821, 0x04},
	{0x3823, 0x08},
	{0x3826, 0x00},
	{0x3827, 0x08},
	{0x382d, 0x08},
	{0x3832, 0x02},
	{0x3833, 0x00},
	{0x383c, 0x48},
	{0x383d, 0xef}, //ff
	{0x3d85, 0x0b},
	{0x3d84, 0x40},
	{0x3d8c, 0x63},
	{0x3d8d, 0xd7},
	{0x4000, 0xf8},
	{0x4001, 0x2b},
	{0x4004, 0x00},
	{0x4005, 0x40},
	{0x400a, 0x01},
	{0x400f, 0xa0},
	{0x4010, 0x12},
	{0x4018, 0x00},
	{0x4008, 0x02},
	{0x4009, 0x0d},
	{0x401a, 0x58},
	{0x4050, 0x00},
	{0x4051, 0x01},
	{0x4028, 0x2f},
	{0x4052, 0x00},
	{0x4053, 0x80},
	{0x4054, 0x00},
	{0x4055, 0x80},
	{0x4056, 0x00},
	{0x4057, 0x80},
	{0x4058, 0x00},
	{0x4059, 0x80},
	{0x430b, 0xff},
	{0x430c, 0xff},
	{0x430d, 0x00},
	{0x430e, 0x00},
	{0x4501, 0x18},
	{0x4502, 0x00},
	{0x4643, 0x00},
	{0x4640, 0x01},
	{0x4641, 0x04},
	{0x4800, 0x64},
	{0x4809, 0x2b},
	{0x4813, 0x90},
	{0x4817, 0x04},
	{0x4833, 0x18},
	{0x4837, 0x0b},
	{0x483b, 0x00},
	{0x484b, 0x03},
	{0x4850, 0x7c},
	{0x4852, 0x06},
	{0x4856, 0x58},
	{0x4857, 0xaa},
	{0x4862, 0x0a},
	{0x4869, 0x18},
	{0x486a, 0xaa},
	{0x486e, 0x03},
	{0x486f, 0x55},
	{0x4875, 0xf0},
	{0x5000, 0x89},
	{0x5001, 0x42},
	{0x5004, 0x40},
	{0x5005, 0x00},
	{0x5180, 0x00},
	{0x5181, 0x10},
	{0x580b, 0x03},
	{0x4d00, 0x03},
	{0x4d01, 0xc9},
	{0x4d02, 0xbc},
	{0x4d03, 0xc6},
	{0x4d04, 0x4a},
	{0x4d05, 0x25},
	{0x4700, 0x2b},
	{0x4e00, 0x2b},
	{0x3501, 0x09},
	{0x3502, 0x01},
	{0x4028, 0x4f},
	{0x4029, 0x1f},
	{0x402a, 0x7f},
	{0x402b, 0x01},
};

static camera_i2c_reg_array OS08A20_4lane_3840x2160_Linear_10bit_30fps_1440Mbps[] =
// 3840X2160 4lane MIPI1440Mbps Linear10 30fps MCLK24M
{
        {0x0100, 0x00},
	{0x0103, 0x01},
	{0x0303, 0x01},
	{0x0305, 0x5a},
	{0x0306, 0x00},
	{0x0308, 0x03},
	{0x0309, 0x04},
	{0x032a, 0x00},
	{0x300f, 0x11},
	{0x3010, 0x01},
	{0x3011, 0x04},
	{0x3012, 0x41},
	{0x3016, 0xf0},
	{0x301e, 0x98},
	{0x3031, 0xa9},
	{0x3103, 0x92},
	{0x3104, 0x01},
	{0x3106, 0x10},
	{0x3400, 0x04},
	{0x3025, 0x03},
	{0x3425, 0x01},
	{0x3428, 0x01},
	{0x3406, 0x08},
	{0x3408, 0x03},
	{0x340c, 0xff},
	{0x340d, 0xff},
	{0x031e, 0x09},
	{0x3501, 0x08},
	{0x3502, 0xe5},
	{0x3505, 0x83},
	{0x3508, 0x00},
	{0x3509, 0x80},
	{0x350a, 0x04},
	{0x350b, 0x00},
	{0x350c, 0x00},
	{0x350d, 0x80},
	{0x350e, 0x04},
	{0x350f, 0x00},
	{0x3600, 0x00},
	{0x3603, 0x2c},
	{0x3605, 0x50},
	{0x3609, 0xb5},
	{0x3610, 0x39},
	{0x360c, 0x01},
	{0x3628, 0xa4},
	{0x362d, 0x10},
	{0x3660, 0x43},
	{0x3661, 0x06},
	{0x3662, 0x00},
	{0x3663, 0x28},
	{0x3664, 0x0d},
	{0x366a, 0x38},
	{0x366b, 0xa0},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x3680, 0x00},
	{0x36c0, 0x00},
	{0x3701, 0x02},
	{0x373b, 0x02},
	{0x373c, 0x02},
	{0x3736, 0x02},
	{0x3737, 0x02},
	{0x3705, 0x00},
	{0x3706, 0x39},
	{0x370a, 0x00},
	{0x370b, 0x98},
	{0x3709, 0x49},
	{0x3714, 0x21},
	{0x371c, 0x00},
	{0x371d, 0x08},
	{0x3740, 0x1b},
	{0x3741, 0x04},
	{0x375e, 0x0b},
	{0x3760, 0x10},
	{0x3776, 0x10},
	{0x3781, 0x02},
	{0x3782, 0x04},
	{0x3783, 0x02},
	{0x3784, 0x08},
	{0x3785, 0x08},
	{0x3788, 0x01},
	{0x3789, 0x01},
	{0x3797, 0x04},
	{0x3762, 0x11},
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0e},
	{0x3805, 0xff},
	{0x3806, 0x08},
	{0x3807, 0x6f},
	{0x3808, 0x0f},
	{0x3809, 0x00},
	{0x380a, 0x08},
	{0x380b, 0x70},
	{0x380c, 0x04},
	{0x380d, 0x0c},
	{0x380e, 0x12},//09
	{0x380f, 0x14},//0a
	{0x3811, 0x10},
	{0x3813, 0x11}, //10
	{0x3814, 0x01},
	{0x3815, 0x01},
	{0x3816, 0x01},
	{0x3817, 0x01},
	{0x381c, 0x00},
	{0x3820, 0x00},
	{0x3821, 0x04},
	{0x3823, 0x08},
	{0x3826, 0x00},
	{0x3827, 0x08},
	{0x382d, 0x08},
	{0x3832, 0x02},
	{0x3833, 0x00},
	{0x383c, 0x48},
	{0x383d, 0xef}, //ff
	{0x3d85, 0x0b},
	{0x3d84, 0x40},
	{0x3d8c, 0x63},
	{0x3d8d, 0xd7},
	{0x4000, 0xf8},
	{0x4001, 0x2b},
	{0x4004, 0x00},
	{0x4005, 0x40},
	{0x400a, 0x01},
	{0x400f, 0xa0},
	{0x4010, 0x12},
	{0x4018, 0x00},
	{0x4008, 0x02},
	{0x4009, 0x0d},
	{0x401a, 0x58},
	{0x4050, 0x00},
	{0x4051, 0x01},
	{0x4028, 0x2f},
	{0x4052, 0x00},
	{0x4053, 0x80},
	{0x4054, 0x00},
	{0x4055, 0x80},
	{0x4056, 0x00},
	{0x4057, 0x80},
	{0x4058, 0x00},
	{0x4059, 0x80},
	{0x430b, 0xff},
	{0x430c, 0xff},
	{0x430d, 0x00},
	{0x430e, 0x00},
	{0x4501, 0x18},
	{0x4502, 0x00},
	{0x4643, 0x00},
	{0x4640, 0x01},
	{0x4641, 0x04},
	{0x4800, 0x64},
	{0x4809, 0x2b},
	{0x4813, 0x90},
	{0x4817, 0x04},
	{0x4833, 0x18},
	{0x4837, 0x0b},
	{0x483b, 0x00},
	{0x484b, 0x03},
	{0x4850, 0x7c},
	{0x4852, 0x06},
	{0x4856, 0x58},
	{0x4857, 0xaa},
	{0x4862, 0x0a},
	{0x4869, 0x18},
	{0x486a, 0xaa},
	{0x486e, 0x03},
	{0x486f, 0x55},
	{0x4875, 0xf0},
	{0x5000, 0x89},
	{0x5001, 0x42},
	{0x5004, 0x40},
	{0x5005, 0x00},
	{0x5180, 0x00},
	{0x5181, 0x10},
	{0x580b, 0x03},
	{0x4d00, 0x03},
	{0x4d01, 0xc9},
	{0x4d02, 0xbc},
	{0x4d03, 0xc6},
	{0x4d04, 0x4a},
	{0x4d05, 0x25},
	{0x4700, 0x2b},
	{0x4e00, 0x2b},
	{0x3501, 0x09},
	{0x3502, 0x01},
	{0x4028, 0x4f},
	{0x4029, 0x1f},
	{0x402a, 0x7f},
	{0x402b, 0x01},
};

static camera_i2c_reg_array OS08A20_2lane_3840x2160_Linear_10bit_30fps_1440Mbps[] =
// 3840X2160 2lane MIPI1440Mbps Linear10 30fps MCLK24M
{
        {0x0100, 0x00},
	{0x0103, 0x01},
	{0x0303, 0x01},
	{0x0305, 0x5a},
	{0x0306, 0x00},
	{0x0308, 0x03},
	{0x0309, 0x04},
	{0x032a, 0x00},
	{0x300f, 0x11},
	{0x3010, 0x01},
	{0x3011, 0x04},
	{0x3012, 0x21}, //41
	{0x3016, 0xf0},
	{0x301e, 0x98},
	{0x3031, 0xa9},
	{0x3103, 0x92},
	{0x3104, 0x01},
	{0x3106, 0x10},
	{0x3400, 0x04},
	{0x3025, 0x03},
	{0x3425, 0x01},
	{0x3428, 0x01},
	{0x3406, 0x08},
	{0x3408, 0x03},
	{0x340c, 0xff},
	{0x340d, 0xff},
	{0x031e, 0x09},
	{0x3501, 0x08},
	{0x3502, 0xe5},
	{0x3505, 0x83},
	{0x3508, 0x00},
	{0x3509, 0x80},
	{0x350a, 0x04},
	{0x350b, 0x00},
	{0x350c, 0x00},
	{0x350d, 0x80},
	{0x350e, 0x04},
	{0x350f, 0x00},
	{0x3600, 0x00},
	{0x3603, 0x2c},
	{0x3605, 0x50},
	{0x3609, 0xb5},
	{0x3610, 0x39},
	{0x360c, 0x01},
	{0x3628, 0xa4},
	{0x362d, 0x10},
	{0x3660, 0x43},
	{0x3661, 0x06},
	{0x3662, 0x00},
	{0x3663, 0x28},
	{0x3664, 0x0d},
	{0x366a, 0x38},
	{0x366b, 0xa0},
	{0x366d, 0x00},
	{0x366e, 0x00},
	{0x3680, 0x00},
	{0x36c0, 0x00},
	{0x3701, 0x02},
	{0x373b, 0x02},
	{0x373c, 0x02},
	{0x3736, 0x02},
	{0x3737, 0x02},
	{0x3705, 0x00},
	{0x3706, 0x39},
	{0x370a, 0x00},
	{0x370b, 0x98},
	{0x3709, 0x49},
	{0x3714, 0x21},
	{0x371c, 0x00},
	{0x371d, 0x08},
	{0x3740, 0x1b},
	{0x3741, 0x04},
	{0x375e, 0x0b},
	{0x3760, 0x10},
	{0x3776, 0x10},
	{0x3781, 0x02},
	{0x3782, 0x04},
	{0x3783, 0x02},
	{0x3784, 0x08},
	{0x3785, 0x08},
	{0x3788, 0x01},
	{0x3789, 0x01},
	{0x3797, 0x04},
	{0x3762, 0x11},
	{0x3800, 0x00},
	{0x3801, 0x00},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0e},
	{0x3805, 0xff},
	{0x3806, 0x08},
	{0x3807, 0x6f},
	{0x3808, 0x0f},
	{0x3809, 0x00},
	{0x380a, 0x08},
	{0x380b, 0x70},
	{0x380c, 0x08}, //04
	{0x380d, 0x18}, //0c
	{0x380e, 0x09},
	{0x380f, 0x0a},
	{0x3811, 0x10},
	{0x3813, 0x11}, //10
	{0x3814, 0x01},
	{0x3815, 0x01},
	{0x3816, 0x01},
	{0x3817, 0x01},
	{0x381c, 0x00},
	{0x3820, 0x00},
	{0x3821, 0x04},
	{0x3823, 0x08},
	{0x3826, 0x00},
	{0x3827, 0x08},
	{0x382d, 0x08},
	{0x3832, 0x02},
	{0x3833, 0x00},
	{0x383c, 0x48},
	{0x383d, 0xef}, //ff
	{0x3d85, 0x0b},
	{0x3d84, 0x40},
	{0x3d8c, 0x63},
	{0x3d8d, 0xd7},
	{0x4000, 0xf8},
	{0x4001, 0x2b},
	{0x4004, 0x00},
	{0x4005, 0x40},
	{0x400a, 0x01},
	{0x400f, 0xa0},
	{0x4010, 0x12},
	{0x4018, 0x00},
	{0x4008, 0x02},
	{0x4009, 0x0d},
	{0x401a, 0x58},
	{0x4050, 0x00},
	{0x4051, 0x01},
	{0x4028, 0x2f},
	{0x4052, 0x00},
	{0x4053, 0x80},
	{0x4054, 0x00},
	{0x4055, 0x80},
	{0x4056, 0x00},
	{0x4057, 0x80},
	{0x4058, 0x00},
	{0x4059, 0x80},
	{0x430b, 0xff},
	{0x430c, 0xff},
	{0x430d, 0x00},
	{0x430e, 0x00},
	{0x4501, 0x18},
	{0x4502, 0x00},
	{0x4643, 0x00},
	{0x4640, 0x01},
	{0x4641, 0x04},
	{0x4800, 0x64},
	{0x4809, 0x2b},
	{0x4813, 0x90},
	{0x4817, 0x04},
	{0x4833, 0x18},
	{0x4837, 0x0b},
	{0x483b, 0x00},
	{0x484b, 0x03},
	{0x4850, 0x7c},
	{0x4852, 0x06},
	{0x4856, 0x58},
	{0x4857, 0xaa},
	{0x4862, 0x0a},
	{0x4869, 0x18},
	{0x486a, 0xaa},
	{0x486e, 0x03},
	{0x486f, 0x55},
	#if 0
	{0x4870, 0x1a}, // swap
	{0x4871, 0x48}, // swap
	#endif
	{0x4875, 0xf0},
	{0x5000, 0x89},
	{0x5001, 0x42},
	{0x5004, 0x40},
	{0x5005, 0x00},
	{0x5180, 0x00},
	{0x5181, 0x10},
	{0x580b, 0x03},
	{0x4d00, 0x03},
	{0x4d01, 0xc9},
	{0x4d02, 0xbc},
	{0x4d03, 0xc6},
	{0x4d04, 0x4a},
	{0x4d05, 0x25},
	{0x4700, 0x2b},
	{0x4e00, 0x2b},
	{0x3501, 0x09},
	{0x3502, 0x01},
	{0x4028, 0x4f},
	{0x4029, 0x1f},
	{0x402a, 0x7f},
	{0x402b, 0x01},
};

#endif  //__OS08A20_SETTING_H__
