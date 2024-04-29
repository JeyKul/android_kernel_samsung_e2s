/*****************************************************************************
 *
 * Copyright (c) 2012 - 2022 Samsung Electronics Co., Ltd. All rights reserved
 *
 *****************************************************************************/
#ifndef __SLSI_CHANNELS_H__
#define __SLSI_CHANNELS_H__

#define SLSI_NUM_2P4GHZ_CHANNELS 14
#ifdef CONFIG_SCSC_UNII4
#define SLSI_NUM_5GHZ_CHANNELS 28
#else
#define SLSI_NUM_5GHZ_CHANNELS 25
#endif

#define SLSI_2P4GHZ_MIN_FREQ 2412
#define SLSI_2P4GHZ_MAX_FREQ 2484
#define SLSI_5GHZ_MIN_FREQ 5180
#ifdef CONFIG_SCSC_UNII4
#define SLSI_5GHZ_MAX_FREQ 5885
#define SLSI_5GHZ_LAST_CHAN 177
#else
#define SLSI_5GHZ_MAX_FREQ 5825
#define SLSI_5GHZ_LAST_CHAN 165
#endif

#define SLSI_6GHZ_LAST_CHAN 233
#define SLSI_NUM_6GHZ_CHANNELS 60
#define SLSI_NUM_6GHZ_UNII5_6 30

#define SLSI_6GHZ_MIN_FREQ 5935
#define SLSI_6GHZ_MAX_FREQ 7115
#define SLSI_6GHZ_40MHz_IDX_2_CHAN(i) ((i) * 16 + 3)
#define SLSI_6GHZ_80MHz_IDX_2_CHAN(i) ((i) * 16 + 7)
#define SLSI_6GHZ_160MHz_IDX_2_CHAN(i) ((i) * 32 + 15)
#define SLSI_6GHZ_40MHz_80MHz_MAX_CH_NUM 14
#define SLSI_6GHZ_160MHz_MAX_CH_NUM 7

#define SLSI_160MHz_CH_NUM 8
#define SLSI_80MHz_CH_NUM 4
#define SLSI_40MHz_CH_NUM 2

/* Table E-4 in IEEE Std 802.11-2012 - Global operating classes */
#define SLSI_2P4GHZ_SUPP_OP_CLASS_MIN 81
#define SLSI_2P4GHZ_SUPP_OP_CLASS_MAX 84
#define SLSI_5GHZ_SUPP_OP_CLASS_MIN 115
#define SLSI_5GHZ_SUPP_OP_CLASS_MAX 130
#define SLSI_6GHZ_SUPP_OP_CLASS_MIN 131
#define SLSI_6GHZ_SUPP_OP_CLASS_MAX 136

#ifdef CONFIG_SCSC_WLAN_SUPPORT_6G
#define SLSI_MAX_CHAN_VALUE_ACS (SLSI_NUM_2P4GHZ_CHANNELS + SLSI_NUM_5GHZ_CHANNELS + SLSI_NUM_6GHZ_CHANNELS)
#else
#define SLSI_MAX_CHAN_VALUE_ACS (SLSI_NUM_2P4GHZ_CHANNELS + SLSI_NUM_5GHZ_CHANNELS)
#endif

/* ISM(2.4GHz), UNII1, UNII2a, UNII2c, UNII3, UNII4, UNII5(6GHz)*/
#define SLSI_MAX_SUB_BANDS 7
#ifdef CONFIG_SCSC_WLAN_WIFI_SHARING
#define SLSI_2P4GHZ_CHANNEL_ONE 2412
#endif
#ifdef CONFIG_SCSC_WLAN_SUPPORT_6G
#define SLSI_MAX_SUPPORTED_CHANNELS_NUM (SLSI_NUM_2P4GHZ_CHANNELS + SLSI_NUM_5GHZ_CHANNELS + SLSI_NUM_6GHZ_CHANNELS)
#else
#define SLSI_MAX_SUPPORTED_CHANNELS_NUM (SLSI_NUM_2P4GHZ_CHANNELS + SLSI_NUM_5GHZ_CHANNELS)
#endif

#define SLSI_ROAMING_CHANNELS_MAX SLSI_MAX_SUPPORTED_CHANNELS_NUM

#endif