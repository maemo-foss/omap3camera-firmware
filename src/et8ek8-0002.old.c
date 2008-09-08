#include <media/smiaregs.h>

#define ET8EK8_MES_MAX		2100	//0xFFFF

static struct smia_reglist standby = {
	.type = SMIA_REGLIST_STANDBY,
	.regs = {
		{ SMIA_REG_DELAY, 0, 1 },
		{ SMIA_REG_TERM, 0, 0 }
	}
};

static struct smia_reglist poweron = {
	.type = SMIA_REGLIST_POWERON,
	.regs = {
/*	XSHD    0		XSHUTDOWN lo	*/
/*	VBAT	  1		VBAT on	*/
		 { SMIA_REG_DELAY, 0, 1 },
/*	VANA	  1		VANA on	*/
		 { SMIA_REG_DELAY, 0, 1 },
/*	VDIG	  1		VDIG on	*/
		 { SMIA_REG_DELAY, 0, 5 },
/*	XSHD    1		XSHUTDOWN hi	*/
		 { SMIA_REG_DELAY, 0, 5 },
		 { SMIA_REG_8BIT, 0x126C, 0xCC },	/* Need to set firstly */
		 { SMIA_REG_8BIT, 0x1252, 0xB0 },	/* Need to set secondary (from Sleep to active) */
		 { SMIA_REG_8BIT, 0x1220, 0x89 },	/* Refined value of Min H_COUNT  */
		 { SMIA_REG_8BIT, 0x123A, 0x07 },	/* Frequency of SPCK setting (SPCK=MRCK) */
		 { SMIA_REG_8BIT, 0x1241, 0x94 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1242, 0x02 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x124B, 0x00 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1255, 0xFF },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1256, 0x9F },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1258, 0x00 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x125D, 0x88 },	/* From parallel out to serial out */
		 { SMIA_REG_8BIT, 0x125E, 0xC0 },	/* From w/ embedded data to w/o embedded data */
		 { SMIA_REG_8BIT, 0x1263, 0x98 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1268, 0xC6 },	/* CCP2 out is from STOP to ACTIVE */
		 { SMIA_REG_8BIT, 0x1434, 0x00 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1163, 0x44 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1166, 0x29 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1140, 0x02 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1011, 0x24 },	/* Initial setting */
		 { SMIA_REG_8BIT, 0x1151, 0x80 },	/* Initial setting( for improvement of lower frequency noise ) */
		 { SMIA_REG_8BIT, 0x1152, 0x23 },	/* Initial setting( for improvement of lower frequency noise ) */
		 { SMIA_REG_8BIT, 0x1014, 0x05 },	/* Initial setting( for improvement2 of lower frequency noise ) */
		 { SMIA_REG_8BIT, 0x1033, 0x06 },
		 { SMIA_REG_8BIT, 0x1034, 0x79 },
		 { SMIA_REG_8BIT, 0x1423, 0x3F },
		 { SMIA_REG_8BIT, 0x1424, 0x3F },
		 { SMIA_REG_8BIT, 0x1426, 0x00 },
		 { SMIA_REG_8BIT, 0x1439, 0x00 },	/* 0 */
		 { SMIA_REG_8BIT, 0x161F, 0x60 },	/* 0      blemish correction is off */
		 { SMIA_REG_8BIT, 0x1634, 0x00 },	/* 0      Auto noise reduction is off */
		 { SMIA_REG_8BIT, 0x1646, 0x00 },	/* 0 */
		 { SMIA_REG_8BIT, 0x1648, 0x00 },	/* 0 */
		 { SMIA_REG_8BIT, 0x113E, 0x01 },	/* 1 */
		 { SMIA_REG_8BIT, 0x1239, 0x64 },
		 { SMIA_REG_8BIT, 0x1238, 0x02 },
		 { SMIA_REG_8BIT, 0x123B, 0x70 },
		 { SMIA_REG_8BIT, 0x123A, 0x07 },
		 { SMIA_REG_8BIT, 0x121B, 0x64 },
		 { SMIA_REG_8BIT, 0x121D, 0x64 },
		 { SMIA_REG_8BIT, 0x1221, 0x00 },
		 { SMIA_REG_8BIT, 0x1220, 0x89 },
		 { SMIA_REG_8BIT, 0x1223, 0x00 },
		 { SMIA_REG_8BIT, 0x1222, 0x54 },
		 { SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		 { SMIA_REG_TERM, 0, 0}
	 }
};

static struct smia_reglist list_mode16_1_3_864x656_14_95fps = {
	.type = SMIA_REGLIST_MODE,
	.mode = { .width = 874, .height = 654, .timeperframe = { 100, 2989 }, .max_exp = ET8EK8_MES_MAX, .pixel_format = V4L2_PIX_FMT_SGRBG10 },
	.regs = {
		 { SMIA_REG_8BIT, 0x1239, 0x64 },
		 { SMIA_REG_8BIT, 0x1238, 0x02 },
		 { SMIA_REG_8BIT, 0x123B, 0x71 },
		 { SMIA_REG_8BIT, 0x123A, 0x17 },
		 { SMIA_REG_8BIT, 0x121B, 0x24 },
		 { SMIA_REG_8BIT, 0x121D, 0x24 },
		 { SMIA_REG_8BIT, 0x1221, 0x00 },
		 { SMIA_REG_8BIT, 0x1220, 0xA4 },
		 { SMIA_REG_8BIT, 0x1223, 0x00 },
		 { SMIA_REG_8BIT, 0x1222, 0x55 },
		 { SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		 { SMIA_REG_TERM, 0, 0}
	 }
};

struct smia_meta_reglist smia_meta_reglist = {
	.version = "et8ek8 0002 2008-08-13",
	.reglist = {
		{ .offset = (uintptr_t)&standby },
		{ .offset = (uintptr_t)&poweron },
		{ .offset = (uintptr_t)&list_mode16_1_3_864x656_14_95fps },
		{ .offset = (uintptr_t)NULL },
	}
};
