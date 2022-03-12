/*
 * linux/drivers/video/fbdev/exynos/panel/td4150_boe/td4150_boe_a12s_panel.h
 *
 * Header file for TD4150 Dimming Driver
 *
 * Copyright (c) 2016 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __TD4150_A12S_PANEL_H__
#define __TD4150_A12S_PANEL_H__
#include "../panel_drv.h"
#include "td4150_boe.h"

#include "td4150_boe_a12s_panel_dimming.h"
#include "td4150_boe_a12s_panel_i2c.h"

#include "td4150_boe_a12s_resol.h"

#undef __pn_name__
#define __pn_name__	a12s

#undef __PN_NAME__
#define __PN_NAME__	A12S

static struct seqinfo a12s_seqtbl[MAX_PANEL_SEQ];


/* ===================================================================================== */
/* ============================= [TD4150 READ INFO TABLE] ============================= */
/* ===================================================================================== */
/* <READINFO TABLE> IS DEPENDENT ON LDI. IF YOU NEED, DEFINE PANEL's RESOURCE TABLE */


/* ===================================================================================== */
/* ============================= [TD4150 RESOURCE TABLE] ============================== */
/* ===================================================================================== */
/* <RESOURCE TABLE> IS DEPENDENT ON LDI. IF YOU NEED, DEFINE PANEL's RESOURCE TABLE */


/* ===================================================================================== */
/* ============================== [TD4150 MAPPING TABLE] ============================== */
/* ===================================================================================== */

static u8 a12s_brt_table[TD4150_TOTAL_NR_LUMINANCE][1] = {
	{0},
	{1}, {1}, {2}, {3}, {3}, {4}, {5}, {5}, {6}, {7}, /* 1: 1 */
	{7}, {8}, {9}, {9}, {10}, {11}, {11}, {12}, {13}, {14},
	{14}, {15}, {16}, {16}, {17}, {18}, {18}, {19}, {20}, {20},
	{21}, {22}, {22}, {23}, {24}, {24}, {25}, {26}, {27}, {27},
	{28}, {29}, {29}, {30}, {31}, {31}, {32}, {33}, {33}, {34},
	{35}, {35}, {36}, {37}, {37}, {38}, {39}, {40}, {40}, {41},
	{42}, {42}, {43}, {44}, {44}, {45}, {46}, {46}, {47}, {48},
	{48}, {49}, {50}, {51}, {51}, {52}, {53}, {53}, {54}, {55},
	{55}, {56}, {57}, {57}, {58}, {59}, {59}, {60}, {61}, {61},
	{62}, {63}, {64}, {64}, {65}, {66}, {66}, {67}, {68}, {68},
	{69}, {70}, {70}, {71}, {72}, {72}, {73}, {74}, {74}, {75},
	{76}, {77}, {77}, {78}, {79}, {79}, {80}, {81}, {81}, {82},
	{83}, {83}, {84}, {85}, {85}, {86}, {87}, {88}, {88}, {89}, /* 128: 88 */
	{90}, {91}, {92}, {93}, {94}, {95}, {96}, {97}, {98}, {99},
	{100}, {101}, {102}, {103}, {104}, {105}, {106}, {107}, {108}, {109},
	{110}, {111}, {112}, {113}, {114}, {115}, {116}, {117}, {118}, {118},
	{119}, {120}, {121}, {122}, {123}, {124}, {125}, {126}, {127}, {128},
	{129}, {130}, {131}, {132}, {133}, {134}, {135}, {136}, {137}, {138},
	{139}, {140}, {141}, {142}, {143}, {144}, {145}, {146}, {147}, {148},
	{149}, {149}, {150}, {151}, {152}, {153}, {154}, {155}, {156}, {157},
	{158}, {159}, {160}, {161}, {162}, {163}, {164}, {165}, {166}, {167},
	{168}, {169}, {170}, {171}, {172}, {173}, {174}, {175}, {176}, {177},
	{178}, {179}, {180}, {180}, {181}, {182}, {183}, {184}, {185}, {186},
	{187}, {188}, {189}, {190}, {191}, {192}, {193}, {194}, {195}, {196},
	{197}, {198}, {199}, {200}, {201}, {202}, {203}, {204}, {205}, {206},
	{207}, {208}, {209}, {210}, {211}, {211}, {211}, {211}, {211}, {211}, /* 255: 211 */
	{211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211},
	{211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211},
	{211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211},
	{211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211}, {211},
	{211}, {211}, {211}, {211}, {211}, {254},
};


static struct maptbl a12s_maptbl[MAX_MAPTBL] = {
	[BRT_MAPTBL] = DEFINE_2D_MAPTBL(a12s_brt_table, init_brightness_table, getidx_brt_table, copy_common_maptbl),
};

/* ===================================================================================== */
/* ============================== [TD4150 COMMAND TABLE] ============================== */
/* ===================================================================================== */
static u8 A12S_SLEEP_OUT[] = { 0x11 };
static u8 A12S_SLEEP_IN[] = { 0x10 };
static u8 A12S_DISPLAY_OFF[] = { 0x28 };
static u8 A12S_DISPLAY_ON[] = { 0x29 };

static u8 A12S_BRIGHTNESS[] = {
	0x51,
	0x0F, 0xFF
};

static u8 A12S_BRIGHTNESS_MODE[] = {
	0x53,
	0x0C,
};

static u8 A12S_BRIGHTNESS_CABC_MODE[] = {
	0x55,
	0x03,
};

static u8 A12S_BRIGHTNESS_CABC_MIN[] = {
	0x5E,
	0x30,
};

static u8 A12S_TD4150_BOE_001[] = {
	0xB0,
	0x04,
};

static u8 A12S_TD4150_BOE_002[] = {
	0xB6,
	0x20, 0x6A, 0x00, 0x06, 0xC3, 0x03,
};

static u8 A12S_TD4150_BOE_003[] = {
	0xB7,
	0x31, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_004[] = {
	0xB8,
	0x00, 0x78, 0x64, 0x10, 0x64, 0xB4,
};

static u8 A12S_TD4150_BOE_005[] = {
	0xB9,
	0x00, 0x78, 0x64, 0x10, 0x64, 0xB4,
};

static u8 A12S_TD4150_BOE_006[] = {
	0xBA,
	0x07, 0x7C, 0x40, 0x10, 0x1A, 0x33,
};

static u8 A12S_TD4150_BOE_007[] = {
	0xBB,
	0x00, 0xB4, 0xA0,
};

static u8 A12S_TD4150_BOE_008[] = {
	0xBC,
	0x00, 0xB4, 0xA0,
};

static u8 A12S_TD4150_BOE_009[] = {
	0xBD,
	0x00, 0xB4, 0xA0,
};

static u8 A12S_TD4150_BOE_010[] = {
	0xBE,
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_011[] = {
	0xC0,
	0x00, 0x7F, 0x16, 0x06, 0x40, 0x00, 0x0B, 0x06, 0xB3, 0x00,
	0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_012[] = {
	0xC1,
	0x30, 0x11, 0x50, 0xFA, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00,
};

static u8 A12S_TD4150_BOE_013[] = {
	0xC2,
	0x00, 0x20, 0x04, 0x14, 0x05, 0x00, 0x0C, 0x12, 0x00, 0x04,
	0x20, 0x0E, 0x22, 0x06, 0x00, 0x0C, 0x11, 0x00, 0x07, 0x20,
	0x7C, 0x01, 0x05, 0x00, 0x07, 0x00, 0x00, 0x07, 0xC0, 0x06,
	0x01, 0x06, 0x06, 0x59, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x30, 0x08, 0x08, 0x04, 0x05, 0x05,
	0x00, 0xF6, 0x56, 0x03, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x11, 0x00, 0xF6, 0x56, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x71, 0x08, 0x08, 0x04,
	0x05, 0x05, 0x00, 0xF6, 0x56, 0x03, 0x00, 0x10, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x11, 0x00, 0xF6, 0x56, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
	0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_014[] = {
	0xC3,
	0x00, 0xC0, 0x6D, 0x01, 0x65, 0xE0, 0x07, 0x00, 0x00, 0x00,
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x23, 0x00, 0x07, 0x10, 0x3B, 0x01, 0x65, 0x10,
	0x0A, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_015[] = {
	0xC4,
	0x00, 0x00, 0x0B, 0x00, 0x03, 0x05, 0x61, 0x61, 0x1A, 0x19,
	0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x61, 0x61,
	0x06, 0x04, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x7F, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00,
	0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F,
	0x3F, 0x3F, 0x3F, 0x55, 0x55, 0x55, 0xD5, 0xFF, 0xFF, 0xFF,
	0x57, 0x55, 0x55, 0x55,
};

static u8 A12S_TD4150_BOE_016[] = {
	0xC5,
	0x08, 0x00, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_017[] = {
	0xC6,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x04, 0x00,
	0x40, 0x3C, 0x00, 0x00, 0x04, 0x00, 0x40, 0x3C, 0x0F, 0x05,
	0x01, 0x19, 0x01, 0x35, 0xFF, 0x8F, 0x06, 0x05, 0x01, 0xC0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0xC0, 0x11,
	0x1F, 0x00, 0x00, 0x10, 0x10, 0x00, 0x01, 0xF0, 0x01, 0x00,
	0x50, 0x00, 0x33, 0x03,
};

static u8 A12S_TD4150_BOE_018[] = {
	0xC7,
	0x00, 0x00, 0x00, 0x50, 0x00, 0x6A, 0x00, 0x7C, 0x00, 0x92,
	0x00, 0xA1, 0x00, 0xB7, 0x00, 0xC3, 0x00, 0xE5, 0x00, 0xBA,
	0x01, 0x1E, 0x00, 0xEC, 0x01, 0x35, 0x00, 0xF9, 0x01, 0x74,
	0x01, 0x8F, 0x02, 0x1F, 0x02, 0x95, 0x02, 0xA0, 0x00, 0x00,
	0x00, 0x50, 0x00, 0x6A, 0x00, 0x7C, 0x00, 0x92, 0x00, 0xA1,
	0x00, 0xB7, 0x00, 0xC3, 0x00, 0xE5, 0x00, 0xBA, 0x01, 0x1E,
	0x00, 0xEC, 0x01, 0x35, 0x00, 0xF9, 0x01, 0x74, 0x01, 0x8F,
	0x02, 0x1F, 0x02, 0x95, 0x02, 0xA0,
};

static u8 A12S_TD4150_BOE_019[] = {
	0xC8,
	0x40, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC,
};

static u8 A12S_TD4150_BOE_020[] = {
	0xC9,
	0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x24, 0x8B,
	0x4D, 0x8B, 0x4D, 0x8B, 0x4D,
};

static u8 A12S_TD4150_BOE_021[] = {
	0xCA,
	0x1C, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_022[] = {
	0xCB,
	0x12, 0xD0, 0x09, 0xC1, 0xB9, 0x65, 0x30, 0xA8, 0x74, 0x21,
	0xB8, 0x75, 0x21, 0xA9, 0x64, 0x30, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x70, 0x00, 0x24, 0x00, 0x00, 0x00, 0xFF,
};

static u8 A12S_TD4150_BOE_023[] = {
	0xCE,
	0x7D, 0x40, 0x48, 0x56, 0x67, 0x78, 0x88, 0x98, 0xA7, 0xB5,
	0xC3, 0xD1, 0xDE, 0xE9, 0xF2, 0xFA, 0xFF, 0x0C, 0x12, 0x00,
	0x00, 0x45, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_024[] = {
	0xCF,
	0x00,
};

static u8 A12S_TD4150_BOE_025[] = {
	0xD0,
	0xC2, 0x33, 0x81, 0x66, 0x09, 0x90, 0x00, 0xC0, 0x92, 0x80,
	0x12, 0x48, 0x06, 0x7E, 0x09, 0x08, 0xD0, 0x00,
};

static u8 A12S_TD4150_BOE_026[] = {
	0xD1,
	0xCC, 0xD4, 0x1B, 0x33, 0x33, 0x17, 0x07, 0x3B, 0x55, 0x74,
	0x55, 0x74, 0x00, 0x33, 0x77, 0x07, 0x33, 0x30, 0x06, 0x72,
	0x13, 0x13, 0x00,
};

static u8 A12S_TD4150_BOE_027[] = {
	0xD2,
	0x0F, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_028[] = {
	0xD3,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF,
};

static u8 A12S_TD4150_BOE_029[] = {
	0xE5,
	0x03, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_030[] = {
	0xD6,
	0x00,
};

static u8 A12S_TD4150_BOE_031[] = {
	0xD7,
	0x21, 0x00, 0x12, 0x12, 0x00, 0x70, 0x08, 0x58, 0x00, 0x70,
	0x08, 0x58, 0x00, 0x83, 0x80, 0x85, 0x85, 0x85, 0x87, 0x84,
	0x45, 0x86, 0x87, 0x80, 0x82, 0x80, 0x80, 0x83, 0x83, 0x88,
	0x84, 0x08, 0x0C, 0x0C, 0x0B, 0x0A, 0x0A, 0x0A, 0x07, 0x07,
	0x06, 0x06, 0x0C, 0x08,
};

static u8 A12S_TD4150_BOE_032[] = {
	0xD9,
	0x00, 0x02, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_033[] = {
	0xDD,
	0x30, 0x06, 0x23, 0x65,
};

static u8 A12S_TD4150_BOE_034[] = {
	0xDE,
	0x00, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x10,
	0x00, 0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_035[] = {
	0xE3,
	0xFF,
};

static u8 A12S_TD4150_BOE_036[] = {
	0xE9,
	0x80, 0x11, 0x17, 0x00, 0x00, 0x00, 0x5C, 0x00, 0xFF, 0xBF,
	0x05, 0xFF, 0x9F, 0x04, 0xFF, 0x7F, 0x06, 0xFF, 0x3F, 0x05,
	0xFF, 0x9F, 0x04, 0xFF, 0xCF, 0x07, 0xFF, 0xE7, 0x07, 0xFF,
	0xF3, 0x07, 0xFF, 0xF9, 0x07, 0xCD, 0xFF, 0x07, 0xE4, 0xFF,
	0x07, 0xF3, 0xFF, 0x07, 0xE9, 0xFF, 0x07, 0xE4, 0xFC, 0x07,
	0x7F, 0xFE, 0x07, 0x3F, 0xFF, 0x07, 0x9F, 0xFF, 0x07, 0xDF,
	0xFF, 0x07, 0x0C,
};

static u8 A12S_TD4150_BOE_037[] = {
	0xEA,
	0x02, 0x0A, 0x14, 0x08, 0xE1, 0x0A, 0x20, 0xA2, 0x00, 0x00,
	0x00, 0x0A, 0x23, 0x00, 0x03, 0x01, 0x16, 0x01, 0x16, 0x01,
	0x16, 0x01, 0x28, 0x01, 0x28, 0x00, 0x70, 0x00, 0x00, 0x00,
	0x7F, 0x00, 0x34, 0x00,
};

static u8 A12S_TD4150_BOE_038[] = {
	0xEB,
	0x0A, 0x00, 0x9D, 0x04, 0x71, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_039[] = {
	0xEC,
	0x01, 0xC0, 0x00, 0x10, 0x9B, 0x0A, 0x20, 0xA2, 0x00, 0x00,
	0x00, 0x01, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 A12S_TD4150_BOE_040[] = {
	0xED,
	0x01, 0x02, 0x06, 0x07, 0x00, 0x00, 0x02, 0x01, 0x66, 0x10,
	0x01, 0x00, 0x08, 0x00, 0x80, 0x08, 0x00, 0x00, 0x00, 0x01,
	0x0F, 0x00, 0x01, 0x30, 0x01, 0x01, 0x0F, 0x00, 0x00, 0x10,
	0x81, 0x10, 0x01,
};

static u8 A12S_TD4150_BOE_041[] = {
	0xEE,
	0x05, 0x40, 0x05, 0x00, 0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00,
	0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0x00, 0xC0, 0x0F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x02,
};

static u8 A12S_TD4150_BOE_042[] = {
	0xB0,
	0x03,
};

static DEFINE_STATIC_PACKET(a12s_sleep_out, DSI_PKT_TYPE_WR, A12S_SLEEP_OUT, 0);
static DEFINE_STATIC_PACKET(a12s_sleep_in, DSI_PKT_TYPE_WR, A12S_SLEEP_IN, 0);
static DEFINE_STATIC_PACKET(a12s_display_on, DSI_PKT_TYPE_WR, A12S_DISPLAY_ON, 0);
static DEFINE_STATIC_PACKET(a12s_display_off, DSI_PKT_TYPE_WR, A12S_DISPLAY_OFF, 0);
static DEFINE_STATIC_PACKET(a12s_brightness_mode, DSI_PKT_TYPE_WR, A12S_BRIGHTNESS_MODE, 0);
static DEFINE_STATIC_PACKET(a12s_brightness_cabc_mode, DSI_PKT_TYPE_WR, A12S_BRIGHTNESS_CABC_MODE, 0);
static DEFINE_STATIC_PACKET(a12s_brightness_cabc_min, DSI_PKT_TYPE_WR, A12S_BRIGHTNESS_CABC_MIN, 0);

static DEFINE_PKTUI(a12s_brightness, &a12s_maptbl[BRT_MAPTBL], 1);
static DEFINE_VARIABLE_PACKET(a12s_brightness, DSI_PKT_TYPE_WR, A12S_BRIGHTNESS, 0);

static DEFINE_STATIC_PACKET(a12s_td4150_boe_001, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_001, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_002, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_002, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_003, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_003, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_004, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_004, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_005, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_005, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_006, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_006, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_007, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_007, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_008, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_008, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_009, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_009, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_010, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_010, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_011, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_011, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_012, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_012, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_013, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_013, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_014, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_014, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_015, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_015, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_016, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_016, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_017, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_017, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_018, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_018, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_019, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_019, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_020, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_020, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_021, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_021, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_022, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_022, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_023, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_023, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_024, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_024, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_025, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_025, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_026, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_026, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_027, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_027, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_028, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_028, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_029, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_029, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_030, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_030, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_031, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_031, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_032, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_032, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_033, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_033, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_034, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_034, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_035, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_035, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_036, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_036, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_037, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_037, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_038, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_038, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_039, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_039, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_040, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_040, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_041, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_041, 0);
static DEFINE_STATIC_PACKET(a12s_td4150_boe_042, DSI_PKT_TYPE_WR, A12S_TD4150_BOE_042, 0);

static DEFINE_PANEL_MDELAY(a12s_wait_display_off, 1 * 17); /* 1 frame */
static DEFINE_PANEL_MDELAY(a12s_wait_sleep_out, 5 * 17); /* 4 frame */  /* 70ms */
static DEFINE_PANEL_MDELAY(a12s_wait_60msec, 60);
static DEFINE_PANEL_MDELAY(a12s_wait_10msec, 10);
static DEFINE_PANEL_MDELAY(a12s_wait_blic_off, 1);


static void *a12s_init_cmdtbl[] = {
	&td4150_boe_restbl[RES_ID],
	&PKTINFO(a12s_td4150_boe_001),
	&PKTINFO(a12s_td4150_boe_002),
	&PKTINFO(a12s_td4150_boe_003),
	&PKTINFO(a12s_td4150_boe_004),
	&PKTINFO(a12s_td4150_boe_005),
	&PKTINFO(a12s_td4150_boe_006),
	&PKTINFO(a12s_td4150_boe_007),
	&PKTINFO(a12s_td4150_boe_008),
	&PKTINFO(a12s_td4150_boe_009),
	&PKTINFO(a12s_td4150_boe_010),
	&PKTINFO(a12s_td4150_boe_011),
	&PKTINFO(a12s_td4150_boe_012),
	&PKTINFO(a12s_td4150_boe_013),
	&PKTINFO(a12s_td4150_boe_014),
	&PKTINFO(a12s_td4150_boe_015),
	&PKTINFO(a12s_td4150_boe_016),
	&PKTINFO(a12s_td4150_boe_017),
	&PKTINFO(a12s_td4150_boe_018),
	&PKTINFO(a12s_td4150_boe_019),
	&PKTINFO(a12s_td4150_boe_020),
	&PKTINFO(a12s_td4150_boe_021),
	&PKTINFO(a12s_td4150_boe_022),
	&PKTINFO(a12s_td4150_boe_023),
	&PKTINFO(a12s_td4150_boe_024),
	&PKTINFO(a12s_td4150_boe_025),
	&PKTINFO(a12s_td4150_boe_026),
	&PKTINFO(a12s_td4150_boe_027),
	&PKTINFO(a12s_td4150_boe_028),
	&PKTINFO(a12s_td4150_boe_029),
	&PKTINFO(a12s_td4150_boe_030),
	&PKTINFO(a12s_td4150_boe_031),
	&PKTINFO(a12s_td4150_boe_032),
	&PKTINFO(a12s_td4150_boe_033),
	&PKTINFO(a12s_td4150_boe_034),
	&PKTINFO(a12s_td4150_boe_035),
	&PKTINFO(a12s_td4150_boe_036),
	&PKTINFO(a12s_td4150_boe_037),
	&PKTINFO(a12s_td4150_boe_038),
	&PKTINFO(a12s_td4150_boe_039),
	&PKTINFO(a12s_td4150_boe_040),
	&PKTINFO(a12s_td4150_boe_041),
	&PKTINFO(a12s_td4150_boe_042),
	&PKTINFO(a12s_brightness_cabc_mode),
	&PKTINFO(a12s_brightness_cabc_min),
	&PKTINFO(a12s_sleep_out),
	&DLYINFO(a12s_wait_sleep_out),
};

static void *a12s_res_init_cmdtbl[] = {
	&td4150_boe_restbl[RES_ID],
};

static void *a12s_set_bl_cmdtbl[] = {
	&PKTINFO(a12s_brightness), //51h
};

static void *a12s_display_on_cmdtbl[] = {
	&PKTINFO(a12s_display_on),
	&PKTINFO(a12s_brightness_mode),
};

static void *a12s_display_off_cmdtbl[] = {
	&PKTINFO(a12s_display_off),
	&DLYINFO(a12s_wait_display_off),
};

static void *a12s_exit_cmdtbl[] = {
	&PKTINFO(a12s_sleep_in),
};

/* ===================================================================================== */
/* ================================= [EA8076 I2C TABLE] ===========+++================= */
/* ===================================================================================== */
static u8 TD4150_A12S_I2C_INIT[] = {
	0x0C, 0x2C,
	0x0D, 0x26,
	0x0E, 0x26,
	0x09, 0xBE,
	0x02, 0x6B,
	0x03, 0x0D,
	0x11, 0x74,
	0x04, 0x05,
	0x05, 0xCC,
	0x10, 0x67,
	0x08, 0x13,
};

static u8 TD4150_A12S_I2C_EXIT_VSN[] = {
	0x09, 0xBC,
};

static u8 TD4150_A12S_I2C_EXIT_VSP[] = {
	0x09, 0xB8,
};

static DEFINE_STATIC_PACKET(td4150_boe_a12s_i2c_init, I2C_PKT_TYPE_WR, TD4150_A12S_I2C_INIT, 0);
static DEFINE_STATIC_PACKET(td4150_boe_a12s_i2c_exit_vsn, I2C_PKT_TYPE_WR, TD4150_A12S_I2C_EXIT_VSN, 0);
static DEFINE_STATIC_PACKET(td4150_boe_a12s_i2c_exit_vsp, I2C_PKT_TYPE_WR, TD4150_A12S_I2C_EXIT_VSP, 0);
static DEFINE_STATIC_PACKET(td4150_boe_a12s_i2c_dump, I2C_PKT_TYPE_RD, TD4150_A12S_I2C_INIT, 0);

static void *td4150_boe_a12s_init_cmdtbl[] = {
	&PKTINFO(td4150_boe_a12s_i2c_init),
};

static void *td4150_boe_a12s_exit_cmdtbl[] = {
	&PKTINFO(td4150_boe_a12s_i2c_exit_vsn),
	&DLYINFO(a12s_wait_blic_off),
	&PKTINFO(td4150_boe_a12s_i2c_exit_vsp),
};

static void *td4150_boe_a12s_dump_cmdtbl[] = {
	&PKTINFO(td4150_boe_a12s_i2c_dump),
};


static struct seqinfo a12s_seqtbl[MAX_PANEL_SEQ] = {
	[PANEL_INIT_SEQ] = SEQINFO_INIT("init-seq", a12s_init_cmdtbl),
	[PANEL_RES_INIT_SEQ] = SEQINFO_INIT("resource-init-seq", a12s_res_init_cmdtbl),
	[PANEL_SET_BL_SEQ] = SEQINFO_INIT("set-bl-seq", a12s_set_bl_cmdtbl),
	[PANEL_DISPLAY_ON_SEQ] = SEQINFO_INIT("display-on-seq", a12s_display_on_cmdtbl),
	[PANEL_DISPLAY_OFF_SEQ] = SEQINFO_INIT("display-off-seq", a12s_display_off_cmdtbl),
	[PANEL_EXIT_SEQ] = SEQINFO_INIT("exit-seq", a12s_exit_cmdtbl),
#ifdef CONFIG_SUPPORT_I2C
	[PANEL_I2C_INIT_SEQ] = SEQINFO_INIT("i2c-init-seq", td4150_boe_a12s_init_cmdtbl),
	[PANEL_I2C_EXIT_SEQ] = SEQINFO_INIT("i2c-exit-seq", td4150_boe_a12s_exit_cmdtbl),
	[PANEL_I2C_DUMP_SEQ] = SEQINFO_INIT("i2c-dump-seq", td4150_boe_a12s_dump_cmdtbl),
#endif
};

struct common_panel_info td4150_boe_a12s_default_panel_info = {
	.ldi_name = "td4150_boe",
	.name = "td4150_boe_a12s_default",
	.model = "BOE_6_517_inch",
	.vendor = "BOE",
	.id = 0x3A6220,
	.rev = 0,
	.ddi_props = {
		.gpara = 0,
		.err_fg_recovery = false,
		.init_seq_by_lpdt = true,
	},
	.mres = {
		.nr_resol = ARRAY_SIZE(td4150_boe_a12s_resol),
		.resol = td4150_boe_a12s_resol,
	},
	.maptbl = a12s_maptbl,
	.nr_maptbl = ARRAY_SIZE(a12s_maptbl),
	.seqtbl = a12s_seqtbl,
	.nr_seqtbl = ARRAY_SIZE(a12s_seqtbl),
	.rditbl = td4150_boe_rditbl,
	.nr_rditbl = ARRAY_SIZE(td4150_boe_rditbl),
	.restbl = td4150_boe_restbl,
	.nr_restbl = ARRAY_SIZE(td4150_boe_restbl),
	.dumpinfo = NULL,
	.nr_dumpinfo = 0,
	.panel_dim_info = {
		&td4150_boe_a12s_panel_dimming_info,
	},
	.i2c_data = &td4150_boe_a12s_i2c_data,
};

static int __init td4150_boe_a12s_panel_init(void)
{
	register_common_panel(&td4150_boe_a12s_default_panel_info);

	return 0;
}
arch_initcall(td4150_boe_a12s_panel_init)
#endif /* __TD4150_A12S_PANEL_H__ */
