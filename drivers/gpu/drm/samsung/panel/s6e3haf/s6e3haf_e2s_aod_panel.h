/*
 * linux/drivers/video/fbdev/exynos/panel/s6e3haf/s6e3haf_e2s_aod_panel.h
 *
 * Header file for AOD Driver
 *
 * Copyright (c) 2016 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __S6E3HAF_E2S_AOD_PANEL_H__
#define __S6E3HAF_E2S_AOD_PANEL_H__

#include "oled_common_aod.h"
#include "oled_function.h"
#include "s6e3haf_e2s_self_mask_img.h"
#include "s6e3haf_e2s_aod.h"

static u8 E2S_AOD_KEY1_ENABLE[] = { 0x9F, 0xA5, 0xA5 };
static u8 E2S_AOD_KEY1_DISABLE[] = { 0x9F, 0x5A, 0x5A };

static u8 E2S_AOD_KEY2_ENABLE[] = { 0xF0, 0x5A, 0x5A };
static u8 E2S_AOD_KEY2_DISABLE[] = { 0xF0, 0xA5, 0xA5 };

static u8 E2S_AOD_KEY3_ENABLE[] = { 0xFC, 0x5A, 0x5A };
static u8 E2S_AOD_KEY3_DISABLE[] = { 0xFC, 0xA5, 0xA5 };

static DEFINE_STATIC_PACKET(e2s_aod_l1_key_enable, DSI_PKT_TYPE_WR, E2S_AOD_KEY1_ENABLE, 0);
static DEFINE_STATIC_PACKET(e2s_aod_l1_key_disable, DSI_PKT_TYPE_WR,E2S_AOD_KEY1_DISABLE, 0);

static DEFINE_STATIC_PACKET(e2s_aod_l2_key_enable, DSI_PKT_TYPE_WR, E2S_AOD_KEY2_ENABLE, 0);
static DEFINE_STATIC_PACKET(e2s_aod_l2_key_disable, DSI_PKT_TYPE_WR,E2S_AOD_KEY2_DISABLE, 0);

static DEFINE_STATIC_PACKET(e2s_aod_l3_key_enable, DSI_PKT_TYPE_WR, E2S_AOD_KEY3_ENABLE, 0);
static DEFINE_STATIC_PACKET(e2s_aod_l3_key_disable, DSI_PKT_TYPE_WR, E2S_AOD_KEY3_DISABLE, 0);

static DEFINE_PANEL_MDELAY(e2s_aod_self_spsram_write_delay, 1);
static DEFINE_PANEL_MDELAY(e2s_aod_self_spsram_sel_delay, 1);

static DEFINE_PANEL_UDELAY(e2s_aod_self_mask_checksum_2frame_delay, 33400);
static DEFINE_PANEL_UDELAY(e2s_aod_time_update_delay, 33400);


static DEFINE_PANEL_KEY(e2s_aod_l1_key_enable, CMD_LEVEL_1,
	KEY_ENABLE, &PKTINFO(e2s_aod_l1_key_enable));
static DEFINE_PANEL_KEY(e2s_aod_l1_key_disable, CMD_LEVEL_1,
	KEY_DISABLE, &PKTINFO(e2s_aod_l1_key_disable));

static DEFINE_PANEL_KEY(e2s_aod_l2_key_enable, CMD_LEVEL_2,
	KEY_ENABLE, &PKTINFO(e2s_aod_l2_key_enable));
static DEFINE_PANEL_KEY(e2s_aod_l2_key_disable, CMD_LEVEL_2,
	KEY_DISABLE, &PKTINFO(e2s_aod_l2_key_disable));

static DEFINE_PANEL_KEY(e2s_aod_l3_key_enable, CMD_LEVEL_3,
	KEY_ENABLE, &PKTINFO(e2s_aod_l3_key_enable));
static DEFINE_PANEL_KEY(e2s_aod_l3_key_disable, CMD_LEVEL_3,
	KEY_DISABLE, &PKTINFO(e2s_aod_l3_key_disable));

static struct keyinfo KEYINFO(e2s_aod_l1_key_enable);
static struct keyinfo KEYINFO(e2s_aod_l1_key_disable);
static struct keyinfo KEYINFO(e2s_aod_l2_key_enable);
static struct keyinfo KEYINFO(e2s_aod_l2_key_disable);
static struct keyinfo KEYINFO(e2s_aod_l3_key_enable);
static struct keyinfo KEYINFO(e2s_aod_l3_key_disable);

static struct maptbl e2s_aod_maptbl[] = {};

// --------------------- Image for self mask image ---------------------

static char E2S_AOD_RESET_SD_PATH[] = { 0x75, 0x00, };
static DEFINE_STATIC_PACKET(e2s_aod_reset_sd_path, DSI_PKT_TYPE_WR, E2S_AOD_RESET_SD_PATH, 0);

static char E2S_AOD_SELF_MASK_SD_PATH[] = { 0x75, 0x10, };
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_sd_path, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_SD_PATH, 0);

// --------------------- End of self mask image ---------------------


// --------------------- Image for self mask control ---------------------
static char E2S_AOD_FACTORY_SELF_MASK_ENA[] = {
	0x7A,
	0x03, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x0C, 0x31,
	0x0C, 0x32, 0x0C, 0x33
};

static DEFINE_STATIC_PACKET(e2s_aod_factory_self_mask_ctrl_ena,
		DSI_PKT_TYPE_WR, E2S_AOD_FACTORY_SELF_MASK_ENA, 0);

static char E2S_AOD_SELF_MASK_ENA[] = {
	0x7A,
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2B,
	0x0B, 0x04, 0x0C, 0x2F
};

static DEFINE_STATIC_PACKET(e2s_aod_self_mask_ctrl_ena,
		DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_ENA, 0);

static DEFINE_RULE_BASED_COND(e2s_cond_is_factory_selfmask,
		PANEL_PROPERTY_IS_FACTORY_MODE, EQ, 1);

static void *e2s_aod_self_mask_ena_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&CONDINFO_IF(e2s_cond_is_factory_selfmask),
		&PKTINFO(e2s_aod_factory_self_mask_ctrl_ena),
	&CONDINFO_EL(e2s_cond_is_factory_selfmask),
		&PKTINFO(e2s_aod_self_mask_ctrl_ena),
	&CONDINFO_FI(e2s_cond_is_factory_selfmask),
	&KEYINFO(e2s_aod_l2_key_disable),
};

static char E2S_AOD_SELF_MASK_DISABLE[] = {
	0x7A,
	0x00,
};
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_disable, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_DISABLE, 0);

static void *e2s_aod_self_mask_dis_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_self_mask_disable),
	&KEYINFO(e2s_aod_l2_key_disable),
};
// --------------------- End of self mask control ---------------------

// --------------------- check sum control ----------------------------
static DEFINE_STATIC_PACKET_WITH_OPTION(e2s_aod_self_mask_crc_img_pkt,
		DSI_PKT_TYPE_WR_SR_FAST, E2S_CRC_SELF_MASK_IMG, 0, PKT_OPTION_SR_ALIGN_16);

static char E2S_AOD_SELF_MASK_CRC_ON[] = {
	0xD8,
	0x07, 0x10
};
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_crc_on, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_CRC_ON, 0x27);

static char E2S_AOD_SELF_MASK_DBIST_ON[] = {
	0xBF,
	0x01, 0x00, 0x30, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
};
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_dbist_on, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_DBIST_ON, 0);

static char E2S_AOD_SELF_MASK_DBIST_OFF[] = {
	0xBF,
	0x00, 0x07, 0xFF, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
};
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_dbist_off, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_DBIST_OFF, 0);

static char E2S_AOD_SELF_MASK_ENABLE_FOR_CHECKSUM[] = {
	0x7A,
	0x03, 0x00, 0x00, 0x00, 0x01, 0xf4, 0x02, 0x33,
	0x0c, 0x30, 0x0c, 0x31, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff
};

static DEFINE_STATIC_PACKET(e2s_aod_self_mask_for_checksum, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_ENABLE_FOR_CHECKSUM, 0);

static char E2S_AOD_SELF_MASK_RESTORE[] = {
	0x7A,
	0x03, 0x00, 0x00, 0x00, 0x0c, 0x30, 0x0c, 0x31,
	0x0c, 0x32, 0x0c, 0x33, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff
};
static DEFINE_STATIC_PACKET(e2s_aod_self_mask_restore, DSI_PKT_TYPE_WR, E2S_AOD_SELF_MASK_RESTORE, 0);

static void *e2s_aod_self_mask_crc_cmdtbl[] = {
	&KEYINFO(e2s_aod_l1_key_enable),
	&KEYINFO(e2s_aod_l2_key_enable),
	&KEYINFO(e2s_aod_l3_key_enable),
	&PKTINFO(e2s_aod_self_mask_crc_on),
	&PKTINFO(e2s_aod_self_mask_dbist_on),
	&PKTINFO(e2s_aod_self_mask_for_checksum),
	&DLYINFO(e2s_aod_self_mask_checksum_2frame_delay),
	&s6e3haf_dmptbl[DUMP_SELF_MASK_CRC],
	&PKTINFO(e2s_aod_self_mask_restore),
	&PKTINFO(e2s_aod_self_mask_dbist_off),
	&KEYINFO(e2s_aod_l3_key_disable),
	&KEYINFO(e2s_aod_l2_key_disable),
	&KEYINFO(e2s_aod_l1_key_disable),
};

// --------------------- end of check sum control ----------------------------

static char E2S_AOD_PARTIAL_HLPM_ON[] = { 0x85, 0x03, 0x05, 0x05, 0x08, 0x5D };
static DEFINE_STATIC_PACKET(e2s_aod_partial_hlpm_on, DSI_PKT_TYPE_WR, E2S_AOD_PARTIAL_HLPM_ON, 0);

static void *e2s_aod_partial_enable_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_partial_hlpm_on),
	&KEYINFO(e2s_aod_l2_key_enable),
};

static char E2S_AOD_PARTIAL_HLPM_OFF[] = { 0x85, 0x00, };
DEFINE_STATIC_PACKET(e2s_aod_partial_hlpm_off, DSI_PKT_TYPE_WR, E2S_AOD_PARTIAL_HLPM_OFF, 0);

static void *e2s_aod_partial_disable_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_partial_hlpm_off),
	&KEYINFO(e2s_aod_l2_key_disable),
};

static void *e2s_aod_enter_aod_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_partial_hlpm_on),
	&KEYINFO(e2s_aod_l2_key_enable),
};

static void *e2s_aod_exit_aod_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_partial_hlpm_off),
	&KEYINFO(e2s_aod_l2_key_disable),
};

static DEFINE_STATIC_PACKET_WITH_OPTION(e2s_aod_self_mask_img_pkt,
		DSI_PKT_TYPE_WR_SR_FAST, E2S_SELF_MASK_IMG, 0, PKT_OPTION_SR_ALIGN_16);

static void *e2s_aod_self_mask_img_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&PKTINFO(e2s_aod_self_mask_sd_path),
	&DLYINFO(e2s_aod_self_spsram_sel_delay),
	&CONDINFO_IF(e2s_cond_is_factory_selfmask),
		&PKTINFO(e2s_aod_self_mask_crc_img_pkt),
	&CONDINFO_EL(e2s_cond_is_factory_selfmask),
		&PKTINFO(e2s_aod_self_mask_img_pkt),
	&CONDINFO_FI(e2s_cond_is_factory_selfmask),
	&DLYINFO(e2s_aod_self_spsram_write_delay),
	&PKTINFO(e2s_aod_reset_sd_path),
	&KEYINFO(e2s_aod_l2_key_disable),
};

static void *e2s_aod_self_mask_data_check_cmdtbl[] = {
	&KEYINFO(e2s_aod_l2_key_enable),
	&CONDINFO_IF(e2s_cond_is_factory_selfmask),
		&s6e3haf_dmptbl[DUMP_SELF_MASK_FACTORY_CHECKSUM],
	&CONDINFO_EL(e2s_cond_is_factory_selfmask),
		&s6e3haf_dmptbl[DUMP_SELF_MASK_CHECKSUM],
	&CONDINFO_FI(e2s_cond_is_factory_selfmask),
	&KEYINFO(e2s_aod_l2_key_disable),
};

static struct seqinfo e2s_aod_seqtbl[] = {
	SEQINFO_INIT(SELF_MASK_IMG_SEQ, e2s_aod_self_mask_img_cmdtbl),
	SEQINFO_INIT(SELF_MASK_ENA_SEQ, e2s_aod_self_mask_ena_cmdtbl),
	SEQINFO_INIT(SELF_MASK_DIS_SEQ, e2s_aod_self_mask_dis_cmdtbl),
	SEQINFO_INIT(SELF_MASK_DATA_CHECK_SEQ, e2s_aod_self_mask_data_check_cmdtbl),
	SEQINFO_INIT(ENTER_AOD_SEQ, e2s_aod_enter_aod_cmdtbl),
	SEQINFO_INIT(EXIT_AOD_SEQ, e2s_aod_exit_aod_cmdtbl),
	SEQINFO_INIT(ENABLE_PARTIAL_SCAN_SEQ, e2s_aod_partial_enable_cmdtbl),
	SEQINFO_INIT(DISABLE_PARTIAL_SCAN_SEQ, e2s_aod_partial_disable_cmdtbl),
	SEQINFO_INIT(SELF_MASK_CRC_SEQ, e2s_aod_self_mask_crc_cmdtbl),
};

static struct aod_tune s6e3haf_e2s_aod = {
	.name = "s6e3haf_e2s_aod",
	.nr_seqtbl = ARRAY_SIZE(e2s_aod_seqtbl),
	.seqtbl = e2s_aod_seqtbl,
	.nr_maptbl = ARRAY_SIZE(e2s_aod_maptbl),
	.maptbl = e2s_aod_maptbl,
	.self_mask_en = true,
	.custom_ops = {
		.self_mask_data_check = s6e3haf_aod_self_mask_data_check,
	}
};
#endif /* __S6E3HAF_E2S_AOD_PANEL_H__ */