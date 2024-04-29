/*
 * drivers/media/platform/exynos/mfc/mfc_format.h
 *
 * Copyright (c) 2021 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __MFC_FORMAT_H
#define __MFC_FORMAT_H __FILE__

#define MFC_NUM_FORMATS ARRAY_SIZE(mfc_formats)

static struct mfc_fmt mfc_formats[] = {
	{
		.name = "Unknown",
		.fourcc = 0,
		.codec_mode = 0,
		.type = 0,
		.num_planes = 0,
		.mem_planes = 0,
	},
	{
		.name = "YUV420M",
		.fourcc = V4L2_PIX_FMT_YUV420M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 3,
		.mem_planes = 3,
	},
	{
		.name = "YUV420N",
		.fourcc = V4L2_PIX_FMT_YUV420N,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 3,
		.mem_planes = 1,
	},
	{
		.name = "YVU420M",
		.fourcc = V4L2_PIX_FMT_YVU420M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 3,
		.mem_planes = 3,
	},
	{
		.name = "NV12M",
		.fourcc = V4L2_PIX_FMT_NV12M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N",
		.fourcc = V4L2_PIX_FMT_NV12N,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M 8+2 10bit",
		.fourcc = V4L2_PIX_FMT_NV12M_S10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N 8+2 10bit",
		.fourcc = V4L2_PIX_FMT_NV12N_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M P010 10bit",
		.fourcc = V4L2_PIX_FMT_NV12M_P010,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N P010 10bit single",
		.fourcc = V4L2_PIX_FMT_NV12N_P010,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV21M",
		.fourcc = V4L2_PIX_FMT_NV21M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV21M 8+2 10bit",
		.fourcc = V4L2_PIX_FMT_NV21M_S10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV21M P010 10bit",
		.fourcc = V4L2_PIX_FMT_NV21M_P010,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 8bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWC_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 10bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWC_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV21M 8bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV21M_SBWC_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV21M 10bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV21M_SBWC_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N 8bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWC_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12N 8bit SBWC256",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWC_256_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12N 10bit SBWC",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWC_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12N 10bit SBWC256",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWC_256_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWC,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M 8bit SBWCL",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCL,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 10bit SBWCL",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCL,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N 8bit SBWCL",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCL,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "Nv12N 10bit SBWCL",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCL,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M 8bit SBWCL32",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_32_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 10bit SBWCL32",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_32_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N 8bit SBWCL32",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_32_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12N 10bit SBWCL32",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_32_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M 8bit SBWCL64",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_64_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 10bit SBWCL64",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_64_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12N 8bit SBWCL64",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_64_8B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12N 10bit SBWCL64",
		.fourcc = V4L2_PIX_FMT_NV12N_SBWCL_64_10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLH,
		.num_planes = 2,
		.mem_planes = 1,
	},
	{
		.name = "NV12M 8bit SBWCL64 FR",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_64_8B_FR,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLHFR,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV12M 10bit SBWCL64 FR",
		.fourcc = V4L2_PIX_FMT_NV12M_SBWCL_64_10B_FR,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_SBWCLHFR,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV16M",
		.fourcc = V4L2_PIX_FMT_NV16M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV61M",
		.fourcc = V4L2_PIX_FMT_NV61M,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV16M 8+2 10bit",
		.fourcc = V4L2_PIX_FMT_NV16M_S10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV61M 8+2 10bit",
		.fourcc = V4L2_PIX_FMT_NV61M_S10B,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV16M P210 10bit",
		.fourcc = V4L2_PIX_FMT_NV16M_P210,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "NV61M P210 10bit",
		.fourcc = V4L2_PIX_FMT_NV61M_P210,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_10BIT | MFC_FMT_422,
		.num_planes = 2,
		.mem_planes = 2,
	},
	{
		.name = "RGB888 24bpp",
		.fourcc = V4L2_PIX_FMT_RGB24,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "RGB565 16bpp",
		.fourcc = V4L2_PIX_FMT_RGB565,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "RGBX8888 32bpp",
		.fourcc = V4L2_PIX_FMT_RGB32X,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "BGRA8888 32bpp",
		.fourcc = V4L2_PIX_FMT_BGR32,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ARGB8888 32bpp",
		.fourcc = V4L2_PIX_FMT_ARGB32,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "RGB8888 32bpp",
		.fourcc = V4L2_PIX_FMT_RGB32,
		.codec_mode = MFC_FORMATS_NO_CODEC,
		.type = MFC_FMT_FRAME | MFC_FMT_RGB,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC H264",
		.fourcc = V4L2_PIX_FMT_H264,
		.codec_mode = MFC_REG_CODEC_H264_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC H264/MVC",
		.fourcc = V4L2_PIX_FMT_H264_MVC,
		.codec_mode = MFC_REG_CODEC_H264_MVC_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC H263",
		.fourcc = V4L2_PIX_FMT_H263,
		.codec_mode = MFC_REG_CODEC_H263_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC MPEG1",
		.fourcc = V4L2_PIX_FMT_MPEG1,
		.codec_mode = MFC_REG_CODEC_MPEG2_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC MPEG2",
		.fourcc = V4L2_PIX_FMT_MPEG2,
		.codec_mode = MFC_REG_CODEC_MPEG2_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC MPEG4",
		.fourcc = V4L2_PIX_FMT_MPEG4,
		.codec_mode = MFC_REG_CODEC_MPEG4_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC FIMV",
		.fourcc = V4L2_PIX_FMT_FIMV,
		.codec_mode = MFC_REG_CODEC_MPEG4_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC FIMV1",
		.fourcc = V4L2_PIX_FMT_FIMV1,
		.codec_mode = MFC_REG_CODEC_FIMV1_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC FIMV2",
		.fourcc = V4L2_PIX_FMT_FIMV2,
		.codec_mode = MFC_REG_CODEC_FIMV2_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC FIMV3",
		.fourcc = V4L2_PIX_FMT_FIMV3,
		.codec_mode = MFC_REG_CODEC_FIMV3_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC FIMV4",
		.fourcc = V4L2_PIX_FMT_FIMV4,
		.codec_mode = MFC_REG_CODEC_FIMV4_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC XviD",
		.fourcc = V4L2_PIX_FMT_XVID,
		.codec_mode = MFC_REG_CODEC_MPEG4_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC VC1",
		.fourcc = V4L2_PIX_FMT_VC1_ANNEX_G,
		.codec_mode = MFC_REG_CODEC_VC1_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC VC1 RCV",
		.fourcc = V4L2_PIX_FMT_VC1_ANNEX_L,
		.codec_mode = MFC_REG_CODEC_VC1_RCV_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC VP8",
		.fourcc = V4L2_PIX_FMT_VP8,
		.codec_mode = MFC_REG_CODEC_VP8_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC VP9",
		.fourcc = V4L2_PIX_FMT_VP9,
		.codec_mode = MFC_REG_CODEC_VP9_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC AV1",
		.fourcc = V4L2_PIX_FMT_AV1,
		.codec_mode = MFC_REG_CODEC_AV1_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC HEVC",
		.fourcc = V4L2_PIX_FMT_HEVC,
		.codec_mode = MFC_REG_CODEC_HEVC_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "DEC BPG",
		.fourcc = V4L2_PIX_FMT_BPG,
		.codec_mode = MFC_REG_CODEC_BPG_DEC,
		.type = MFC_FMT_STREAM | MFC_FMT_DEC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC H264",
		.fourcc = V4L2_PIX_FMT_H264,
		.codec_mode = MFC_REG_CODEC_H264_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC MPEG4",
		.fourcc = V4L2_PIX_FMT_MPEG4,
		.codec_mode = MFC_REG_CODEC_MPEG4_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC H263",
		.fourcc = V4L2_PIX_FMT_H263,
		.codec_mode = MFC_REG_CODEC_H263_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC VP8",
		.fourcc = V4L2_PIX_FMT_VP8,
		.codec_mode = MFC_REG_CODEC_VP8_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC VP9",
		.fourcc = V4L2_PIX_FMT_VP9,
		.codec_mode = MFC_REG_CODEC_VP9_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC HEVC",
		.fourcc = V4L2_PIX_FMT_HEVC,
		.codec_mode = MFC_REG_CODEC_HEVC_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
	{
		.name = "ENC BPG",
		.fourcc = V4L2_PIX_FMT_BPG,
		.codec_mode = MFC_REG_CODEC_BPG_ENC,
		.type = MFC_FMT_STREAM | MFC_FMT_ENC,
		.num_planes = 1,
		.mem_planes = 1,
	},
};

#endif /* __MFC_FORMAT_H */
