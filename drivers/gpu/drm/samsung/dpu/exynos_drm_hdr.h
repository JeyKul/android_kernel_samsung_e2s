/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (c) 2020 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * Headef file for Display Quality Enhancer.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __EXYNOS_DRM_HDR_H__
#define __EXYNOS_DRM_HDR_H__

#include <linux/spinlock.h>
#include <hdr_cal.h>
#include <exynos_drm_plane.h>

struct exynos_hdr;

struct exynos_hdr_funcs {
	void (*dump)(struct exynos_hdr *hdr);
	void (*prepare)(struct exynos_hdr *hdr,
			struct exynos_drm_plane_state *exynos_plane_state);
	void (*update)(struct exynos_hdr *hdr,
			const struct exynos_drm_plane_state *exynos_plane_state);
	void (*disable)(struct exynos_hdr *hdr);
	bool (*check)(struct exynos_hdr *hdr);
};

enum hdr_state {
	HDR_STATE_DISABLE = 0,
	HDR_STATE_ENABLE,
};

#define MAX_HDR_CONTEXT 3 // 3 ctx buffer per layer

struct hdr_regs_reset {
	u32 offset;
	u32 val;
};

struct exynos_hdr {
	u32 id;
	struct device *dev;
	struct dpp_device *dpp;

	struct hdr_regs	base_regs[HDR_HW_TYPE_MAX];
	struct hdr_regs	comm_regs;

	int cur_hw_type;
	int num_regs_reset[HDR_HW_TYPE_MAX];
	struct hdr_regs_reset *regs_reset[HDR_HW_TYPE_MAX];

	enum hdr_state state;
	struct mutex lock;
	wait_queue_head_t wait_update;

	int64_t hdr_fd;
	struct dma_buf	*dma_buf;
	void *vaddr;

	void *ctx[MAX_HDR_CONTEXT];
	int ctx_size;
	atomic_t ctx_no;

	const struct exynos_hdr_funcs *funcs;
	bool initialized;
};

#if IS_ENABLED(CONFIG_DRM_SAMSUNG_HDR)
void exynos_hdr_dump(struct exynos_hdr *hdr);
void exynos_hdr_prepare(struct exynos_hdr *hdr,
			struct exynos_drm_plane_state *exynos_plane_state);
void exynos_hdr_update(struct exynos_hdr *hdr,
			const struct exynos_drm_plane_state *exynos_plane_state);
void exynos_hdr_disable(struct exynos_hdr *hdr);
struct exynos_hdr *exynos_hdr_register(struct dpp_device *dpp);
#else
static inline void exynos_hdr_dump(struct exynos_hdr *hdr) {}
static inline void exynos_hdr_prepare(struct exynos_hdr *hdr,
			struct exynos_drm_plane_state *exynos_plane_state) {}
static inline void exynos_hdr_update(struct exynos_hdr *hdr,
			const struct exynos_drm_plane_state *exynos_plane_state) {}
static inline void exynos_hdr_disable(struct exynos_hdr *hdr) {}
static inline struct exynos_hdr *exynos_hdr_register(struct dpp_device *dpp) {return NULL; }
#endif

#endif /* __EXYNOS_DRM_HDR_H__ */
