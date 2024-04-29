/*
 * s2mps27-private.h - Voltage regulator driver for the S2MPS27
 *
 *  Copyright (C) 2023 Samsung Electrnoics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_S2MPS27_REGULATOR_H
#define __LINUX_MFD_S2MPS27_REGULATOR_H
#include <linux/i2c.h>

#if IS_ENABLED(CONFIG_S2MPS27_ADC)
#include <linux/iio/iio.h>
#include <linux/iio/machine.h>
#include <linux/iio/driver.h>
#include <linux/iio/consumer.h>
#endif

/* Main id */
enum s2mps27_main_id{
	MAIN_ID = 0x0D,
};

/* Base address */
enum s2mps27_base_addr {
	VGPIO_ADDR = 0x00,
	COM_ADDR   = 0x03,
	RTC_ADDR   = 0x04,
	PM1_ADDR   = 0x05,
	PM2_ADDR   = 0x06,
	PM3_ADDR   = 0x07,
	ADC_ADDR   = 0x0A,
	GPIO_ADDR  = 0x0B,
	EXT_ADDR   = 0x0E,
	TEMP_ADDR  = 0x1F,
};

#define S2MPS27_REG_INVALID			(0xFF)

/* S2MPS27 VGPIO(0x00) Address */
#define S2MPS27_VGPIO_REG0			0x00
#define S2MPS27_VGPIO_PSI			0x01
#define S2MPS27_VGPIO_VGI0			0x02
#define S2MPS27_VGPIO_VGI1			0x03
#define S2MPS27_VGPIO_VGI2			0x04
#define S2MPS27_VGPIO_VGI3			0x05
#define S2MPS27_VGPIO_VGI4			0x06
#define S2MPS27_VGPIO_VGI5			0x07
#define S2MPS27_VGPIO_VGI6			0x08
#define S2MPS27_VGPIO_VGI7			0x09
#define S2MPS27_VGPIO_VGI8			0x0A
#define S2MPS27_VGPIO_VGI9			0x0B
#define S2MPS27_VGPIO_VGI10			0x0C
#define S2MPS27_VGPIO_VGI11			0x0D
#define S2MPS27_VGPIO_VGI12			0x0E
#define S2MPS27_VGPIO_VGI13			0x0F
#define S2MPS27_VGPIO_VGI14			0x10
#define S2MPS27_VGPIO_VGI15			0x11
#define S2MPS27_VGPIO_VGI16			0x12
#define S2MPS27_VGPIO_VGI17			0x13
#define S2MPS27_VGPIO_VGI18			0x14
#define S2MPS27_VGPIO_USID			0x30
#define S2MPS27_VGPIO_GSID_0			0x34
#define S2MPS27_VGPIO_GSID_1			0x35
#define S2MPS27_VGPIO_GSID_2			0x36
#define S2MPS27_VGPIO_GSID_3			0x37
#define S2MPS27_VGPIO_GSID_4			0x38
#define S2MPS27_VGPIO_GSID_5			0x39
#define S2MPS27_VGPIO_MAX_FREQ			0x40
#define S2MPS27_VGPIO_TIMEOUT_INIT_VALUE_L	0x44
#define S2MPS27_VGPIO_TIMEOUT_INIT_VALUE_H	0x45
#define S2MPS27_VGPIO_CONFIG			0x46
#define S2MPS27_VGPIO_DEBUG_0			0x50
#define S2MPS27_VGPIO_DEBUG_1			0x51
#define S2MPS27_VGPIO_DEBUG_2			0x52
#define S2MPS27_VGPIO_DEBUG_3			0x53
#define S2MPS27_VGPIO_NON_BLOCKING		0xE0
#define S2MPS27_VGPIO_VERSION_0			0xF0
#define S2MPS27_VGPIO_VERSION_1			0xF1
#define S2MPS27_VGPIO_VERSION_2			0xF2
#define S2MPS27_VGPIO_VERSION_3			0xF3

/* VGPIO TX (PMIC -> AP) table check */
#define S2MPS27_VGI1_WRSTBO			(1 << 0)
#define S2MPS27_VGI1_IRQ_S1			(1 << 1)
#define S2MPS27_VGI1_IRQ_S2			(1 << 2)
#define S2MPS27_VGI1_IRQ_EXTRA			(1 << 3)
#define S2MPS27_VGI2_IRQ_RF			(1 << 0)
#define S2MPS27_VGI2_IRQ_S3			(1 << 2)
#define S2MPS27_VGI4_IRQ_S4			(1 << 0)
#define S2MPS27_VGI4_ONOB			(1 << 1)
#define S2MPS27_VGI4_IRQ_M			(1 << 2)
#define S2MPS27_VGI4_VOL_DN			(1 << 3)
#define S2MPS27_VGI5_IRQ_S5			(1 << 0)

/* S2MPS27 COM(0x03) Address */
#define S2MPS27_COM_VGPIO_REG0_1		0x00
#define S2MPS27_COM_VGPIO_REG0_2		0x01
#define S2MPS27_COM_CHIP_ID			0x0E
#define S2MPS27_COM_PLATFORM_ID			0x0F
#define S2MPS27_COM_SPMI_CFG1			0x10
#define S2MPS27_COM_SPMI_CFG2			0x11
#define S2MPS27_COM_SPMI_CFG3			0x12
#define S2MPS27_COM_SPMI_CFG4			0x13
#define S2MPS27_COM_SPMI_CFG5			0x14
#define S2MPS27_COM_COM_CTRL1			0x15
#define S2MPS27_COM_TX_MASK			0x16
#define S2MPS27_COM_IRQ				0x17
#define S2MPS27_COM_COM_CTRL3			0x18
#define S2MPS27_COM_COM_CLK_ON			0x19
#define S2MPS27_COM_COM_CLK_OFF			0x1A
#define S2MPS27_COM_COM_OM			0x1B
#define S2MPS27_COM_COM_OTP_TEST		0x1C
#define S2MPS27_COM_COM_OTP_AW_OPT		0x1D
#define S2MPS27_COM_COM_OTP_ADRL		0x1E
#define S2MPS27_COM_COM_OTP_ADRH		0x1F
#define S2MPS27_COM_COM_OTP_DATA		0x20
#define S2MPS27_COM_COM_MONSEL1			0x21
#define S2MPS27_COM_COM_MONSEL2			0x22
#define S2MPS27_COM_COM_MONRD1			0x23
#define S2MPS27_COM_COM_MONRD2			0x24
#define S2MPS27_COM_COM_CCD			0x25
#define S2MPS27_COM_CHECKSUM_DATA		0x26
#define S2MPS27_COM_CHECKSUM_REF		0x27
#define S2MPS27_COM_CHECKSUM_RESULT		0x28
#define S2MPS27_COM_OTP_LOAD_EN_PAT		0x29
#define S2MPS27_COM_BUCK_OM			0x2A
#define S2MPS27_COM_BUCK_MON_SEL		0x2B
#define S2MPS27_COM_BUCK_MON_SEL2		0x2C
#define S2MPS27_COM_BUCK_MON_EN1		0x2D
#define S2MPS27_COM_COM_SPR_ADR_MSB1		0x50
#define S2MPS27_COM_COM_SPR_ADR_MSB2		0x51
#define S2MPS27_COM_COM_SPR_ADR1		0x52
#define S2MPS27_COM_COM_SPR_ADR2		0x53
#define S2MPS27_COM_COM_SPR_ADR3		0x54
#define S2MPS27_COM_COM_SPR_ADR4		0x55
#define S2MPS27_COM_COM_SPR_ADR5		0x56
#define S2MPS27_COM_COM_SPR_ADR6		0x57
#define S2MPS27_COM_COM_SPR_DAT1		0x58
#define S2MPS27_COM_COM_SPR_DAT2		0x59
#define S2MPS27_COM_COM_SPR_DAT3		0x5A
#define S2MPS27_COM_COM_SPR_DAT4		0x5B
#define S2MPS27_COM_COM_SPR_DAT5		0x5C
#define S2MPS27_COM_COM_SPR_DAT6		0x5D

/* CHIP ID MASK */
#define S2MPS27_CHIP_ID_MASK			(0xFF)
#define S2MPS27_CHIP_ID_HW_MASK			(0x0F)
#define S2MPS27_CHIP_ID_SW_MASK			(0xF0)

/* TX_MASK MASK */
#define S2MPS27_IRQ_TX_EN_MASK			(1 << 7)
#define S2MPS27_VOLDN_TX_ENB_MASK		(1 << 5)
#define S2MPS27_ONOB_TX_ENB_MASK		(1 << 4)
#define S2MPS27_WRSTBO_TX_ENB_MASK		(1 << 3)
#define S2MPS27_ADC_IRQM_MASK			(1 << 1)
#define S2MPS27_PM_IRQM_MASK			(1 << 0)

/* IRQ MASK */
#define S2MPS27_GPIO_IRQ			(1 << 2)
#define S2MPS27_ADC_IRQ				(1 << 1)
#define S2MPS27_PM_IRQ				(1 << 0)

/* S2MPS27 RTC(0x04) Address  */
#define S2MPS27_RTC_RTC_CTRL			0x00
#define S2MPS27_RTC_RTC_WTSR_SMPL		0x01
#define S2MPS27_RTC_RTC_UPDATE			0x02
#define S2MPS27_RTC_CAP_SEL			0x03
#define S2MPS27_RTC_RTC_MSEC			0x04
#define S2MPS27_RTC_RTC_SEC			0x05
#define S2MPS27_RTC_RTC_MIN			0x06
#define S2MPS27_RTC_RTC_HOUR			0x07
#define S2MPS27_RTC_RTC_WEEK			0x08
#define S2MPS27_RTC_RTC_DAY			0x09
#define S2MPS27_RTC_RTC_MON			0x0A
#define S2MPS27_RTC_RTC_YEAR			0x0B
#define S2MPS27_RTC_RTC_A0SEC			0x0C
#define S2MPS27_RTC_RTC_A0MIN			0x0D
#define S2MPS27_RTC_RTC_A0HOUR			0x0E
#define S2MPS27_RTC_RTC_A0WEEK			0x0F
#define S2MPS27_RTC_RTC_A0DAY			0x10
#define S2MPS27_RTC_RTC_A0MON			0x11
#define S2MPS27_RTC_RTC_A0YEAR			0x12
#define S2MPS27_RTC_RTC_A1SEC			0x13
#define S2MPS27_RTC_RTC_A1MIN			0x14
#define S2MPS27_RTC_RTC_A1HOUR			0x15
#define S2MPS27_RTC_RTC_A1WEEK			0x16
#define S2MPS27_RTC_RTC_A1DAY			0x17
#define S2MPS27_RTC_RTC_A1MON			0x18
#define S2MPS27_RTC_RTC_A1YEAR			0x19
#define S2MPS27_RTC_RTC_OSC_CTRL		0x1A
#define S2MPS27_RTC_SECURE_CNT1			0x1B
#define S2MPS27_RTC_SECURE_CNT2			0x1C
#define S2MPS27_RTC_SECURE_CNT3			0x1D
#define S2MPS27_RTC_SECURE_CNT4			0x1E
#define S2MPS27_RTC_RTC_DEBUG1			0x1F
#define S2MPS27_RTC_RTC_DEBUG2			0x20
#define S2MPS27_RTC_RTC_DEBUG3			0x21
#define S2MPS27_RTC_RTC_RCO_TRIM		0x22
#define S2MPS27_RTC_RTC_SECURE1			0x23
#define S2MPS27_RTC_RTC_SECURE2			0x24
#define S2MPS27_RTC_RTC_SECURE3			0x25
#define S2MPS27_RTC_RTC_SECURE4			0x26
#define S2MPS27_RTC_RTC_WDT			0x27
#define S2MPS27_RTC_RTC_TEST			0x28

/* S2MPS27 PM1(0x05) Address */
#define S2MPS27_PM1_INT1			0x00
#define S2MPS27_PM1_INT2			0x01
#define S2MPS27_PM1_INT3			0x02
#define S2MPS27_PM1_INT4			0x03
#define S2MPS27_PM1_INT5			0x04
#define S2MPS27_PM1_INT1M			0x05
#define S2MPS27_PM1_INT2M			0x06
#define S2MPS27_PM1_INT3M			0x07
#define S2MPS27_PM1_INT4M			0x08
#define S2MPS27_PM1_INT5M			0x09
#define S2MPS27_PM1_STATUS1			0x0A
#define S2MPS27_PM1_STATUS2			0x0B
#define S2MPS27_PM1_PWRONSRC1			0x0C
#define S2MPS27_PM1_PWRONSRC2			0x0D
#define S2MPS27_PM1_OFFSRC1_CUR			0x0E
#define S2MPS27_PM1_OFFSRC2_CUR			0x0F
#define S2MPS27_PM1_OFFSRC1_OLD1		0x10
#define S2MPS27_PM1_OFFSRC2_OLD1		0x11
#define S2MPS27_PM1_OFFSRC1_OLD2		0x12
#define S2MPS27_PM1_OFFSRC2_OLD2		0x13
#define S2MPS27_PM1_BU_CHG			0x17
#define S2MPS27_PM1_RTC_BUF			0x18
#define S2MPS27_PM1_CTRL1			0x19
#define S2MPS27_PM1_CTRL2			0x1A
#define S2MPS27_PM1_CTRL3			0x1B
#define S2MPS27_PM1_ETC_OTP1			0x1C
#define S2MPS27_PM1_ETC_OTP2			0x1D
#define S2MPS27_PM1_UVLO_OTP			0x1E
#define S2MPS27_PM1_CFG_PM			0x1F
#define S2MPS27_PM1_TIME_CTRL			0x20
#define S2MPS27_PM1_BUCK_SR1_CTRL		0x21
#define S2MPS27_PM1_BUCK_SR1_OUT1		0x22
#define S2MPS27_PM1_BUCK_SR1_OUT2		0x23
#define S2MPS27_PM1_BUCK_SR1_DVS		0x24
#define S2MPS27_PM1_BUCK_SR1_OCP		0x25
#define S2MPS27_PM1_BB_CTRL			0x26
#define S2MPS27_PM1_BB_OUT1			0x27
#define S2MPS27_PM1_BB_OUT2			0x28
#define S2MPS27_PM1_BB_DVS1			0x29
#define S2MPS27_PM1_BB_DVS2			0x2A
#define S2MPS27_PM1_BB_OCP			0x2B
#define S2MPS27_PM1_LDO1_CTRL			0x2C
#define S2MPS27_PM1_LDO2_CTRL			0x2D
#define S2MPS27_PM1_LDO3_CTRL			0x2E
#define S2MPS27_PM1_LDO4_CTRL			0x2F
#define S2MPS27_PM1_LDO5_CTRL			0x30
#define S2MPS27_PM1_LDO6_CTRL			0x31
#define S2MPS27_PM1_LDO7_CTRL			0x32
#define S2MPS27_PM1_LDO8_CTRL			0x33
#define S2MPS27_PM1_LDO9_CTRL			0x34
#define S2MPS27_PM1_LDO10_CTRL			0x35
#define S2MPS27_PM1_LDO11_CTRL			0x36
#define S2MPS27_PM1_LDO12_CTRL			0x37
#define S2MPS27_PM1_LDO13_CTRL			0x38
#define S2MPS27_PM1_LDO14_CTRL			0x39
#define S2MPS27_PM1_LDO15_CTRL			0x3A
#define S2MPS27_PM1_LDO16_CTRL			0x3B
#define S2MPS27_PM1_LDO17_CTRL			0x3C
#define S2MPS27_PM1_LDO18_CTRL			0x3D
#define S2MPS27_PM1_LDO_DSCH1			0x3E
#define S2MPS27_PM1_LDO_DSCH2			0x3F
#define S2MPS27_PM1_LDO_DSCH3			0x40
#define S2MPS27_PM1_LDO_DSCH4			0x41
#define S2MPS27_PM1_GPIO_SEQ_CTRL		0x42
#define S2MPS27_PM1_WRST_CTRL1			0x43
#define S2MPS27_PM1_WRST_CTRL2			0x44
#define S2MPS27_PM1_WRST_CTRL3			0x45
#define S2MPS27_PM1_EXT_CTRL5			0xFA
#define S2MPS27_PM1_EXT_PWRHOLD			0xFB
#define S2MPS27_PM1_EXT_CTRL2			0xFD
#define S2MPS27_PM1_EXT_CTRL3			0xFE
#define S2MPS27_PM1_EXT_CTRL1			0xFF

/* S2MPS27 PM2(0x06) Address */
#define S2MPS27_PM2_ONSEQ_CTRL1			0x00
#define S2MPS27_PM2_ONSEQ_CTRL2			0x01
#define S2MPS27_PM2_ONSEQ_CTRL3			0x02
#define S2MPS27_PM2_ONSEQ_CTRL4			0x03
#define S2MPS27_PM2_ONSEQ_CTRL5			0x04
#define S2MPS27_PM2_ONSEQ_CTRL6			0x05
#define S2MPS27_PM2_ONSEQ_CTRL7			0x06
#define S2MPS27_PM2_ONSEQ_CTRL8			0x07
#define S2MPS27_PM2_ONSEQ_CTRL9			0x08
#define S2MPS27_PM2_ONSEQ_CTRL10		0x09
#define S2MPS27_PM2_ONSEQ_CTRL11		0x0A
#define S2MPS27_PM2_ONSEQ_CTRL12		0x0B
#define S2MPS27_PM2_ONSEQ_CTRL13		0x0C
#define S2MPS27_PM2_ONSEQ_CTRL14		0x0D
#define S2MPS27_PM2_ONSEQ_CTRL15		0x0E
#define S2MPS27_PM2_ONSEQ_CTRL16		0x0F
#define S2MPS27_PM2_ONSEQ_CTRL17		0x10
#define S2MPS27_PM2_ONSEQ_CTRL18		0x11
#define S2MPS27_PM2_ONSEQ_CTRL19		0x12
#define S2MPS27_PM2_ONSEQ_CTRL20		0x13
#define S2MPS27_PM2_ONSEQ_CTRL21		0x14
#define S2MPS27_PM2_OFF_SEQ_CTRL1		0x15
#define S2MPS27_PM2_OFF_SEQ_CTRL2		0x16
#define S2MPS27_PM2_OFF_SEQ_CTRL3		0x17
#define S2MPS27_PM2_OFF_SEQ_CTRL4		0x18
#define S2MPS27_PM2_OFF_SEQ_CTRL5		0x19
#define S2MPS27_PM2_OFF_SEQ_CTRL6		0x1A
#define S2MPS27_PM2_OFF_SEQ_CTRL7		0x1B
#define S2MPS27_PM2_OFF_SEQ_CTRL8		0x1C
#define S2MPS27_PM2_OFF_SEQ_CTRL9		0x1D
#define S2MPS27_PM2_OFF_SEQ_CTRL10		0x1E
#define S2MPS27_PM2_OFF_SEQ_CTRL11		0x1F
#define S2MPS27_PM2_M_SEL_VGPIO1		0x20
#define S2MPS27_PM2_M_SEL_VGPIO2		0x21
#define S2MPS27_PM2_M_SEL_VGPIO3		0x22
#define S2MPS27_PM2_M_SEL_VGPIO4		0x23
#define S2MPS27_PM2_M_SEL_VGPIO5		0x24
#define S2MPS27_PM2_M_SEL_VGPIO6		0x25
#define S2MPS27_PM2_M_SEL_VGPIO7		0x26
#define S2MPS27_PM2_M_SEL_VGPIO8		0x27
#define S2MPS27_PM2_M_SEL_VGPIO9		0x28
#define S2MPS27_PM2_M_SEL_VGPIO10		0x29
#define S2MPS27_PM2_M_SEL_VGPIO11		0x2A
#define S2MPS27_PM2_M_SEL_VGPIO12		0x2B
#define S2MPS27_PM2_M_SEL_VGPIO13		0x2C
#define S2MPS27_PM2_M_SEL_VGPIO14		0x2D
#define S2MPS27_PM2_M_SEL_VGPIO15		0x2E
#define S2MPS27_PM2_M_SEL_VGPIO16		0x2F
#define S2MPS27_PM2_M_SEL_VGPIO17		0x30
#define S2MPS27_PM2_M_SEL_VGPIO18		0x31
#define S2MPS27_PM2_M_SEL_VGPIO19		0x32
#define S2MPS27_PM2_M_SEL_VGPIO20		0x33
#define S2MPS27_PM2_M_SEL_VGPIO21		0x34
#define S2MPS27_PM2_M_SEL_DVS_EN1		0x35
#define S2MPS27_PM2_OFF_CTRL1			0x36
#define S2MPS27_PM2_OFF_CTRL2			0x37
#define S2MPS27_PM2_OFF_CTRL3			0x38
#define S2MPS27_PM2_OFF_CTRL4			0x39
#define S2MPS27_PM2_OFF_CTRL5			0x3A
#define S2MPS27_PM2_OFF_CTRL6			0x3B
#define S2MPS27_PM2_OFF_CTRL7			0x3C
#define S2MPS27_PM2_CFG_PM1			0x3D
#define S2MPS27_PM2_CFG_PM2			0x3E
#define S2MPS27_PM2_CFG_PM3			0x3F
#define S2MPS27_PM2_CFG_PM4			0x40
#define S2MPS27_PM2_CFG_PM5			0x41
#define S2MPS27_PM2_CFG_PM6			0x42
#define S2MPS27_PM2_LDO_OI_CTRL1		0x43
#define S2MPS27_PM2_LDO_OI_CTRL2		0x44
#define S2MPS27_PM2_LDO_OI_CTRL3		0x45
#define S2MPS27_PM2_LDO_OI_CTRL4		0x46
#define S2MPS27_PM2_OI_OVP_CTRL			0x47
#define S2MPS27_PM2_OVP_CTRL2			0x48
#define S2MPS27_PM2_IPTAT			0x49
#define S2MPS27_PM2_DCXO_CTRL1			0x4A
#define S2MPS27_PM2_DCXO_CTRL2			0x4B
#define S2MPS27_PM2_DCXO_CTRL3			0x4C
#define S2MPS27_PM2_VGPIO_REG0_0		0xE0
#define S2MPS27_PM2_VGPIO_REG0_1		0xE1
#define S2MPS27_PM2_VGPIO2			0xE2
#define S2MPS27_PM2_VGPIO3			0xE3
#define S2MPS27_PM2_VGPIO4			0xE4
#define S2MPS27_PM2_VGPIO5			0xE5
#define S2MPS27_PM2_VGPIO6			0xE6
#define S2MPS27_PM2_VGPIO7			0xE7
#define S2MPS27_PM2_VGPIO8			0xE8
#define S2MPS27_PM2_VGPIO9			0xE9
#define S2MPS27_PM2_VGPIO18			0xEA
#define S2MPS27_PM2_VGPIO19			0xEB
#define S2MPS27_PM2_VGPIO20			0xEC

/* S2MPS27 PM3(0x07) Address */
#define S2MPS27_PM3_SEQ_CTRL1			0x00
#define S2MPS27_PM3_SEQ_CTRL2			0x01
#define S2MPS27_PM3_SEQ_CTRL3			0x02
#define S2MPS27_PM3_SEQ_CTRL4			0x03
#define S2MPS27_PM3_SEQ_CTRL5			0x04
#define S2MPS27_PM3_PSI_CTRL1			0x05
#define S2MPS27_PM3_PSI_CTRL2			0x06
#define S2MPS27_PM3_PSI_CTRL3			0x07
#define S2MPS27_PM3_PSI_CTRL4			0x08
#define S2MPS27_PM3_PSI_CTRL5			0x09
#define S2MPS27_PM3_PSI_CTRL6			0x0A
#define S2MPS27_PM3_TEST_CTRL1			0x0B
#define S2MPS27_PM3_TEST_CTRL2			0x0C
#define S2MPS27_PM3_TEST_CTRL3			0x0D
#define S2MPS27_PM3_TEST_CTRL4			0x0E
#define S2MPS27_PM3_TEST_CTRL5			0x0F
#define S2MPS27_PM3_TEST_CTRL6			0x10
#define S2MPS27_PM3_PROT_CTRL			0x11
#define S2MPS27_PM3_DUMP_CTRL1			0x12
#define S2MPS27_PM3_DUMP_CTRL2			0x13
#define S2MPS27_PM3_PSI_OFF_SRC			0x14
#define S2MPS27_PM3_DEBUG_IRQ1			0x20
#define S2MPS27_PM3_DEBUG_IRQ2			0x21

/* S2MPS27 ADC(0x0A) Address */
#define S2MPS27_ADC_ADC_INTP			0x00
#define S2MPS27_ADC_ADC_INTM			0x01
#define S2MPS27_ADC_ADC_STATUS			0x02
#define S2MPS27_ADC_ADC_CTRL1			0x03
#define S2MPS27_ADC_ADC_CTRL2			0x04
#define S2MPS27_ADC_ADC_CTRL3			0x05
#define S2MPS27_ADC_ADC_CTRL4			0x06
#define S2MPS27_ADC_ADC_CTRL5			0x07
#define S2MPS27_ADC_AVG_NUM_SET			0x08
#define S2MPS27_ADC_PERIOD_CTRL			0x09
#define S2MPS27_ADC_NTC_MUX_SEL			0x0A
#define S2MPS27_ADC_GPADC_MUX_SEL		0x0B
#define S2MPS27_ADC_NTC_TH_CTRL0		0x0C
#define S2MPS27_ADC_NTC_TH_CTRL1		0x0D
#define S2MPS27_ADC_NTC_TH_CTRL2		0x0E
#define S2MPS27_ADC_NTC_TH_CTRL3		0x0F
#define S2MPS27_ADC_NTC0_DATA_L			0x10
#define S2MPS27_ADC_NTC0_DATA_H			0x11
#define S2MPS27_ADC_NTC1_DATA_L			0x12
#define S2MPS27_ADC_NTC1_DATA_H			0x13
#define S2MPS27_ADC_GPADC_DATA_L		0x14
#define S2MPS27_ADC_GPADC_DATA_H		0x15
#define S2MPS27_ADC_ADC_CONFIG			0x16
#define S2MPS27_ADC_ADC_TEST			0x17

/* S2MPS27 GPIO(0x0B) Address */
#define S2MPS27_GPIO_GPIO0_SET			0x00
#define S2MPS27_GPIO_GPIO1_SET			0x01
#define S2MPS27_GPIO_GPIO2_SET			0x02
#define S2MPS27_GPIO_GPIO3_SET			0x03
#define S2MPS27_GPIO_GPIO4_SET			0x04
#define S2MPS27_GPIO_GPIO5_SET			0x05
#define S2MPS27_GPIO_GPIO_MODE1			0x06
#define S2MPS27_GPIO_GPIO_MODE2			0x07
#define S2MPS27_GPIO_GPIO_CFG			0x08
#define S2MPS27_GPIO_GPIO_IRQ1			0x10
#define S2MPS27_GPIO_GPIO_IRQ2			0x11
#define S2MPS27_GPIO_GPIO_IRQM1			0x12
#define S2MPS27_GPIO_GPIO_IRQM2			0x13
#define S2MPS27_GPIO_GPIO_STATUS		0x14
#define S2MPS27_GPIO_GPIO_PO_STATUS		0x15

/* PMIC 1 mask */
#define BUCK_RAMP_MASK				(0x03)
#define BUCK_RAMP_UP_SHIFT			6
#define SMPLWARN_LEVEL_SHIFT			5
#define SMPLWARN_LEVEL_MASK			(0x7 << SMPLWARN_LEVEL_SHIFT)

/* S2MPS27 regulator ids */
enum s2mps27_regulators{
	S2MPS27_BUCK_SR1,
	S2MPS27_BB,
	S2MPS27_LDO1,
	S2MPS27_LDO2,
	S2MPS27_LDO3,
	S2MPS27_LDO4,
	S2MPS27_LDO5,
	S2MPS27_LDO6,
	S2MPS27_LDO7,
	S2MPS27_LDO8,
	S2MPS27_LDO9,
	S2MPS27_LDO10,
	S2MPS27_LDO11,
	S2MPS27_LDO12,
	S2MPS27_LDO13,
	S2MPS27_LDO14,
	S2MPS27_LDO15,
	S2MPS27_LDO16,
	S2MPS27_LDO17,
	S2MPS27_LDO18,
	S2MPS27_REG_MAX,
};

#define S2MPS27_REGULATOR_MAX	(S2MPS27_REG_MAX)

#define S2MPS27_INST_ACOK_EN	(1 << 2)
#define S2MPS27_JIG_REBOOT_EN	(1 << 7)

/* BUCK_SR1M */
#define S2MPS27_BUCK_MIN1	700000
#define S2MPS27_BUCK_STEP1	6250
/* BUCK_BOOST*/
#define S2MPS27_BB_MIN		2600000
#define S2MPS27_BB_STEP		12500
/* (IV_PMOS) LDOs 1M/2M/3M/4M/5M/7M/12M/13M/14M/15M/16M/17M/18M */
#define S2MPS27_LDO_MIN1	1500000
#define S2MPS27_LDO_STEP1	12500
/* (MV_PMOS) LDO 6M - skip on PMIC EVT0.0 */
#define S2MPS27_LDO_MIN2	700000
#define S2MPS27_LDO_STEP2	25000
/* (MV_PMOS) LDOs 8M/9M/10M/11M */
#define S2MPS27_LDO_MIN3	1800000
#define S2MPS27_LDO_STEP3	25000

/* LDO/BUCK output voltage control */
#define S2MPS27_LDO_VSEL_MASK	0x3F	/* LDO_CTRL */
#define S2MPS27_BUCK_VSEL_MASK	0xFF	/* BUCK_SR1_OUT1,2 */
#define S2MPS27_BB_VSEL_MASK	0x7F    /* BUCK_BOOST_OUT1,2 */

/* BUCK_SR1/BB/LDO Enable Control [7:6] */
#define S2MPS27_ENABLE_SHIFT	6
#define S2MPS27_ENABLE_MASK	(0x3 << S2MPS27_ENABLE_SHIFT)

/* BUCK_SR1/BB Mode Control [3:2] */
#define S2MPS27_BUCK_MODE_SHIFT		2
#define S2MPS27_BUCK_MODE_MASK		0x0C
#define S2MPS27_BUCK_AUTO_MODE		(0x02 << S2MPS27_BUCK_MODE_SHIFT)
#define S2MPS27_BUCK_FCCM_MODE		(0x03 << S2MPS27_BUCK_MODE_SHIFT)

/* soft start time */
#define S2MPS27_ENABLE_TIME_LDO		120
#define S2MPS27_ENABLE_TIME_BUCK	120
#define S2MPS27_ENABLE_TIME_BB		120

/* POWER-KEY MASK */
#define S2MPS27_STATUS1_PWRON	(1 << 0)
#define S2MPS27_PWRKEY_PRESS	(1 << 1)
#define S2MPS27_PWRKEY_RELEASE 	(1 << 0)

/* VOL-DOWN-KEY MASK */
#define S2MPS27_STATUS1_MR1B	(1 << 4)
#define S2MPS27_VOLDN_PRESS	(1 << 7)
#define S2MPS27_VOLDN_RELEASE	(1 << 6)

enum s2mps27_irq_source {
	S2MPS27_PMIC_INT1 = 0,
	S2MPS27_PMIC_INT2,
	S2MPS27_PMIC_INT3,
	S2MPS27_PMIC_INT4,
	S2MPS27_PMIC_INT5,
	S2MPS27_ADC_INTP,
	S2MPS27_IRQ_GROUP_NR,
};

#define S2MPS27_NUM_IRQ_ADC_REGS	1
#define S2MPS27_NUM_IRQ_PMIC_REGS	5
#define S2MPS27_BUCK_MAX		2
#define S2MPS27_TEMP_MAX		2
#define S2MPS27_LDO_OI_MAX		6

enum s2mps27_irq{
	/* PMIC */
	S2MPS27_PMIC_IRQ_PWRONR_INT1,
	S2MPS27_PMIC_IRQ_PWRONP_INT1,
	S2MPS27_PMIC_IRQ_JIGONBF_INT1,
	S2MPS27_PMIC_IRQ_JIGONBR_INT1,
	S2MPS27_PMIC_IRQ_ACOKBF_INT1,
	S2MPS27_PMIC_IRQ_ACOKBR_INT1,
	S2MPS27_PMIC_IRQ_PWRON1S_INT1,
	S2MPS27_PMIC_IRQ_MRB_INT1,

	S2MPS27_PMIC_IRQ_RTC60S_INT2,
	S2MPS27_PMIC_IRQ_RTCA1_INT2,
	S2MPS27_PMIC_IRQ_RTCA0_INT2,
	S2MPS27_PMIC_IRQ_SMPL_INT2,
	S2MPS27_PMIC_IRQ_RTC1S_INT2,
	S2MPS27_PMIC_IRQ_WTSR_INT2,
	S2MPS27_PMIC_IRQ_SPMI_LDO_OK_FAIL_INT2,
	S2MPS27_PMIC_IRQ_WRSTB_INT2,

	S2MPS27_PMIC_IRQ_INT120C_INT3,
	S2MPS27_PMIC_IRQ_INT140C_INT3,
	S2MPS27_PMIC_IRQ_TSD_INT3,
	S2MPS27_PMIC_IRQ_OVP_INT3,
	S2MPS27_PMIC_IRQ_TX_TRAN_FAIL_INT3,
	S2MPS27_PMIC_IRQ_OTP_CSUM_ERR_INT3,
	S2MPS27_PMIC_IRQ_VOLDNR_INT3,
	S2MPS27_PMIC_IRQ_VOLDNP_INT3,

	S2MPS27_PMIC_IRQ_OCP_SR1_INT4,
	S2MPS27_PMIC_IRQ_OCP_BB1_INT4,
	S2MPS27_PMIC_IRQ_OI_SR1_INT4,
	S2MPS27_PMIC_IRQ_OI_BB1_INT4,
	S2MPS27_PMIC_IRQ_PARITY_ERR0_INT4,
	S2MPS27_PMIC_IRQ_PARITY_ERR1_INT4,
	S2MPS27_PMIC_IRQ_PARITY_ERR2_INT4,
	S2MPS27_PMIC_IRQ_PARITY_ERR3_INT4,

	S2MPS27_PMIC_IRQ_OI_L1_INT5,
	S2MPS27_PMIC_IRQ_OI_L7_INT5,
	S2MPS27_PMIC_IRQ_OI_L8_INT5,
	S2MPS27_PMIC_IRQ_OI_L9_INT5,
	S2MPS27_PMIC_IRQ_OI_L10_INT5,
	S2MPS27_PMIC_IRQ_OI_L11_INT5,
	S2MPS27_PMIC_IRQ_WDT_INT5,

//	S2MPS27_ADC_IRQ_NTC0_OVER_INTP,
//	S2MPS27_ADC_IRQ_NTC1_OVER_INTP,

	S2MPS27_IRQ_NR,
};

enum sec_device_type {
	S2MPS27X,
};

struct s2mps27_dev {
	struct device *dev;
	struct s2mps27_platform_data *pdata;
	struct i2c_client *com;
	struct i2c_client *vgpio;
	struct i2c_client *rtc;
	struct i2c_client *pm1;
	struct i2c_client *pm2;
	struct i2c_client *pm3;
	struct i2c_client *adc;
	struct i2c_client *gpio;
	struct i2c_client *ext;
	struct mutex i2c_lock;
	struct mutex irqlock;

	bool wakeup;
	bool jig_reboot_en;
	bool inst_acok_en;
	int type;
	int device_type;

	/* IRQ */
	int irq;
	int irq_base;
	int irq_masks_cur[S2MPS27_IRQ_GROUP_NR];
	int irq_masks_cache[S2MPS27_IRQ_GROUP_NR];

	/* pmic VER/REV register */
	uint8_t pmic_rev;	/* pmic Rev */

	struct adc_info *adc_meter;
	int adc_mode;

#if IS_ENABLED(CONFIG_SEC_PM)
	struct device *ap_pmic_dev;
#endif /* CONFIG_SEC_PM */

	/* VGPIO_RX_MONITOR */
	void __iomem *mem_base;
	void __iomem *mem_base2;

	/* VGPIO_SYSREG */
	void __iomem *sysreg_vgpio2ap;
	void __iomem *sysreg_vgpio2pmu;

	/* Work queue */
	struct workqueue_struct *irq_wqueue;
	struct delayed_work irq_work;
};


enum s2mps27_types {
	TYPE_S2MPS27,
};

/* TODO : function definition */
//extern int s2mps27_adc_set_enable(struct adc_info *adc_meter, int en);

extern int s2mps27_irq_init(struct s2mps27_dev *s2mps27);
extern void s2mps27_irq_exit(struct s2mps27_dev *s2mps27);

/* S2MPS27 shared i2c API function */
extern int s2mps27_read_reg(struct i2c_client *i2c, uint8_t reg, uint8_t *dest);
extern int s2mps27_bulk_read(struct i2c_client *i2c, uint8_t reg, int count, uint8_t *buf);
extern int s2mps27_write_reg(struct i2c_client *i2c, uint8_t reg, uint8_t value);
extern int s2mps27_bulk_write(struct i2c_client *i2c, uint8_t reg, int count, uint8_t *buf);
extern int s2mps27_update_reg(struct i2c_client *i2c, uint8_t reg, uint8_t val, uint8_t mask);
extern int pmic_read_pwrkey_status(void);
extern int pmic_read_vol_dn_key_status(void);

#if IS_ENABLED(CONFIG_MFD_S2MPS28)
extern void s2mps28_1_call_notifier(void);
extern void s2mps28_2_call_notifier(void);
extern void s2mps28_3_call_notifier(void);
extern void s2mps28_4_call_notifier(void);
extern void s2mps28_5_call_notifier(void);
#endif
#if IS_ENABLED(CONFIG_MFD_S2MPA05_9945)
extern void s2mpa05_call_notifier(void);
#endif
#endif /* __LINUX_MFD_S2MPS27_REGULATOR_H */
