/* Automatically generated code from Scooby
 * configuration file by makemodes.pl. */


#include <media/smiaregs.h>
#include <linux/videodev2.h>

		/* VBAT    3.80		Battery voltage */
		/* VANA 	  2.80		Analog supply voltage */
		/* VDIG 	  1.80		Digital supply voltage */
		/* SPEED   400.0		I2C speed in kHz */
		/* CCM 		1.66 -0.46 -0.20 -0.23 1.67 -0.44 -0.12 -0.72 1.84	6500K */
		/* GAMMA 	2.2	 */
		/* ACONTRAST	1	contrast enhancement: 1=enable, 0=disable */
		/* CONTRLIMITS	0.0 1.0 contrast limit values: black, white */
		/* AWB		1	autowhite balance: 1=enabled, 0=disabled */
		/* WBGAINS	1.0 1.0 1.0 1.0	wb gains used when awb disabled */
		/* RUNON		1 1 1 1	wb, ccm, contrast, gamma: 1=enabled, 0=disabled */
		/* BAYER		1	Bayer format: 0=rggb, 1=grbg, gbrg=2, bggr=3 */
		/* CODING	1 	Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8 */
		/* BLACKLVL	64	Black level */
		/* SATLVL	1023	Saturation level	 */
		/* MODE 4		Actuator drive mode (bits S3,S2,S1,S0 for AD5820) */

/* Mode0_powerdown */
static struct smia_reglist mode0_powerdown = {	/* 1 */
	.type = SMIA_REGLIST_STANDBY,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		/* XSHD	0		XSHUTDOWN low */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VDIG  0		VDIG off */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VANA  0		VANA off */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VBAT  0		VBAT off */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode1_poweron_Mode2_16VGA_2592x1968_12.07fps */
static struct smia_reglist mode1_poweron_mode2_16vga_2592x1968_12_07fps = {	/* 2 */
	.type = SMIA_REGLIST_POWERON,
	.mode = {
		.width = 2592,
		.height = 1968,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1207
		},
		.max_exp = 660,
		/* .max_gain = 800, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		/* XSHD    0		XSHUTDOWN lo */
		/* VBAT	  1		VBAT on */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VANA	  1		VANA on */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VDIG	  1		VDIG on */
		{ SMIA_REG_DELAY, 0, 5 },
		/* XSHD    1		XSHUTDOWN hi */
		{ SMIA_REG_DELAY, 0, 5 },
		{ SMIA_REG_8BIT, 0x126C, 0xCC },	/* Need to set firstly */
		{ SMIA_REG_8BIT, 0x1269, 0x00 },	/* Strobe and Data of CCP2 delay are minimized. */
		{ SMIA_REG_8BIT, 0x1220, 0x89 },	/* Refined value of Min H_COUNT  */
		{ SMIA_REG_8BIT, 0x123A, 0x07 },	/* Frequency of SPCK setting (SPCK=MRCK) */
		{ SMIA_REG_8BIT, 0x1241, 0x94 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1242, 0x02 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x124B, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1255, 0xFF },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1256, 0x9F },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1258, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* From parallel out to serial out */
		{ SMIA_REG_8BIT, 0x125E, 0xC0 },	/* From w/ embeded data to w/o embeded data */
		{ SMIA_REG_8BIT, 0x1263, 0x98 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1268, 0xC6 },	/* CCP2 out is from STOP to ACTIVE */
		{ SMIA_REG_8BIT, 0x1434, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1163, 0x44 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1166, 0x29 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1140, 0x02 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1011, 0x24 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1151, 0x80 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1152, 0x23 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1014, 0x05 },	/* Initial setting( for improvement2 of lower frequency noise ) */
		{ SMIA_REG_8BIT, 0x1033, 0x06 },
		{ SMIA_REG_8BIT, 0x1034, 0x79 },
		{ SMIA_REG_8BIT, 0x1423, 0x3F },
		{ SMIA_REG_8BIT, 0x1424, 0x3F },
		{ SMIA_REG_8BIT, 0x1426, 0x00 },
		{ SMIA_REG_8BIT, 0x1439, 0x00 },	/* Switch of Preset-White-balance (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x161F, 0x60 },	/* Switch of blemish correction (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x1634, 0x00 },	/* Switch of auto noise correction (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x1646, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1648, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x113E, 0x01 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x113F, 0x22 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1252, 0xB0 },	/* Need to set finaly (from Sleep to active) */
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
		{ SMIA_REG_DELAY, 0, 400 },
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* etMax        660	max exposure time ms * 10 */
/* agMax        800	max analog gain x * 100 */

/* Mode1_16VGA_2592x1968_13.12fps_DPCM10-8 */
static struct smia_reglist mode1_16vga_2592x1968_13_12fps_dpcm10_8 = {	/* 3 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 2592,
		.height = 1968,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1312
		},
		.max_exp = 660,
		/* .max_gain = 800, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x57 },
		{ SMIA_REG_8BIT, 0x1238, 0x82 },
		{ SMIA_REG_8BIT, 0x123B, 0x70 },
		{ SMIA_REG_8BIT, 0x123A, 0x06 },
		{ SMIA_REG_8BIT, 0x121B, 0x64 },
		{ SMIA_REG_8BIT, 0x121D, 0x64 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x80 },	/* <-changed to v14 7E->80 */
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		/* CODING	3 	Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8 */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* etMax        660	max exposure time ms * 10 */
/* agMax        800	max analog gain x * 100 */

/* Mode2_16VGA_2592x1968_12.07fps */
static struct smia_reglist mode2_16vga_2592x1968_12_07fps = {	/* 4 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 2592,
		.height = 1968,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1207
		},
		.max_exp = 660,
		/* .max_gain = 800, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
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
/* etMax        660	max exposure time ms * 10 */
/* agMax        800	max analog gain x * 100 */

/* Mode3_4VGA_1296x984_14.91fps_DPCM10-8 */
static struct smia_reglist mode3_4vga_1296x984_14_91fps_dpcm10_8 = {	/* 5 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 984,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1491
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x7B },
		{ SMIA_REG_8BIT, 0x1238, 0x82 },
		{ SMIA_REG_8BIT, 0x123B, 0x70 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x63 },
		{ SMIA_REG_8BIT, 0x121D, 0x63 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x89 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat  3	0=raw8, 1=raw10, 3=DPCM10-8 */

/* Mode4_SVGA_864x656_14.94fps */
static struct smia_reglist mode4_svga_864x656_14_94fps = {	/* 6 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 864,
		.height = 656,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1494
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x62 },
		{ SMIA_REG_8BIT, 0x121D, 0x62 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xA6 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	1=raw10  */

/* Mode5_VGA_648x492_14.96fps */
static struct smia_reglist mode5_vga_648x492_14_96fps = {	/* 7 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 492,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1496
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x61 },
		{ SMIA_REG_8BIT, 0x121D, 0x61 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xDD },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode8_3/4_972x738_15.00fps_DPCM10-8 */
static struct smia_reglist mode8_3_4_972x738_15_00fps_dpcm10_8 = {	/* 8 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 972,
		.height = 738,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 15
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x70 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x53 },
		{ SMIA_REG_8BIT, 0x121D, 0x53 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x93 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode13_1/2_1296x984_15.00fps_DPCM10-8 */
static struct smia_reglist mode13_1_2_1296x984_15_00fps_dpcm10_8 = {	/* 9 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 984,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 15
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x16 },
		{ SMIA_REG_8BIT, 0x121B, 0x34 },
		{ SMIA_REG_8BIT, 0x121D, 0x34 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x7E },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		/* CODING	3 	Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8 */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode16_1/3_864x656_14.95fps */
static struct smia_reglist mode16_1_3_864x656_14_95fps = {	/* 10 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 864,
		.height = 656,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1495
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
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

/* Mode18_1/4_648x492_14.96fps */
static struct smia_reglist mode18_1_4_648x492_14_96fps = {	/* 11 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 492,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1496
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x14 },
		{ SMIA_REG_8BIT, 0x121D, 0x14 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xDD },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode19_1/6_432x328_14.99fps */
static struct smia_reglist mode19_1_6_432x328_14_99fps = {	/* 12 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 432,
		.height = 328,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 1499
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x17 },
		{ SMIA_REG_8BIT, 0x121B, 0x04 },
		{ SMIA_REG_8BIT, 0x121D, 0x04 },
		{ SMIA_REG_8BIT, 0x1221, 0x01 },
		{ SMIA_REG_8BIT, 0x1220, 0x4B },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode3_4VGA_1296x984_29.99fps_DPCM10-8 */
static struct smia_reglist mode3_4vga_1296x984_29_99fps_dpcm10_8 = {	/* 13 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 984,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2999
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x06 },
		{ SMIA_REG_8BIT, 0x121B, 0x63 },
		{ SMIA_REG_8BIT, 0x121D, 0x63 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x7E },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		/* CODING	3 	Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8 */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode4_SVGA_864x656_29.88fps */
static struct smia_reglist mode4_svga_864x656_29_88fps = {	/* 14 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 864,
		.height = 656,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2988
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x62 },
		{ SMIA_REG_8BIT, 0x121D, 0x62 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xA6 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode5_VGA_648x492_29.93fps */
static struct smia_reglist mode5_vga_648x492_29_93fps = {	/* 15 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 492,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2993
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x61 },
		{ SMIA_REG_8BIT, 0x121D, 0x61 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xDD },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode8_3/4_972x738_29.99fps */
static struct smia_reglist mode8_3_4_972x738_29_99fps = {	/* 16 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 972,
		.height = 738,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2999
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x70 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x53 },
		{ SMIA_REG_8BIT, 0x121D, 0x53 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x93 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode13_1/2_1296x984_29.99fps_DPCM10-8 */
static struct smia_reglist mode13_1_2_1296x984_29_99fps_dpcm10_8 = {	/* 17 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 984,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2999
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x06 },
		{ SMIA_REG_8BIT, 0x121B, 0x34 },
		{ SMIA_REG_8BIT, 0x121D, 0x34 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x7E },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		/* CODING	3 	Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8 */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode16_1/3_864x656_29.89fps */
static struct smia_reglist mode16_1_3_864x656_29_89fps = {	/* 18 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 864,
		.height = 656,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2989
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
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

/* Mode18_1/4_648x492_29.93fps */
static struct smia_reglist mode18_1_4_648x492_29_93fps = {	/* 19 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 492,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2993
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x14 },
		{ SMIA_REG_8BIT, 0x121D, 0x14 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xDD },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode19_1/6_432x328_29.97fps */
static struct smia_reglist mode19_1_6_432x328_29_97fps = {	/* 20 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 432,
		.height = 328,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2997
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x04 },
		{ SMIA_REG_8BIT, 0x121D, 0x04 },
		{ SMIA_REG_8BIT, 0x1221, 0x01 },
		{ SMIA_REG_8BIT, 0x1220, 0x4B },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode2_16VGA_2592x1968_3.99fps */
static struct smia_reglist mode2_16vga_2592x1968_3_99fps = {	/* 21 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 2592,
		.height = 1968,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 399
		},
		.max_exp = 2000,
		/* .max_gain = 800, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x70 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x64 },
		{ SMIA_REG_8BIT, 0x121D, 0x64 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0x89 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0xFE },
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* etMax        2000	max exposure time ms * 10 */
/* agMax        800	max analog gain x * 100 */

/* TestMode_ColorBar_On */
static struct smia_reglist testmode_colorbar_on = {	/* 22 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x112C, 0x01 },
		{ SMIA_REG_8BIT, 0x1420, 0xE0 },
		{ SMIA_REG_8BIT, 0x111B, 0x40 },	/* <-- Colorbar mode */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* TestMode_ColorBar_Off */
static struct smia_reglist testmode_colorbar_off = {	/* 23 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x112C, 0x00 },
		{ SMIA_REG_8BIT, 0x1420, 0xF0 },
		{ SMIA_REG_8BIT, 0x111B, 0x00 },
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* TestMode_0xA5_On */
static struct smia_reglist testmode_0xa5_on = {	/* 24 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1130, 0xB1 },
		{ SMIA_REG_8BIT, 0x112C, 0x40 },
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* TestMode_0xA5_Off */
static struct smia_reglist testmode_0xa5_off = {	/* 25 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x112C, 0x00 },
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* LSC_on */
static struct smia_reglist lsc_on = {	/* 26 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1446, 0x91 },	/* LSSC_LEFT_RX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1447, 0x6C },	/* LSSC_LEFT_GRX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1448, 0x72 },	/* LSSC_LEFT_GBX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1449, 0x5A },	/* LSSC_LEFT_BX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1454, 0x91 },	/* LSSC_RIGHT_RX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1455, 0x6C },	/* LSSC_RIGHT_GRX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1456, 0x72 },	/* LSSC_RIGHT_GBX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1457, 0x5A },	/* LSSC_RIGHT_BX2G[7-0] */
		{ SMIA_REG_8BIT, 0x1462, 0x91 },	/* LSSC_TOP_RY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1463, 0x78 },	/* LSSC_TOP_GRY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1464, 0x78 },	/* LSSC_TOP_GBY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1465, 0x72 },	/* LSSC_TOP_BY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1470, 0x91 },	/* LSSC_BOTTOM_RY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1471, 0x78 },	/* LSSC_BOTTOM_GRY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1472, 0x78 },	/* LSSC_BOTTOM_GBY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1473, 0x72 },	/* LSSC_BOTTOM_BY2G[7-0] */
		{ SMIA_REG_8BIT, 0x1445, 0x90 },	/* 0	LSSC_SW/ ## LSSC_MODE[1-0]/ ## ## ## * */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* LSC_off */
static struct smia_reglist lsc_off = {	/* 27 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1445, 0x00 },	/* LSSC_SW/ ## LSSC_MODE[1-0]/ ## ## ## * */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* ANR_on */
static struct smia_reglist anr_on = {	/* 28 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1635, 0x10 },	/* AGMIN_ANR_SLV */
		{ SMIA_REG_8BIT, 0x1636, 0x10 },	/* AGMAX_ANR_SLV */
		{ SMIA_REG_8BIT, 0x1637, 0x00 },	/* AGMIN_ANR_MP */
		{ SMIA_REG_8BIT, 0x1638, 0x78 },	/* AGMAX_ANR_MP */
		{ SMIA_REG_8BIT, 0x124B, 0x80 },	/* AG_LIMSW */
		{ SMIA_REG_8BIT, 0x1247, 0x02 },	/* AG_MIN */
		{ SMIA_REG_8BIT, 0x1248, 0x0F },	/* AG_MAX */
		{ SMIA_REG_8BIT, 0x1634, 0x80 },	/* ANR 80=on, 00=off */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* ANR_off */
static struct smia_reglist anr_off = {	/* 29 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1634, 0x00 },
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_2x3_1296x656_29.9fps */
static struct smia_reglist mode_2x3_1296x656_29_9fps = {	/* 30 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 656,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 100,
			.denominator = 2990
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x1239, 0x64 },
		{ SMIA_REG_8BIT, 0x1238, 0x02 },
		{ SMIA_REG_8BIT, 0x123B, 0x71 },
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x62 },
		{ SMIA_REG_8BIT, 0x121D, 0x63 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xA6 },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/ ## ## ## ## CCP_COMP_MODE[2-0] */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode1_poweron */
static struct smia_reglist mode1_poweron = {	/* 31 */
	.type = SMIA_REGLIST_POWERON,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 660,
		/* .max_gain = 800, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		/* XSHD    0		XSHUTDOWN lo */
		/* VBAT	  1		VBAT on */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VANA	  1		VANA on */
		{ SMIA_REG_DELAY, 0, 1 },
		/* VDIG	  1		VDIG on */
		{ SMIA_REG_DELAY, 0, 5 },
		/* XSHD    1		XSHUTDOWN hi */
		{ SMIA_REG_DELAY, 0, 5 },
		{ SMIA_REG_8BIT, 0x126C, 0xCA },	/* Need to set firstly */
		{ SMIA_REG_8BIT, 0x1269, 0x00 },	/* Strobe and Data of CCP2 delay are minimized. */
		{ SMIA_REG_8BIT, 0x1220, 0x89 },	/* Refined value of Min H_COUNT  */
		{ SMIA_REG_8BIT, 0x1258, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* From parallel out to serial out(RAW10) */
		{ SMIA_REG_8BIT, 0x125E, 0xC0 },	/* From w/ embedded data to w/o embedded data */
		{ SMIA_REG_8BIT, 0x1268, 0xC6 },	/* CCP2 out is from STOP to ACTIVE */
		{ SMIA_REG_8BIT, 0x1011, 0x04 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1014, 0x04 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1015, 0x01 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1016, 0x02 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1423, 0x30 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1424, 0x30 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1426, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1439, 0x00 },	/* Switch of Preset-White-balance (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x161F, 0x60 },	/* Switch of blemish correction (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x1634, 0x00 },	/* Switch of auto noise correction (0d:disable / 1d:enable) */
		{ SMIA_REG_8BIT, 0x1646, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x1648, 0x00 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x113E, 0x04 },	/* Initial setting */
		{ SMIA_REG_8BIT, 0x113F, 0x22 },	/* 2	Initial setting */
		{ SMIA_REG_8BIT, 0x1252, 0xB0 },	/* Need to set finaly (from Sleep to active) */
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
		{ SMIA_REG_DELAY, 0, 400 },
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* etMax        660	max exposure time ms * 10 */
/* agMax        800	max analog gain x * 100 */

/* Mode_Extralow_FPS */
static struct smia_reglist mode_extralow_fps = {	/* 32 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 0,
		.height = 0,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 0
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x123A, 0x27 },	/* Adjust VCO 12fps -> 4fps */
		{ SMIA_REG_8BIT, 0x1224, 0x1F },	/* 0.125fps(8s max) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

struct smia_meta_reglist smia_meta_reglist = {
	.version = "V14 03-June-2008",
	.reglist = {
		{ .offset = (uintptr_t)&mode0_powerdown },
		{ .offset = (uintptr_t)&mode1_poweron_mode2_16vga_2592x1968_12_07fps },
		{ .offset = (uintptr_t)&mode1_16vga_2592x1968_13_12fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode2_16vga_2592x1968_12_07fps },
		{ .offset = (uintptr_t)&mode3_4vga_1296x984_14_91fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode4_svga_864x656_14_94fps },
		{ .offset = (uintptr_t)&mode5_vga_648x492_14_96fps },
		{ .offset = (uintptr_t)&mode8_3_4_972x738_15_00fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode13_1_2_1296x984_15_00fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode16_1_3_864x656_14_95fps },
		{ .offset = (uintptr_t)&mode18_1_4_648x492_14_96fps },
		{ .offset = (uintptr_t)&mode19_1_6_432x328_14_99fps },
		{ .offset = (uintptr_t)&mode3_4vga_1296x984_29_99fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode4_svga_864x656_29_88fps },
		{ .offset = (uintptr_t)&mode5_vga_648x492_29_93fps },
		{ .offset = (uintptr_t)&mode8_3_4_972x738_29_99fps },
		{ .offset = (uintptr_t)&mode13_1_2_1296x984_29_99fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode16_1_3_864x656_29_89fps },
		{ .offset = (uintptr_t)&mode18_1_4_648x492_29_93fps },
		{ .offset = (uintptr_t)&mode19_1_6_432x328_29_97fps },
		{ .offset = (uintptr_t)&mode2_16vga_2592x1968_3_99fps },
		{ .offset = (uintptr_t)&testmode_colorbar_on },
		{ .offset = (uintptr_t)&testmode_colorbar_off },
		{ .offset = (uintptr_t)&testmode_0xa5_on },
		{ .offset = (uintptr_t)&testmode_0xa5_off },
		{ .offset = (uintptr_t)&lsc_on },
		{ .offset = (uintptr_t)&lsc_off },
		{ .offset = (uintptr_t)&anr_on },
		{ .offset = (uintptr_t)&anr_off },
		{ .offset = (uintptr_t)&mode_2x3_1296x656_29_9fps },
		{ .offset = (uintptr_t)&mode1_poweron },
//		{ .offset = (uintptr_t)&mode_extralow_fps },
		{ .offset = 0 },
	}
};

