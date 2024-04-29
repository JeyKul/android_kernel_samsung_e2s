// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2013-2016, Linux Foundation. All rights reserved.
 */
#ifndef _UFS_DUMP_H_
#define _UFS_DUMP_H_

enum {
	LOG_STD_HCI_SFR = 0xFFFFFFF0,
	LOG_VS_HCI_SFR,
	LOG_FMP_SFR,
	LOG_UNIPRO_SFR,
	LOG_PMA_SFR,
	LOG_MCQ_SFR,
	LOG_SQCQ_SFR,
	LOG_INVALID,
};

enum {
	DBG_ATTR_UNIPRO = 0xEFFFFFF0,
	DBG_ATTR_PCS_CMN,
	DBG_ATTR_PCS_TX,
	DBG_ATTR_PCS_RX,
	DBG_ATTR_DIRECT_PCS_TX,
	DBG_ATTR_DIRECT_PCS_RX,
	DBG_ATTR_PCS_START,
	DBG_ATTR_PCS_END,
};

enum {
	DBG_ATTR_CPORT_TX = 0xDFFFFFF0,
	DBG_ATTR_CPORT_RX,
	DBG_ATTR_CPORT_PTR,
	DBG_ATTR_CPORT_UTRL,
	DBG_ATTR_CPORT_UCD,
	DBG_ATTR_CPORT_UTMRL,
	DBG_ATTR_CPORT_REMAP,
	DBG_ATTR_CPORT_END,
};

enum {
	SFR_VAL_H_0_FIRST = 0,
	SFR_VAL_H_0,
	SFR_VAL_NUM,
};

enum {
	ATTR_VAL_H_0_L_0_FIRST = 0,
	ATTR_VAL_H_0_L_1_FIRST,
	ATTR_VAL_H_0_L_0,
	ATTR_VAL_H_0_L_1,
	ATTR_VAL_NUM,
};

struct exynos_ufs_sfr_log {
	const char* name;
	const u32 offset;
	u32 val[SFR_VAL_NUM];
};

struct exynos_ufs_attr_log {
	const u32 mib;
	const u32 offset;
	/* 0: lane0, 1: lane1 */
	u32 val[ATTR_VAL_NUM];
};

struct exynos_ufs_cport_log {
	const u32 mib;
	const char *name;
	const u32 offset;
	const u32 size;
};

static struct exynos_ufs_cport_log ufs_cport_sfr[] = {
	{DBG_ATTR_CPORT_TX,	"TX BUF",	0x0,	0x100},
	{DBG_ATTR_CPORT_RX,	"RX BUF",	0x100,	0x100},
	{DBG_ATTR_CPORT_PTR,	"CPORT LOG PTR",	0x200,	0x100},
	{DBG_ATTR_CPORT_UTRL,	"UTRL",	0x300,	0x800},
	{DBG_ATTR_CPORT_UCD,	"UCD",	0x700, 0x800},
	{DBG_ATTR_CPORT_UTMRL,	"UTMRL",	0xB00, 0xc0},
	{DBG_ATTR_CPORT_END,	0,	0},
};

static struct exynos_ufs_sfr_log ufs_log_sfr[] = {
	{"STD HCI SFR",	LOG_STD_HCI_SFR,	{0}},

	{"AHIT",	0x18,	{0}},
	{"INTERRUPT STATUS",	0x20,	{0}},
	{"INTERRUPT ENABLE",	0x24,	{0}},
	{"CONTROLLER STATUS",	0x30,	{0}},
	{"CONTROLLER ENABLE",	0x34,	{0}},
	{"UFS_PH_UECPA",	0x38,	{0}},
	{"UFS_PH_UECDL",	0x3C,	{0}},
	{"UFS_PH_UECN",		0x40,	{0}},
	{"UFS_PH_UECT",		0x44,	{0}},
	{"UFS_PH_UECDME",	0x48,	{0}},
	{"UTP TRANSF REQ INT AGG CNTRL",	0x4C,	{0}},
	{"UTP TRANSF REQ LIST BASE L",	0x50,	{0}},
	{"UTP TRANSF REQ LIST BASE H",	0x54,	{0}},
	{"UTP TRANSF REQ DOOR BELL",	0x58,	{0}},
	{"UTP TRANSF REQ LIST CLEAR",	0x5C,	{0}},
	{"UTP TRANSF REQ LIST RUN STOP",	0x60,	{0}},
	{"UTP TRANSF REQ LIST CNR",	0x64,	{0}},
	{"UTP TASK REQ LIST BASE L",	0x70,	{0}},
	{"UTP TASK REQ LIST BASE H",	0x74,	{0}},
	{"UTP TASK REQ DOOR BELL",	0x78,	{0}},
	{"UTP TASK REQ LIST CLEAR",	0x7C,	{0}},
	{"UTP TASK REQ LIST RUN STOP",	0x80,	{0}},
	{"UIC COMMAND",	0x90,	{0}},
	{"UIC COMMAND ARG1",	0x94,	{0}},
	{"UIC COMMAND ARG2",	0x98,	{0}},
	{"UIC COMMAND ARG3",	0x9C,	{0}},
	{"MH_IS",	0xd0,	{0}},
	{"MH_IE",	0xd4,	{0}},
	{"DBR_DUPLICATION_INFO",	0xe8,	{0}},
	{"SMU_CDB_INVALID_INFO",	0xec,	{0}},
	{"SMU_UNMAP_INVALID_INFO",	0xf4,	{0}},
	{"CCAP",	0x100,	{0}},

	{"VS HCI SFR",	LOG_VS_HCI_SFR,	{0}},

	{"TXPRDT ENTRY SIZE",	0x1100,	{0}},
	{"RXPRDT ENTRY SIZE",	0x1104,	{0}},
	{"TO CNT DIV VAL",	0x1108,	{0}},
	{"1US TO CNT VAL",	0x110C,	{0}},
	{"INVALID UPIU CTRL",	0x1110,	{0}},
	{"INVALID UPIU BADDR",	0x1114,	{0}},
	{"INVALID UPIU UBADDR",	0x1118,	{0}},
	{"INVALID UTMR OFFSET ADDR",	0x111C,	{0}},
	{"INVALID UTR OFFSET ADDR",	0x1120,	{0}},
	{"INVALID DIN OFFSET ADDR",	0x1124,	{0}},
	{"VENDOR SPECIFIC IS",	0x1138,	{0}},
	{"VENDOR SPECIFIC IE",	0x113C,	{0}},
	{"UTRL NEXUS TYPE",	0x1140,	{0}},
	{"UTMRL NEXUS TYPE",	0x1144,	{0}},
	{"SW RST",	0x1150,	{0}},
	{"RX UPIU MATCH ERROR CODE",	0x115C,	{0}},
	{"DATA REORDER",	0x1160,	{0}},
	{"AXIDMA RWDATA BURST LEN",	0x116C,	{0}},
	{"WRITE DMA CTRL",	0x1174,	{0}},
	{"V2P1 CTRL",	0x118C,	{0}},
	{"CLKSTOP CTRL",	0x11B0,	{0}},
	{"UFS_PH MISC",		0x11B4,	{0}},
	{"DMA0 MONITOR STATE",	0x11C8,	{0}},
	{"DMA0 MONITOR CNT",	0x11CC,	{0}},
	{"DMA1 MONITOR STATE",	0x11D0,	{0}},
	{"DMA1 MONITOR CNT",	0x11D4,	{0}},
	{"DMA0 DOORBELL DEBUG",	0x11D8,	{0}},
	{"DMA1 DOORBELL DEBUG",	0x11DC,	{0}},

	{"AXI DMA IF CTRL",	0x11F8,	{0}},
	{"UFS ACG DISABLE",	0x11FC,	{0}},
	{"MPHY REFCLK SEL",	0x1208,	{0}},

	{"SMU RD ABORT MATCH INFO",	0x1218,	{0}},
	{"SMU WR ABORT MATCH INFO",	0x121C,	{0}},

	{"INVALID PRDT CTRL",	0x1230,	{0}},
	{"UFS_PH_AH8_H8T",	0x1604,	{0}},
	{"UFS_PH_AH8_CLKGATE_CONFIG",	0x1608,	{0}},
	{"UFS_PH_AH8_STATE",	0x160c,	{0}},
	{"UFS_PH_AH8_ERR_CONTROL",	0x1614,	{0}},
	{"UFS_PH_AH8_INT_CONTROL",	0x1618,	{0}},
	{"UFS_PH_AH8_PROC_MPHY",	0x161c,	{0}},
	{"UFS_PH_AH8_PROC_CONFIG",	0x1620,	{0}},
	{"UFS_PH_AH8_TIMEOUT",	0x1624,	{0}},
	{"UFS_CLKDIV",	0x1810,	{0}},
	{"UFS_PH_VENDOR_SPECIFIC_IS_2", 0x1814,  {0}},
        {"UFS_PH_AXIDMA_FSM_TIMER",     0x181C,  {0}},

	{"FMP SFR",	LOG_FMP_SFR,	{0}},

	{"UFSPRCTRL",	0x0000,	{0}},
	{"UFSPRSTAT0",	0x0008,	{0}},
	{"UFSPRSTAT1",	0x000C,	{0}},
	{"UFSPRSECURITY0",	0x0010,	{0}},
	{"UFSPRSECURITY1",	0x0014,	{0}},
	{"UFSPRSECURITY2",	0x0018,	{0}},
	{"UFSPRVERSION",	0x001C,	{0}},
	{"UFSPWCTRL",	0x0100,	{0}},
	{"UFSPWSTAT0",	0x0108,	{0}},
	{"UFSPWSTAT1",	0x010C,	{0}},
	{"UFSPSBEGIN0",	0x2000,	{0}},
	{"UFSPSEND0",	0x2004,	{0}},
	{"UFSPSLUN0",	0x2008,	{0}},
	{"UFSPSCTRL0",	0x200C,	{0}},
	{"UFSPSBEGIN1",	0x2010,	{0}},
	{"UFSPSEND1",	0x2014,	{0}},
	{"UFSPSLUN1",	0x2018,	{0}},
	{"UFSPSCTRL1",	0x201C,	{0}},
	{"UFSPSBEGIN2",	0x2020,	{0}},
	{"UFSPSEND2",	0x2024,	{0}},
	{"UFSPSLUN2",	0x2028,	{0}},
	{"UFSPSCTRL2",	0x202C,	{0}},
	{"UFSPSBEGIN3",	0x2030,	{0}},
	{"UFSPSEND3",	0x2034,	{0}},
	{"UFSPSLUN3",	0x2038,	{0}},
	{"UFSPSCTRL3",	0x203C,	{0}},
	{"UFSPSBEGIN4",	0x2040,	{0}},
	{"UFSPSEND4",	0x2044,	{0}},
	{"UFSPSLUN4",	0x2048,	{0}},
	{"UFSPSCTRL4",	0x204C,	{0}},
	{"UFSPSBEGIN5",	0x2050,	{0}},
	{"UFSPSEND5",	0x2054,	{0}},
	{"UFSPSLUN5",	0x2058,	{0}},
	{"UFSPSCTRL5",	0x205C,	{0}},
	{"UFSPSBEGIN6",	0x2060,	{0}},
	{"UFSPSEND6",	0x2064,	{0}},
	{"UFSPSLUN6",	0x2068,	{0}},
	{"UFSPSCTRL6",	0x206C,	{0}},
	{"UFSPSBEGIN7",	0x2070,	{0}},
	{"UFSPSEND7",	0x2074,	{0}},
	{"UFSPSLUN7",	0x2078,	{0}},
	{"UFSPSCTRL7",	0x207C,	{0}},

	{"UNIPRO SFR",	LOG_UNIPRO_SFR,	{0}},

	{"DME_LINKSTARTUP_CNF_RESULT",		(0x7854),	{0}},
	{"DME_HIBERNATE_ENTER_CNF_RESULT",		(0x7864),	{0}},
	{"DME_HIBERNATE_ENTER_IND_RESULT",		(0x7868),	{0}},
	{"DME_HIBERNATE_EXIT_CNF_RESULT",		(0x7874),	{0}},
	{"DME_HIBERNATE_EXIT_IND_RESULT",		(0x7878),	{0}},
	{"DME_POWERMODE_IND_RESULT",		(0x78EC),	{0}},
	{"DME_INTR_STATUS_LSB",		(0x7B00),	{0}},
	{"DME_INTR_STATUS_MSB",		(0x7B04),	{0}},
	{"DME_INTR_ERROR_CODE",		(0x7B20),	{0}},
	{"DME_DBG_OPTION_SUITE",		(0x7C00),	{0}},
	{"DME_DBG_CTRL_FSM",		(0x7D00),	{0}},
	{"DME_DBG_FLAG_STATUS",		(0x7D14),	{0}},
	{"DME_DBG_LINKCFG_FSM",		(0x7D18),	{0}},
	{"DME_DBG_ERROR_HISTORY_COUNTER",		(0x7E10),	{0}},
	{"DME_DBG_ERROR_HISTORY_POINTER",		(0x7E14),	{0}},
	{"DME_DBG_ERROR_HISTORY_0",		(0x7E20),	{0}},
	{"DME_DBG_ERROR_HISTORY_1",		(0x7E24),	{0}},
	{"DME_DBG_ERROR_HISTORY_2",		(0x7E28),	{0}},
	{"DME_DBG_ERROR_HISTORY_3",		(0x7E2C),	{0}},
	{"DME_DBG_ERROR_HISTORY_4",		(0x7E30),	{0}},
	{"DME_DBG_ERROR_HISTORY_5",		(0x7E34),	{0}},
	{"DME_DBG_ERROR_HISTORY_6",		(0x7E38),	{0}},
	{"DME_DBG_ERROR_HISTORY_7",		(0x7E3C),	{0}},

	{"PMA SFR",	LOG_PMA_SFR,	{0}},

	{"CMN_REG05E",		(0x0178),	{0}},
	{"CMN_REG061",		(0x0184),	{0}},
	{"CMN_REG062",		(0x0188),	{0}},
	{"TRSV_REG2FB",		(0x0BEC),	{0}},
	{"TRSV_REG2FC",		(0x0BF0),	{0}},
	{"TRSV_REG2FD",		(0x0BF4),	{0}},
	{"TRSV_REG2FE",		(0x0BF8),	{0}},
	{"TRSV_REG2FF",		(0x0BFC),	{0}},
	{"TRSV_REG300",		(0x0C00),	{0}},
	{"TRSV_REG301",		(0x0C04),	{0}},
	{"TRSV_REG302",		(0x0C08),	{0}},
	{"TRSV_REG303",		(0x0C0C),	{0}},
	{"TRSV_REG304",		(0x0C10),	{0}},
	{"TRSV_REG305",		(0x0C14),	{0}},
	{"TRSV_REG306",		(0x0C18),	{0}},
	{"TRSV_REG307",		(0x0C1C),	{0}},
	{"TRSV_REG310",		(0x0C40),	{0}},
	{"TRSV_REG311",		(0x0C44),	{0}},
	{"TRSV_REG316",		(0x0C58),	{0}},
	{"TRSV_REG317",		(0x0C5C),	{0}},
	{"TRSV_REG31D",		(0x0C74),	{0}},
	{"TRSV_REG31E",		(0x0C78),	{0}},
	{"TRSV_REG31F",		(0x0C7C),	{0}},
	{"TRSV_REG32F",		(0x0CBC),	{0}},
	{"TRSV_REG332",		(0x0CC8),	{0}},
	{"TRSV_REG333",		(0x0CCC),	{0}},
	{"TRSV_REG4FB",		(0x13EC),	{0}},
	{"TRSV_REG4FC",		(0x13F0),	{0}},
	{"TRSV_REG4FD",		(0x13F4),	{0}},
	{"TRSV_REG4FE",		(0x13F8),	{0}},
	{"TRSV_REG4FF",		(0x13FC),	{0}},
	{"TRSV_REG500",		(0x1400),	{0}},
	{"TRSV_REG501",		(0x1404),	{0}},
	{"TRSV_REG502",		(0x1408),	{0}},
	{"TRSV_REG503",		(0x140C),	{0}},
	{"TRSV_REG504",		(0x1410),	{0}},
	{"TRSV_REG505",		(0x1414),	{0}},
	{"TRSV_REG506",		(0x1418),	{0}},
	{"TRSV_REG507",		(0x141C),	{0}},
	{"TRSV_REG510",		(0x1440),	{0}},
	{"TRSV_REG511",		(0x1444),	{0}},
	{"TRSV_REG516",		(0x1458),	{0}},
	{"TRSV_REG517",		(0x145C),	{0}},
	{"TRSV_REG51D",		(0x1474),	{0}},
	{"TRSV_REG51E",		(0x1478),	{0}},
	{"TRSV_REG51F",		(0x147C),	{0}},
	{"TRSV_REG52F",		(0x14BC),	{0}},
	{"TRSV_REG532",		(0x14C8),	{0}},
	{"TRSV_REG533",		(0x14CC),	{0}},
	{0, 0,	{0}},
};

static struct exynos_ufs_sfr_log ufs_log_sfr_evt1[] = {
};

static struct exynos_ufs_attr_log ufs_log_attr[] = {
	{DBG_ATTR_UNIPRO, 0,	{0, 0}},
	/* PA Standard */
	{0x1520,	0x3080,	{0, 0}},
	{0x1540,	0x3100,	{0, 0}},
	{0x1543,	0x310C,	{0, 0}},
	{0x155C,	0x3170,	{0, 0}},
	{0x155D,	0x3174,	{0, 0}},
	{0x155F,	0x317C,	{0, 0}},
	{0x1560,	0x3180,	{0, 0}},
	{0x1561,	0x3184,	{0, 0}},
	{0x1564,	0x3190,	{0, 0}},
	{0x1567,	0x319C,	{0, 0}},
	{0x1568,	0x31A0,	{0, 0}},
	{0x1569,	0x31A4,	{0, 0}},
	{0x156A,	0x31A8,	{0, 0}},
	{0x1571,	0x31C4,	{0, 0}},
	{0x1580,	0x3200,	{0, 0}},
	{0x1581,	0x3204,	{0, 0}},
	{0x1582,	0x3208,	{0, 0}},
	{0x1583,	0x320C,	{0, 0}},
	{0x1584,	0x3210,	{0, 0}},
	{0x1585,	0x3214,	{0, 0}},
	{0x1590,	0x3240,	{0, 0}},
	{0x1591,	0x3244,	{0, 0}},
	{0x15A1,	0x3284,	{0, 0}},
	{0x15A2,	0x3288,	{0, 0}},
	{0x15A3,	0x328C,	{0, 0}},
	{0x15A4,	0x3290,	{0, 0}},
	{0x15A7,	0x329C,	{0, 0}},
	{0x15A8,	0x32A0,	{0, 0}},
	{0x15A9,	0x32A4,	{0, 0}},
	{0x15C0,	0x3300,	{0, 0}},
	{0x15C1,	0x3304,	{0, 0}},
	{0x15D2,	0x3348,	{0, 0}},
	{0x15D3,	0x334C,	{0, 0}},
	{0x15D4,	0x3350,	{0, 0}},
	{0x15D5,	0x3354,	{0, 0}},
	/* PA Debug */
	{0x9500,	0x3800,	{0, 0}},
	{0x9501,	0x3804,	{0, 0}},
	{0x9502,	0x3808,	{0, 0}},
	{0x9504,	0x3810,	{0, 0}},
	{0x9564,	0x3990,	{0, 0}},
	{0x956A,	0x39A8,	{0, 0}},
	{0x956D,	0x39B4,	{0, 0}},
	{0x9570,	0x39C0,	{0, 0}},
	{0x9595,	0x3A54,	{0, 0}},
	{0x9596,	0x3A58,	{0, 0}},
	{0x9597,	0x3A5C,	{0, 0}},
	{0x95C0,	0x3B00,	{0, 0}},
	{0x95C1,	0x3B04,	{0, 0}},
	{0x0044,	0x0044,	{0, 0}},
	/* DL Standard */
	{0x2047,	0x411C, {0, 0}},
	{0x2067,	0x419C, {0, 0}},
	/* DL Debug */
	{0xA000,	0x4800, {0, 0}},
	{0xA005,	0x4814, {0, 0}},
	{0xA007,	0x481C, {0, 0}},
	{0xA010,	0x4840, {0, 0}},
	{0xA020,	0x4880, {0, 0}},
	{0xA021,	0x4884, {0, 0}},
	{0xA022,	0x4888, {0, 0}},
	{0xA023,	0x488C, {0, 0}},
	{0xA024,	0x4890, {0, 0}},
	{0xA025,	0x4894, {0, 0}},
	{0xA026,	0x4898, {0, 0}},
	{0xA027,	0x489C, {0, 0}},
	{0xA100,	0x4C00, {0, 0}},
	{0xA101,	0x4C04, {0, 0}},
	{0xA102,	0x4C08, {0, 0}},
	{0xA103,	0x4C0C, {0, 0}},
	{0xA114,	0x4C50, {0, 0}},
	{0xA115,	0x4C54, {0, 0}},
	{0xA116,	0x4C58, {0, 0}},
	{0xA120,	0x4C80, {0, 0}},
	{0xA121,	0x4C84, {0, 0}},
	{0xA122,	0x4C88, {0, 0}},
	/* NL Standard */
	/* NL Debug */
	{0xB011,	0x5844,	{0, 0}},
	/* TL Standard */
	{0x4020,	0x6080, {0, 0}},
	/* TL Debug */
	{0xC001,	0x6804,	{0, 0}},
	{0xC024,	0x6890,	{0, 0}},
	{0xC026,	0x6898,	{0, 0}},
	/* MPHY PCS TX */
        {DBG_ATTR_PCS_TX, 0,    {0, 0}},
	{0x0021, 0x2084,        {0, 0}},
	{0x0022, 0x2088,        {0, 0}},
	{0x0023, 0x208C,        {0, 0}},
	{0x0024, 0x2090,        {0, 0}},
	{0x0028, 0x20A0,        {0, 0}},
	{0x0029, 0x20A4,        {0, 0}},
	{0x002A, 0x20A8,        {0, 0}},
	{0x002B, 0x20AC,        {0, 0}},
	{0x002C, 0x20B0,        {0, 0}},
	{0x002D, 0x20B4,        {0, 0}},
	{0x0033, 0x20CC,        {0, 0}},
	{0x0035, 0x20D4,        {0, 0}},
	{0x0036, 0x20D8,        {0, 0}},
	{0x0041, 0x2104,        {0, 0}},
        /* MPHY PCS RX */
	{DBG_ATTR_PCS_RX, 0,    {0, 0}},
	{0x00A1, 0x2284,        {0, 0}},
	{0x00A2, 0x2288,        {0, 0}},
	{0x00A3, 0x228C,        {0, 0}},
	{0x00A4, 0x2290,        {0, 0}},
	{0x00A7, 0x229C,        {0, 0}},
	{0x00C1, 0x2304,        {0, 0}},
	{0x0006, 0x2018,        {0, 0}},
	{0x0012, 0x2048,        {0, 0}},
	{0x0019, 0x2064,        {0, 0}},
	{0x0023, 0x208C,        {0, 0}},
	{0x0024, 0x2090,        {0, 0}},
	{0x005D, 0x2174,        {0, 0}},
	{0, 0,	{0, 0}},
};

#endif	/* _UFS_DUMP_H_ */
