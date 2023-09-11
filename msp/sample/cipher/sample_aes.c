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
    AX_U64 *virAddr;
    AX_U64 *pyhyAddr;
    AX_U32 size;
} AX_CIPHER_CMM_T;

#define DMA_ALLOC_ALIGN      0x40
typedef struct {
    AX_CIPHER_MODE_E Mode;
    const AX_U8 *Key_p;
    const AX_U8 *Ptx_p;
    const AX_U8 *Ctx_p;
    const AX_U8 *Iv_p;
    AX_U32 KeyLen;
    AX_U32 PtxLen;
} TestVector_AES_Rec_t;
typedef const TestVector_AES_Rec_t *TestVector_AES_t;
#define TEST_VECTOR_AES(mode, key, ptx, ctx, iv) \
    {                                            \
        AX_CIPHER_MODE_CIPHER_##mode,                 \
        key, ptx, ctx, iv,                       \
        sizeof(key), sizeof(ptx)                 \
    }

static const AX_U8 F_1_1_key[] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};
static const AX_U8 F_1_1_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_1_1_ctx[] = {
    0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97,
    0xf5, 0xd3, 0xd5, 0x85, 0x03, 0xb9, 0x69, 0x9d, 0xe7, 0x85, 0x89, 0x5a, 0x96, 0xfd, 0xba, 0xaf,
    0x43, 0xb1, 0xcd, 0x7f, 0x59, 0x8e, 0xce, 0x23, 0x88, 0x1b, 0x00, 0xe3, 0xed, 0x03, 0x06, 0x88,
    0x7b, 0x0c, 0x78, 0x5e, 0x27, 0xe8, 0xad, 0x3f, 0x82, 0x23, 0x20, 0x71, 0x04, 0x72, 0x5d, 0xd4
};

static const AX_U8 F_1_3_key[] = {
    0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
    0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b
};
static const AX_U8 F_1_3_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_1_3_ctx[] = {
    0xbd, 0x33, 0x4f, 0x1d, 0x6e, 0x45, 0xf2, 0x5f, 0xf7, 0x12, 0xa2, 0x14, 0x57, 0x1f, 0xa5, 0xcc,
    0x97, 0x41, 0x04, 0x84, 0x6d, 0x0a, 0xd3, 0xad, 0x77, 0x34, 0xec, 0xb3, 0xec, 0xee, 0x4e, 0xef,
    0xef, 0x7a, 0xfd, 0x22, 0x70, 0xe2, 0xe6, 0x0a, 0xdc, 0xe0, 0xba, 0x2f, 0xac, 0xe6, 0x44, 0x4e,
    0x9a, 0x4b, 0x41, 0xba, 0x73, 0x8d, 0x6c, 0x72, 0xfb, 0x16, 0x69, 0x16, 0x03, 0xc1, 0x8e, 0x0e
};

static const AX_U8 F_1_5_key[] = {
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};
static const AX_U8 F_1_5_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_1_5_ctx[] = {
    0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8,
    0x59, 0x1c, 0xcb, 0x10, 0xd4, 0x10, 0xed, 0x26, 0xdc, 0x5b, 0xa7, 0x4a, 0x31, 0x36, 0x28, 0x70,
    0xb6, 0xed, 0x21, 0xb9, 0x9c, 0xa6, 0xf4, 0xf9, 0xf1, 0x53, 0xe7, 0xb1, 0xbe, 0xaf, 0xed, 0x1d,
    0x23, 0x30, 0x4b, 0x7a, 0x39, 0xf9, 0xf3, 0xff, 0x06, 0x7d, 0x8d, 0x8f, 0x9e, 0x24, 0xec, 0xc7
};

static const AX_U8 F_2_1_key[] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};
static const AX_U8 F_2_1_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_2_1_ctx[] = {
    0x76, 0x49, 0xab, 0xac, 0x81, 0x19, 0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b, 0x12, 0xe9, 0x19, 0x7d,
    0x50, 0x86, 0xcb, 0x9b, 0x50, 0x72, 0x19, 0xee, 0x95, 0xdb, 0x11, 0x3a, 0x91, 0x76, 0x78, 0xb2,
    0x73, 0xbe, 0xd6, 0xb8, 0xe3, 0xc1, 0x74, 0x3b, 0x71, 0x16, 0xe6, 0x9e, 0x22, 0x22, 0x95, 0x16,
    0x3f, 0xf1, 0xca, 0xa1, 0x68, 0x1f, 0xac, 0x09, 0x12, 0x0e, 0xca, 0x30, 0x75, 0x86, 0xe1, 0xa7
};
static const AX_U8 F_2_1_iv[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static const AX_U8 F_2_3_key[] = {
    0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
    0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b
};
static const AX_U8 F_2_3_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_2_3_ctx[] = {
    0x4f, 0x02, 0x1d, 0xb2, 0x43, 0xbc, 0x63, 0x3d, 0x71, 0x78, 0x18, 0x3a, 0x9f, 0xa0, 0x71, 0xe8,
    0xb4, 0xd9, 0xad, 0xa9, 0xad, 0x7d, 0xed, 0xf4, 0xe5, 0xe7, 0x38, 0x76, 0x3f, 0x69, 0x14, 0x5a,
    0x57, 0x1b, 0x24, 0x20, 0x12, 0xfb, 0x7a, 0xe0, 0x7f, 0xa9, 0xba, 0xac, 0x3d, 0xf1, 0x02, 0xe0,
    0x08, 0xb0, 0xe2, 0x79, 0x88, 0x59, 0x88, 0x81, 0xd9, 0x20, 0xa9, 0xe6, 0x4f, 0x56, 0x15, 0xcd
};
static const AX_U8 F_2_3_iv[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static const AX_U8 F_2_5_key[] = {
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};
static const AX_U8 F_2_5_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_2_5_ctx[] = {
    0xf5, 0x8c, 0x4c, 0x04, 0xd6, 0xe5, 0xf1, 0xba, 0x77, 0x9e, 0xab, 0xfb, 0x5f, 0x7b, 0xfb, 0xd6,
    0x9c, 0xfc, 0x4e, 0x96, 0x7e, 0xdb, 0x80, 0x8d, 0x67, 0x9f, 0x77, 0x7b, 0xc6, 0x70, 0x2c, 0x7d,
    0x39, 0xf2, 0x33, 0x69, 0xa9, 0xd9, 0xba, 0xcf, 0xa5, 0x30, 0xe2, 0x63, 0x04, 0x23, 0x14, 0x61,
    0xb2, 0xeb, 0x05, 0xe2, 0xc3, 0x9b, 0xe9, 0xfc, 0xda, 0x6c, 0x19, 0x07, 0x8c, 0x6a, 0x9d, 0x1b
};
static const AX_U8 F_2_5_iv[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static const AX_U8 F_5_1_key[] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};
static const AX_U8 F_5_1_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_5_1_ctx[] = {
    0x87, 0x4d, 0x61, 0x91, 0xb6, 0x20, 0xe3, 0x26, 0x1b, 0xef, 0x68, 0x64, 0x99, 0x0d, 0xb6, 0xce,
    0x98, 0x06, 0xf6, 0x6b, 0x79, 0x70, 0xfd, 0xff, 0x86, 0x17, 0x18, 0x7b, 0xb9, 0xff, 0xfd, 0xff,
    0x5a, 0xe4, 0xdf, 0x3e, 0xdb, 0xd5, 0xd3, 0x5e, 0x5b, 0x4f, 0x09, 0x02, 0x0d, 0xb0, 0x3e, 0xab,
    0x1e, 0x03, 0x1d, 0xda, 0x2f, 0xbe, 0x03, 0xd1, 0x79, 0x21, 0x70, 0xa0, 0xf3, 0x00, 0x9c, 0xee
};
static const AX_U8 F_5_1_iv[] = {
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

static const AX_U8 F_5_3_key[] = {
    0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,
    0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b
};
static const AX_U8 F_5_3_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_5_3_ctx[] = {
    0x1a, 0xbc, 0x93, 0x24, 0x17, 0x52, 0x1c, 0xa2, 0x4f, 0x2b, 0x04, 0x59, 0xfe, 0x7e, 0x6e, 0x0b,
    0x09, 0x03, 0x39, 0xec, 0x0a, 0xa6, 0xfa, 0xef, 0xd5, 0xcc, 0xc2, 0xc6, 0xf4, 0xce, 0x8e, 0x94,
    0x1e, 0x36, 0xb2, 0x6b, 0xd1, 0xeb, 0xc6, 0x70, 0xd1, 0xbd, 0x1d, 0x66, 0x56, 0x20, 0xab, 0xf7,
    0x4f, 0x78, 0xa7, 0xf6, 0xd2, 0x98, 0x09, 0x58, 0x5a, 0x97, 0xda, 0xec, 0x58, 0xc6, 0xb0, 0x50
};
static const AX_U8 F_5_3_iv[] = {
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

static const AX_U8 F_5_5_key[] = {
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};
static const AX_U8 F_5_5_ptx[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_5_5_ctx[] = {
    0x60, 0x1e, 0xc3, 0x13, 0x77, 0x57, 0x89, 0xa5, 0xb7, 0xa7, 0xf5, 0x04, 0xbb, 0xf3, 0xd2, 0x28,
    0xf4, 0x43, 0xe3, 0xca, 0x4d, 0x62, 0xb5, 0x9a, 0xca, 0x84, 0xe9, 0x90, 0xca, 0xca, 0xf5, 0xc5,
    0x2b, 0x09, 0x30, 0xda, 0xa2, 0x3d, 0xe9, 0x4c, 0xe8, 0x70, 0x17, 0xba, 0x2d, 0x84, 0x98, 0x8d,
    0xdf, 0xc9, 0xc5, 0x8d, 0xb6, 0x7a, 0xad, 0xa6, 0x13, 0xc2, 0xdd, 0x08, 0x45, 0x79, 0x41, 0xa6
};
static const AX_U8 F_5_5_iv[] = {
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

/* ICM */
static const AX_U8 F_4_1_key[] = {
    0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C,
};
static const AX_U8 F_4_1_iv[] = {
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0x00, 0x00,
};
static const AX_U8 F_4_1_ptx[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static const AX_U8 F_4_1_ctx[] = {
    0xE0, 0x3E, 0xAD, 0x09, 0x35, 0xC9, 0x5E, 0x80, 0xE1, 0x66, 0xB1, 0x6D, 0xD9, 0x2B, 0x4E, 0xB4,
    0xD2, 0x35, 0x13, 0x16, 0x2B, 0x02, 0xD0, 0xF7, 0x2A, 0x43, 0xA2, 0xFE, 0x4A, 0x5F, 0x97, 0xAB,
    0x41, 0xE9, 0x5B, 0x3B, 0xB0, 0xA2, 0xE8, 0xDD, 0x47, 0x79, 0x01, 0xE4, 0xFC, 0xA8, 0x94, 0xC0,
};

static const AX_U8 F_4_2_key[] = {
    0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C,
};
static const AX_U8 F_4_2_iv[] = {
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
};
static const AX_U8 F_4_2_ptx[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static const AX_U8 F_4_2_ctx[] = {
    0xEC, 0x8C, 0xDF, 0x73, 0x98, 0x60, 0x7C, 0xB0, 0xF2, 0xD2, 0x16, 0x75, 0xEA, 0x9E, 0xA1, 0xE4,
    0x36, 0x2B, 0x7C, 0x3C, 0x67, 0x73, 0x51, 0x63, 0x18, 0xA0, 0x77, 0xD7, 0xFC, 0x50, 0x73, 0xAE,
    0x6A, 0x2C, 0xC3, 0x78, 0x78, 0x89, 0x37, 0x4F, 0xBE, 0xB4, 0xC8, 0x1B, 0x17, 0xBA, 0x6C, 0x44,
};

static const TestVector_AES_Rec_t aesVectors [] = {
    TEST_VECTOR_AES(ECB, F_1_1_key, F_1_1_ptx, F_1_1_ctx, NULL),
    TEST_VECTOR_AES(ECB, F_1_3_key, F_1_3_ptx, F_1_3_ctx, NULL),
    TEST_VECTOR_AES(ECB, F_1_5_key, F_1_5_ptx, F_1_5_ctx, NULL),
    TEST_VECTOR_AES(CBC, F_2_1_key, F_2_1_ptx, F_2_1_ctx, F_2_1_iv),
    TEST_VECTOR_AES(CBC, F_2_3_key, F_2_3_ptx, F_2_3_ctx, F_2_3_iv),
    TEST_VECTOR_AES(CBC, F_2_5_key, F_2_5_ptx, F_2_5_ctx, F_2_5_iv),
    TEST_VECTOR_AES(CTR, F_5_1_key, F_5_1_ptx, F_5_1_ctx, F_5_1_iv),
    TEST_VECTOR_AES(CTR, F_5_3_key, F_5_3_ptx, F_5_3_ctx, F_5_3_iv),
    TEST_VECTOR_AES(CTR, F_5_5_key, F_5_5_ptx, F_5_5_ctx, F_5_5_iv),
    TEST_VECTOR_AES(ICM, F_4_1_key, F_4_1_ptx, F_4_1_ctx, F_4_1_iv),
    TEST_VECTOR_AES(ICM, F_4_2_key, F_4_2_ptx, F_4_2_ctx, F_4_2_iv)
};

// *** Start add for performance test case ***
#define    INPUT_DATA_LEN   16
static const AX_U8 F_ptx_test[] = {
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
    0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
    0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
    0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
};
static const AX_U8 F_ctx_test[] = {
    0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97,
    0xf5, 0xd3, 0xd5, 0x85, 0x03, 0xb9, 0x69, 0x9d, 0xe7, 0x85, 0x89, 0x5a, 0x96, 0xfd, 0xba, 0xaf,
    0x43, 0xb1, 0xcd, 0x7f, 0x59, 0x8e, 0xce, 0x23, 0x88, 0x1b, 0x00, 0xe3, 0xed, 0x03, 0x06, 0x88,
    0x7b, 0x0c, 0x78, 0x5e, 0x27, 0xe8, 0xad, 0x3f, 0x82, 0x23, 0x20, 0x71, 0x04, 0x72, 0x5d, 0xd4
};
static const TestVector_AES_Rec_t aesVectorsPerformanceTest [] = {
    TEST_VECTOR_AES(ECB, F_1_1_key, F_ptx_test, F_ctx_test, NULL),
    TEST_VECTOR_AES(ECB, F_1_3_key, F_ptx_test, F_ctx_test, NULL),
    TEST_VECTOR_AES(ECB, F_1_5_key, F_ptx_test, F_ctx_test, NULL),
    TEST_VECTOR_AES(CBC, F_2_1_key, F_ptx_test, F_ctx_test, F_2_1_iv),
    TEST_VECTOR_AES(CBC, F_2_3_key, F_ptx_test, F_ctx_test, F_2_3_iv),
    TEST_VECTOR_AES(CBC, F_2_5_key, F_ptx_test, F_ctx_test, F_2_5_iv),
    TEST_VECTOR_AES(CTR, F_5_1_key, F_ptx_test, F_ctx_test, F_5_1_iv),
    TEST_VECTOR_AES(CTR, F_5_3_key, F_ptx_test, F_ctx_test, F_5_3_iv),
    TEST_VECTOR_AES(CTR, F_5_5_key, F_ptx_test, F_ctx_test, F_5_5_iv),
    TEST_VECTOR_AES(ICM, F_4_1_key, F_ptx_test, F_ctx_test, F_4_1_iv),
    TEST_VECTOR_AES(ICM, F_4_2_key, F_ptx_test, F_ctx_test, F_4_2_iv)
};

// *** Start add for performance test case ***

int SAMPLE_AES_VectorNum(void)
{
    return sizeof(aesVectors) / sizeof(aesVectors[0]);
}

TestVector_AES_t SAMPLE_AES_VectorGet(int Index)
{
    if (Index >= SAMPLE_AES_VectorNum())
        return NULL;

    return &aesVectors[Index];
}

int SAMPLE_CIPHER_AES_Encrypt()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_AES_t tv_p;
    unsigned char resultText[512];
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_AES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(resultText, 0, sizeof(resultText));
            if (AX_CIPHER_Encrypt(handler, (AX_U8 *)tv_p->Ptx_p, resultText, tv_p->PtxLen) == AX_SUCCESS) {
                if (memcmp(resultText, tv_p->Ctx_p, tv_p->PtxLen) != 0) {
                    printf("encrypt compare error, %d\n", Index);
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
        printf("AES_Encrypt wrong tests %d\n", Failed);
    } else {
        printf("AES_Encrypt PASS\n");
    }
    return 0;
}
int SAMPLE_CIPHER_AES_Decrypt()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    TestVector_AES_t tv_p;
    unsigned char resultText[512];
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_AES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
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
        printf("AES_Decrypt wrong tests %d\n", Failed);
    } else {
        printf("AES_Decrypt PASS\n");
    }
    return 0;
}

int SAMPLE_CIPHER_AES_EncryptPhy()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    TestVector_AES_t tv_p;
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_AES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;

        ret1 = AX_SYS_MemAlloc(&phySrc, (AX_VOID **)&src, tv_p->PtxLen, 64, (AX_S8 *)"ce_aes_sample");
        if (ret1 < 0) {
            printf("PhySrc Alloc memory failed!\n");
            return AX_ERR_CIPHER_NOMEM;
        }
        ret1 = AX_SYS_MemAlloc(&phyDst, (AX_VOID **)&dst, tv_p->PtxLen, 64, (AX_S8 *)"ce_aes_sample");
        if (ret1 < 0) {
            printf("PhyDst Alloc memory failed!\n");
            return AX_ERR_CIPHER_NOMEM;
        }
        memcpy((AX_U8 *)src, tv_p->Ptx_p, tv_p->PtxLen);

        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(dst, 0, 512);
            if (AX_CIPHER_EncryptPhy(handler, phySrc, phyDst, tv_p->PtxLen) == AX_SUCCESS) {
                if (memcmp((AX_U8 *)dst, tv_p->Ctx_p, tv_p->PtxLen) != 0) {
                    printf("phy addr encrypt compare error, %d\n", Index);
                }
                Success++;
            } else {
                printf("phy addr encrypt error %d\n", Index);
                Failed++;
            }
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Phy addr Process vector %d\n", Index);
            Failed++;
        }

        AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
        AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);
    }
    if (Failed) {
        printf("Phy addr AES_Encrypt_Phy wrong tests %d\n", Failed);
    } else {
        printf("Phy addr AES_Encrypt_Phy PASS \n");
    }
    return 0;
}

int SAMPLE_CIPHER_AES_DecryptPhy()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    AX_CIPHER_STS ret;
    TestVector_AES_t tv_p;
    for (Index = 0; ; Index++) {
        tv_p = SAMPLE_AES_VectorGet(Index);
        if (tv_p == NULL) {
            break;
        }
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;

        ret1 = AX_SYS_MemAlloc(&phySrc, (AX_VOID **)&src, tv_p->PtxLen, 64, (AX_S8 *)"ce_sample");
        if (ret1 < 0) {
            printf("PhySrc Alloc memory failed!\n");
            return AX_ERR_CIPHER_NOMEM;
        }
        ret1 = AX_SYS_MemAlloc(&phyDst, (AX_VOID **)&dst, tv_p->PtxLen, 64, (AX_S8 *)"ce_sample123");
        if (ret1 < 0) {
            AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
            printf("PhyDst Alloc memory failed!\n");
            return AX_ERR_CIPHER_NOMEM;
        }
        memcpy((AX_U8 *)src, tv_p->Ctx_p, tv_p->PtxLen);
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(dst, 0, 512);
            if (AX_CIPHER_DecryptPhy(handler, phySrc, phyDst, tv_p->PtxLen) == AX_SUCCESS) {
                if (memcmp((AX_U8 *)dst, tv_p->Ptx_p, tv_p->PtxLen) != 0) {
                    printf("phy addr decrypt compare error, %d\n", Index);
                }
                Success++;
            } else {
                printf("Phy addr decrypt error %d\n", Index);
                Failed++;
            }
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Phy addr Process vector %d\n", Index);
            Failed++;
        }
        AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
        AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);
    }
    if (Failed) {
        printf("Phy addr AES_Decrypt_Phy wrong tests %d\n", Failed);
    } else {
        printf("Phy addr AES_Decrypt_Phy PASS\n");
    }
    return 0;
}

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
        strcpy(g_Mode_Array, "CBC");
        break;
    case 5:
        strcpy(g_Mode_Array, "CBC");
        break;
    case 6:
        strcpy(g_Mode_Array, "CTR");
        break;
    case 7:
        strcpy(g_Mode_Array, "CTR");
        break;
    case 8:
        strcpy(g_Mode_Array, "CTR");
        break;
    case 9:
        strcpy(g_Mode_Array, "ICM");
        break;
    case 10:
        strcpy(g_Mode_Array, "ICM");
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
        strcpy(g_KeyBitsMode, "F_1_1_key 128 bits ");
        break;
    case 1:
        strcpy(g_KeyBitsMode, "F_1_3_key 192 bits ");
        break;
    case 2:
        strcpy(g_KeyBitsMode, "F_1_5_key 256 bits ");
        break;
    case 3:
        strcpy(g_KeyBitsMode, "F_2_1_key 128 bits ");
        break;
    case 4:
        strcpy(g_KeyBitsMode, "F_2_3_key 192 bits ");
        break;
    case 5:
        strcpy(g_KeyBitsMode, "F_2_5_key 256 bits ");
        break;
    case 6:
        strcpy(g_KeyBitsMode, "F_5_1_key 128 bits ");
        break;
    case 7:
        strcpy(g_KeyBitsMode, "F_5_3_key 192 bits ");
        break;
    case 8:
        strcpy(g_KeyBitsMode, "F_5_5_key 256 bits ");
        break;
    case 9:
        strcpy(g_KeyBitsMode, "F_4_1_key 128 bits ");
        break;
    case 10:
        strcpy(g_KeyBitsMode, "F_4_2_key 128 bits ");
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
static int SAMPLE_CIPHER_AES_EncryptPhy_PerformanceTest()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_CIPHER_STS ret;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    TestVector_AES_t tv_p;
    ret1 = AX_SYS_MemAlloc(&phySrc, (AX_VOID **)&src, 1024 * 1024 * INPUT_DATA_LEN, 64, (AX_S8 *)"ce_aes_sample");
    if (ret1 < 0) {
        printf("PhySrc Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }
    ret1 = AX_SYS_MemAlloc(&phyDst, (AX_VOID **)&dst, 512, 64, (AX_S8 *)"ce_aes_sample");
    if (ret1 < 0) {
        AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
        printf("PhyDst Alloc memory failed!\n");
        return AX_ERR_CIPHER_NOMEM;
    }

    for (Index = 0; Index < sizeof(aesVectorsPerformanceTest) / sizeof(aesVectorsPerformanceTest[0]); Index++) {
        tv_p = &aesVectorsPerformanceTest[Index];
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;
        memcpy((AX_U8 *)src, tv_p->Ptx_p, tv_p->PtxLen);
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(dst, 0, 512);
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
            printf("AES Encrypt %s Mode, key bits %s Mode: perf encryt:%lfMB/s \n",
                   SAMPLE_CIPHER_AES_Get_Mode(Index), SAMPLE_CIPHER_AES_Get_KeyBitsMode(Index), mPerSecond);
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Phy addr Process vector %d\n", Index);
            Failed++;
        }
    }
    AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
    AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);
    if (Failed) {
        printf("AES_Encrypt_Phy wrong tests %d\n", Failed);
    } else {
        printf("AES_Encrypt_Phy PASS \n\n");
    }
    return 0;
}
static int SAMPLE_CIPHER_AES_DecryptPhy_PerformanceTest()
{
    AX_CIPHER_CTRL_T ctrl;
    int Index;
    int Success = 0;
    int Failed = 0;
    int ret1 = 0;
    AX_CIPHER_HANDLE handler;
    AX_U64 phySrc, phyDst;
    AX_VOID *src, *dst;
    AX_CIPHER_STS ret;
    TestVector_AES_t tv_p;
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
    for (Index = 0; Index < sizeof(aesVectorsPerformanceTest) / sizeof(aesVectorsPerformanceTest[0]); Index++) {
        tv_p = &aesVectorsPerformanceTest[Index];
        ctrl.alg = AX_CIPHER_ALGO_CIPHER_AES;
        ctrl.workMode = tv_p->Mode;
        ctrl.pKey = (AX_U8 *)tv_p->Key_p;
        ctrl.keySize = tv_p->KeyLen;
        ctrl.pIV = (AX_U8 *)tv_p->Iv_p;

        memcpy((AX_U8 *)src, tv_p->Ctx_p, tv_p->PtxLen);
        ret = AX_CIPHER_CreateHandle(&handler, &ctrl);
        if (ret == AX_SUCCESS) {
            memset(dst, 0, 512);
            t1 = get_time_us();
            for (int k = 0; k < 10; k++) {
                if (AX_CIPHER_DecryptPhy(handler, phySrc, phyDst, 1024 * 1024 * INPUT_DATA_LEN) == AX_SUCCESS) {
                    Success++;
                } else {
                    printf("phy addr decrypt error index = %d, k = %d .\n", Index, k);
                    Failed++;
                }
            }
            t2 = get_time_us();
            averageCost = (AX_F32)(t2 - t1) / 10 / 1000000;
            mPerSecond = (AX_F32)INPUT_DATA_LEN / averageCost;
            printf("AES Decrypt %s Mode, key bits %s Mode: perf decrypt:%lfMB/s \n",
                   SAMPLE_CIPHER_AES_Get_Mode(Index), SAMPLE_CIPHER_AES_Get_KeyBitsMode(Index), mPerSecond);
            AX_CIPHER_DestroyHandle(handler);
        } else {
            printf("Phy addr Process vector %d\n", Index);
            Failed++;
        }
    }
    AX_SYS_MemFree((AX_U64)phySrc, (AX_VOID *)src);
    AX_SYS_MemFree((AX_U64)phyDst, (AX_VOID *)dst);
    if (Failed) {
        printf("AES_Decrypt_Phy wrong tests %d\n", Failed);
    } else {
        printf("AES_Decrypt_Phy PASS\n\n");
    }
    return 0;
}
int SAMPLE_CIPHER_AES_PerformanceTest()
{
    SAMPLE_CIPHER_AES_EncryptPhy_PerformanceTest();
    SAMPLE_CIPHER_AES_DecryptPhy_PerformanceTest();
    return 0;
}
