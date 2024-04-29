#ifndef IS_DEVICE_CSI_H
#define IS_DEVICE_CSI_H

#include <linux/interrupt.h>
#include <linux/kfifo.h>
#include <media/v4l2-device.h>
#include "pablo-debug.h"
#include "is-type.h"
#include "pablo-framemgr.h"
#include "is-subdev-ctrl.h"
#include "pablo-work.h"
#include "is-device-camif-dma.h"
#include "pablo-device-camif-subblks.h"

#define CSI_IRQ_NAME_LENGTH	16

#define CSI_NOTIFY_VSYNC	10
#define CSI_NOTIFY_VBLANK	11

#define CSI_LINE_RATIO		14	/* 70% */
#define CSI_ERR_COUNT		10  	/* 10frame */

#define CSI_WAIT_ABORT_TIMEOUT	(HZ / 4)

#define CSI_VALID_ENTRY_TO_CH(id) ((id) >= ENTRY_SSVC0 && (id) <= ENTRY_SSVC7)
#define CSI_ENTRY_TO_CH(id) ({BUG_ON(!CSI_VALID_ENTRY_TO_CH(id));id - ENTRY_SSVC0;}) /* range : vc0(0) ~ vc7(7) */
#define CSI_CH_TO_ENTRY(id) (id + ENTRY_SSVC0) /* range : ENTRY_SSVC0 ~ ENTRY_SSVC7 */

/* for use multi buffering */
#define CSI_GET_PREV_FRAMEPTR(frameptr, num_frames, offset) \
	((frameptr) == 0 ? (num_frames) - offset : (frameptr) - offset)
#define CSI_GET_NEXT_FRAMEPTR(frameptr, num_frames) \
	(((frameptr) + 1) % num_frames)

/* For frame id decoder */
#define BUF_SWAP_CNT		2	/* for frame_id decoder & FRO mode: double buffering */

/* for ebuf */
#define EBUF_MANUAL_MODE	0
#define EBUF_AUTO_MODE		1

enum is_csi_state {
	CSIS_DMA_FLUSH_WAIT,
	CSIS_START_STREAM,
	/* runtime buffer done state for error */
	CSIS_BUF_ERR_VC0,
	CSIS_BUF_ERR_VC1,
	CSIS_BUF_ERR_VC2,
	CSIS_BUF_ERR_VC3,
	CSIS_BUF_ERR_VC4,
	CSIS_BUF_ERR_VC5,
	CSIS_BUF_ERR_VC6,
	CSIS_BUF_ERR_VC7,
	CSIS_BUF_ERR_VC8,
	CSIS_BUF_ERR_VC9,
	/* csi vc multibuffer setting state */
	CSIS_SET_MULTIBUF_DMA0,
	CSIS_SET_MULTIBUF_DMA1,
	CSIS_SET_MULTIBUF_DMA2,
	CSIS_SET_MULTIBUF_DMA3,
	CSIS_SET_MULTIBUF_DMA4,
	/* use csi_dma disable on vvalid */
	CSIS_DMA_DISABLING,
	CSIS_LINE_IRQ_ENABLE,
};

struct is_csis_state_cnt {
	u32				err;
	u32				str;
	u32				end;
};

struct is_device_csi {
	char				*stm;
	u32				instance;	/* logical stream id */

	u32 device_id;				/* Physical sensor node id */
	struct pablo_camif_otf_info	otf_info;

	u32 __iomem			*base_reg;
	u32 __iomem			*phy_reg;
	u32 __iomem			*fro_reg;
	u32 __iomem			*otf_out_mux;
	resource_size_t			regs_start;
	resource_size_t			regs_end;
	int				irq;
	char				irq_name[CSI_IRQ_NAME_LENGTH];

	struct is_camif_wdma *wdma[CSIS_MAX_NUM_DMA_ATTACH];
	struct is_camif_wdma_module *wdma_mod[CSIS_MAX_NUM_DMA_ATTACH];
	unsigned int wdma_ch_hint; /* use designated ch, if it is in DT. */
	struct is_wdma_info		wdma_info;

	struct is_camif_wdma *stat_wdma;
	struct is_camif_wdma_module	*stat_wdma_mod;

	struct pablo_camif_mcb		*mcb;
	struct pablo_camif_ebuf		*ebuf;
	struct pablo_camif_bns		*bns;
	struct pablo_camif_csis_pdp_top	*top;

	/* debug */
	struct hw_debug_info		debug_info[DEBUG_FRAME_COUNT];

	/* for settle time */
	struct is_sensor_cfg	*sensor_cfg;

	/* image configuration */
	struct is_image		image;

	unsigned long			state;

	/* for DMA feature */
	struct is_framemgr		*framemgr;
	u32				sw_checker;
	atomic_t			fcount;
	atomic_t			chain_fcount;
	u32				hw_fcount;
	struct tasklet_struct		tasklet_csis_end;
	struct tasklet_struct		tasklet_csis_line;
	struct tasklet_struct		tasklet_csis_otf_cfg;

	struct workqueue_struct		*workqueue;
	struct work_struct wq_csis_dma;
	struct is_work_list work_list;

	struct work_struct		wq_ebuf_reset;

	int pre_dma_enable[CSIS_MAX_NUM_DMA_ATTACH][DMA_VIRTUAL_CH_MAX];
	int cur_dma_enable[CSIS_MAX_NUM_DMA_ATTACH][DMA_VIRTUAL_CH_MAX];

	/* dma subdev slots for each dma vc  */
	struct is_subdev *dma_subdev[CSIS_MAX_NUM_DMA_ATTACH][DMA_VIRTUAL_CH_MAX];

	/* pointer address from device sensor */
	struct v4l2_subdev		**subdev;
	struct phy			*phy;
	struct phy_setfile_table	*phy_sf_tbl;

	ulong error_id[CSI_VIRTUAL_CH_MAX];
	ulong dma_error_id[CSIS_MAX_NUM_DMA_ATTACH][DMA_VIRTUAL_CH_MAX];
	u32 error_id_last[CSI_VIRTUAL_CH_MAX];
	u32 error_count;
	u32 error_count_vc_overlap;

	atomic_t                        vblank_count; /* Increase at CSI frame end */
	atomic_t			vvalid; /* set 1 while vvalid period */

	char				name[IS_STR_LEN];
	u32				use_cphy;
	bool				potf;
	bool				f_id_dec; /* For frame id decoder in FRO mode */
	atomic_t			bufring_cnt; /* For double buffering in FRO mode */
	u32				dma_batch_num;
	u32				otf_batch_num;
	spinlock_t			dma_seq_slock;
	spinlock_t			dma_irq_slock;
	spinlock_t			dma_rta_lock;

	wait_queue_head_t		dma_flush_wait_q;
	bool				crc_flag;

	struct is_csis_state_cnt	state_cnt;

	struct kfifo dbg_irq_info_fifo;
	struct work_struct wq_link_dump;
};

struct is_sensor_subdev_ioctl_PD_arg {
	struct is_frame *vc_frame;
	struct is_device_csi *csi;
	bool start_end;
};

void csi_emulate_irq(u32 instance, u32 vvalid);
void csi_hw_cdump_all(struct is_device_csi *csi);
void csi_hw_dump_all(struct is_device_csi *csi);
u32 csi_hw_g_bpp(u32 hwformat);

int __must_check is_csi_probe(void *parent, u32 instance, u32 ch, int wdma_ch_hint);
int __must_check is_csi_open(struct v4l2_subdev *subdev, struct is_framemgr *framemgr);
int __must_check is_csi_close(struct v4l2_subdev *subdev);
/* for DMA feature */
extern u32 __iomem *last_fcount0;
extern u32 __iomem *last_fcount1;

struct pablo_csi_wq_set_func {
	void (*wq_csis_dma_vc[CSIS_MAX_NUM_DMA_ATTACH][DMA_VIRTUAL_CH_MAX])(
		struct work_struct *data);
};

struct pablo_csi_wq_set_func *get_csi_wq_set_func(void);

#if IS_ENABLED(CONFIG_PABLO_KUNIT_TEST)
struct pablo_kunit_csi_func {
	void (*csi_s_multibuf_addr)(struct is_device_csi *csi, struct is_frame *frame, u32 index,
				    u32 idx_wdma, u32 wdma_vc);
	void (*csi_dma_work_fn)(struct work_struct *data);
	union {
		void (*old_tasklet_csis_line)(unsigned long data);
		void (*tasklet_csis_line)(struct tasklet_struct *t);
	};
	void (*csi_hw_cdump_all)(struct is_device_csi *csi);
	void (*csi_hw_dump_all)(struct is_device_csi *csi);
	u32 (*csi_hw_g_bpp)(u32 hwformat);
};

struct pablo_kunit_csi_func *pablo_kunit_get_csi_test(void);
#endif

#endif
