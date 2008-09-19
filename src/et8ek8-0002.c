/* Automatically generated code from Scooby
 * configuration file `stingraytsb_v09.ini' by makemodes.pl. */


#include <media/smiaregs.h>
#include <linux/videodev2.h>

/*
 *
 * Stingray sensor mode settings for Scooby
 * 	v01 bw
 *	v02 color 08.08.2007
 *	v03 color
 *	v04 based on "Stingray_Sensor_Mode_Setting_Calculator.xls" 31.08.2007
 *           15fps&30fps modes added, Hcount corrected (removes colorcast from right edge)
 *   	v05 power-up settings minimized (based on application note E70 command table)
 *	v06 based on "Stingray_Sensor_Mode_Setting_Calculator_V1.7" 21.09.2007
 *	v07 actuator drive mode setting added, modes are same as v06
 *	v08 based on "Stingray_Sensor_mode_setting_calculator_v1.8" 06.10.2007 
 *	    -Mode2_16VGA_2592x1968_12.07fps modified (max CCP downto 640Mbit/s)
 *	    -MFR settings updated (from application note E100)
 *	v09 MFR registers updated (Sugimoto's email 7-Nov-2007)
 *
 * Modes
 *	0 Mode0_powerdown
 *	1 Mode1_poweron_Mode2_16VGA_2592x1968_12.07fps
 *	2 Mode1_16VGA_2592x1968_13.12fps_DPCM10-8
 *	3 Mode2_16VGA_2592x1968_12.07fps
 * 15fps:
 *	4 Mode3_4VGA_1296x984_14.91fps_DPCM10-8
 *	5 Mode4_SVGA_864x656_14.94fps
 *	6 Mode5_VGA_648x492_14.96fps
 *	7 Mode13_1/2_1296x984_15.00fps_DPCM10-8
 *	8 Mode16_1/3_864x656_14.95fps
 *	9 Mode18_1/4_648x492_14.96fps
 *	10 Mode19_1/6_432x328_14.99fps
 * 30fps:
 *	11 Mode3_4VGA_1296x984_29.99fps_DPCM10-8
 *	12 Mode4_SVGA_864x656_29.88fps
 *	13 Mode5_VGA_648x492_29.93fps
 *	14 Mode13_1/2_1296x984_29.99fps_DPCM10-8
 *	15 Mode16_1/3_864x656_29.89fps
 *	16 Mode18_1/4_648x492_29.93fps
 *	17 Mode19_1/6_432x328_29.97fps
 *
 *
 *
 *
 *
 *
 * Scooby HW settings - these are set always, immediately. Can not be inside mode settings.
 *
 * Configure powersupplies, I2C speed and ExtClk.
 *
 */
/*
 *
 *
 * Lens actuator drive settings
 *
 */
/*
 *
 *
 *
 *
 *
 * Sensor Mode0 - power down
 *
 *
 */
/* VBAT    3.80		Battery voltage */
/* VANA 	  2.80		Analog supply voltage */
/* VDIG 	  1.80		Digital supply voltage */
/* SPEED   400.0		I2C speed in kHz */
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
		.max_exp = 0,
		/* .max_gain = 0, */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	1=raw10  */
/* imageWidth	2592	Number of pixels in one line */
/* imageHeight	1968	Number of lines in active image */
/* paxelTopLine	 328	Top line of AFV&APS window (y0) */
/* paxelLeftPixel 432	Left column of AFV&APS window (x0) */
/* paxelWidth 	 576	Number of pixels in one Paxel */
/* paxelHeight    437	Number of lines in one Paxel */

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
		.max_exp = 0,
		/* .max_gain = 0, */
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
		{ SMIA_REG_8BIT, 0x1220, 0x7E },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      0	0=raw8, 1=raw10  */

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
		.max_exp = 0,
		/* .max_gain = 0, */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

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
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      0	0=raw8, 1=raw10  */

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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode13_1/2_1296x984_15.00fps_DPCM10-8 */
static struct smia_reglist mode13_1_2_1296x984_15_00fps_dpcm10_8 = {	/* 8 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      0	0=raw8, 1=raw10  */

/* Mode16_1/3_864x656_14.95fps */
static struct smia_reglist mode16_1_3_864x656_14_95fps = {	/* 9 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode18_1/4_648x492_14.96fps */
static struct smia_reglist mode18_1_4_648x492_14_96fps = {	/* 10 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode19_1/6_432x328_14.99fps */
static struct smia_reglist mode19_1_6_432x328_14_99fps = {	/* 11 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode3_4VGA_1296x984_29.99fps_DPCM10-8 */
static struct smia_reglist mode3_4vga_1296x984_29_99fps_dpcm10_8 = {	/* 12 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      0	0=raw8, 1=raw10  */

/* Mode4_SVGA_864x656_29.88fps */
static struct smia_reglist mode4_svga_864x656_29_88fps = {	/* 13 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode5_VGA_648x492_29.93fps */
static struct smia_reglist mode5_vga_648x492_29_93fps = {	/* 14 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode13_1/2_1296x984_29.99fps_DPCM10-8 */
static struct smia_reglist mode13_1_2_1296x984_29_99fps_dpcm10_8 = {	/* 15 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x83 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode16_1/3_864x656_29.89fps */
static struct smia_reglist mode16_1_3_864x656_29_89fps = {	/* 16 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode18_1/4_648x492_29.93fps */
static struct smia_reglist mode18_1_4_648x492_29_93fps = {	/* 17 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode19_1/6_432x328_29.97fps */
static struct smia_reglist mode19_1_6_432x328_29_97fps = {	/* 18 */
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
		{ SMIA_REG_8BIT, 0x125D, 0x88 },	/* CCP_LVDS_MODE/  */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode3_4VGA_1296x984_14.96fps */
static struct smia_reglist mode3_4vga_1296x984_14_96fps = {	/* 19 */
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
		{ SMIA_REG_8BIT, 0x123A, 0x07 },
		{ SMIA_REG_8BIT, 0x121B, 0x63 },
		{ SMIA_REG_8BIT, 0x121D, 0x63 },
		{ SMIA_REG_8BIT, 0x1221, 0x00 },
		{ SMIA_REG_8BIT, 0x1220, 0xDD },
		{ SMIA_REG_8BIT, 0x1223, 0x00 },
		{ SMIA_REG_8BIT, 0x1222, 0x54 },
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	0=raw8, 1=raw10 */

struct smia_meta_reglist smia_meta_reglist = {
	.version = "2008-08-19",
	.reglist = {
		{ .offset = (uintptr_t)&mode0_powerdown },
		{ .offset = (uintptr_t)&mode1_poweron_mode2_16vga_2592x1968_12_07fps },
		{ .offset = (uintptr_t)&mode1_16vga_2592x1968_13_12fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode2_16vga_2592x1968_12_07fps },
		{ .offset = (uintptr_t)&mode3_4vga_1296x984_14_91fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode4_svga_864x656_14_94fps },
		{ .offset = (uintptr_t)&mode5_vga_648x492_14_96fps },
		{ .offset = (uintptr_t)&mode13_1_2_1296x984_15_00fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode16_1_3_864x656_14_95fps },
		{ .offset = (uintptr_t)&mode18_1_4_648x492_14_96fps },
		{ .offset = (uintptr_t)&mode19_1_6_432x328_14_99fps },
		{ .offset = (uintptr_t)&mode3_4vga_1296x984_29_99fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode4_svga_864x656_29_88fps },
		{ .offset = (uintptr_t)&mode5_vga_648x492_29_93fps },
		{ .offset = (uintptr_t)&mode13_1_2_1296x984_29_99fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode16_1_3_864x656_29_89fps },
		{ .offset = (uintptr_t)&mode18_1_4_648x492_29_93fps },
		{ .offset = (uintptr_t)&mode19_1_6_432x328_29_97fps },
		{ .offset = (uintptr_t)&mode3_4vga_1296x984_14_96fps },
		{ .offset = 0 }
	}
};

