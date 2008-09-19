/* Automatically generated code from Scooby
 * configuration file `acmelitest_v02.ini' by makemodes.pl. */


#include <media/smiaregs.h>
#include <linux/videodev2.h>

/*
 *
 * Acme Lite Scooby sensor settings 
 *	v0.2 ("acmelite-V0.2-15fps.xls")
 *
 * <tuukka.o.toivonen@nokia.com> Dec 2007
 *
 * mode
 * 0	Mode_powerdown
 * 1	Mode_powerup
 * 2	Mode_648x488@30FPS_RAW10_9.6MHz
 * 3	Mode_648x488@30FPS_RAW10_13.0MHz
 * 4	Mode_648x488@15FPS_RAW10_9.6MHz
 * 5	Mode_648x488@15FPS_RAW10_13.0MHz
 *
 * Camera ID registers, for reference:
 * model_id high byte 0000 02
 * model_id low byte  0001 2B
 * revision_number    0002 00
 * manufacturer_id    0003 01
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
 * Sensor Mode0 - power down
 *
 *
 */
/* VBAT    3.80		Battery voltage */
/* VANA 	  2.80		Analog supply voltage */
/* VDIG 	  1.80		Digital supply voltage */
			
/* SPEED   400.0		I2C speed in kHz */

/* Mode_powerdown */
static struct smia_reglist mode_powerdown = {	/* 1 */
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
		{ SMIA_REG_DELAY, 0, 5 },
		/* VDIG  0		VDIG off */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VANA  0		VANA off */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VBAT  0		VBAT off */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_powerup */
static struct smia_reglist mode_powerup = {	/* 2 */
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
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		/* XSHD    0		XSHUTDOWN lo */
		/* VBAT	  1		VBAT on */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VANA	  1		VANA on */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VDIG	  1		VDIG on */
		{ SMIA_REG_DELAY, 0, 5 },
		/* XSHD    1		XSHUTDOWN hi */
		{ SMIA_REG_DELAY, 0, 100 },
		{ SMIA_REG_8BIT, 0x0103, 0x01 },	/* // SOFTWARE_RESET (clears itself) */
		{ SMIA_REG_DELAY, 0, 100 },
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0111, 0x00 },	/* // CCP2_signalling_mode */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },	/* // CCP_data_format high byte */
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // CCP_data_format low byte */
		{ SMIA_REG_8BIT, 0x0120, 0x00 },	/* // gain_mode */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },	/* // vt_pix_clk_div high byte */
		{ SMIA_REG_8BIT, 0x0301, 0x0A },	/* // vt_pix_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },	/* // vt_sys_clk_div high byte */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },	/* // pre_pll_clk_div high byte */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },	/* // pll_multiplier high byte */
		{ SMIA_REG_8BIT, 0x0340, 0x01 },	/* // frame_length_lines high byte */
		{ SMIA_REG_8BIT, 0x0341, 0xF1 },	/* // frame_length_lines low byte */
		{ SMIA_REG_8BIT, 0x0342, 0x03 },	/* // line_length_pck high byte */
		{ SMIA_REG_8BIT, 0x0343, 0x24 },	/* // line_length_pck low byte */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },	/* // x_addr_start high byte */
		{ SMIA_REG_8BIT, 0x0345, 0x00 },	/* // x_addr_start low byte */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },	/* // y_addr_start high byte */
		{ SMIA_REG_8BIT, 0x0347, 0x00 },	/* // y_addr_start low byte */
		{ SMIA_REG_8BIT, 0x0348, 0x02 },	/* // x_addr_end high byte */
		{ SMIA_REG_8BIT, 0x0349, 0x87 },	/* // x_addr_end low byte */
		{ SMIA_REG_8BIT, 0x034A, 0x01 },	/* // y_addr_end high byte */
		{ SMIA_REG_8BIT, 0x034B, 0xE7 },	/* // y_addr_end low byte */
		{ SMIA_REG_8BIT, 0x034C, 0x02 },	/* // x_output_size high byte */
		{ SMIA_REG_8BIT, 0x034D, 0x88 },	/* // x_output_size low byte */
		{ SMIA_REG_8BIT, 0x034E, 0x01 },	/* // y_output_size high byte */
		{ SMIA_REG_8BIT, 0x034F, 0xE8 },	/* // y_output_size low byte */
		{ SMIA_REG_8BIT, 0x0380, 0x00 },	/* // x_even_inc high byte */
		{ SMIA_REG_8BIT, 0x0381, 0x01 },	/* // x_even_inc low byte */
		{ SMIA_REG_8BIT, 0x0382, 0x00 },	/* // x_odd_inc high byte */
		{ SMIA_REG_8BIT, 0x0383, 0x01 },	/* // x_odd_inc low byte */
		{ SMIA_REG_8BIT, 0x0384, 0x00 },	/* // y_even_inc high byte */
		{ SMIA_REG_8BIT, 0x0385, 0x01 },	/* // y_even_inc low byte */
		{ SMIA_REG_8BIT, 0x0386, 0x00 },	/* // y_odd_inc high byte */
		{ SMIA_REG_8BIT, 0x0387, 0x01 },	/* // y_odd_inc low byte */
		{ SMIA_REG_8BIT, 0x311C, 0xA0 },	/* // MFR REGISTER */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	1=raw10  */

/* Mode_648x488@30FPS_RAW10_9.6MHz */
static struct smia_reglist mode_648x488_30fps_raw10_9_6mhz = {	/* 3 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 488,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 30
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0303, 0x02 },	/* // vt_sys_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0305, 0x01 },	/* // pre_pll_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0307, 0x19 },	/* // pll_multiplier low byte */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_648x488@30FPS_RAW10_13.0MHz */
static struct smia_reglist mode_648x488_30fps_raw10_13_0mhz = {	/* 4 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 488,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 30
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0303, 0x02 },	/* // vt_sys_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // pre_pll_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0307, 0x24 },	/* // pll_multiplier low byte */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_648x488@15FPS_RAW10_9.6MHz */
static struct smia_reglist mode_648x488_15fps_raw10_9_6mhz = {	/* 5 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 488,
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
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0303, 0x04 },	/* // vt_sys_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0305, 0x01 },	/* // pre_pll_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0307, 0x19 },	/* // pll_multiplier low byte */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_648x488@15FPS_RAW10_13.0MHz */
static struct smia_reglist mode_648x488_15fps_raw10_13_0mhz = {	/* 6 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 488,
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
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0303, 0x04 },	/* // vt_sys_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // pre_pll_clk_div low byte */
		{ SMIA_REG_8BIT, 0x0307, 0x25 },	/* // pll_multiplier low byte */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // REG_GROUPED_PAR_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

struct smia_meta_reglist smia_meta_reglist = {
	.version = "2008-08-19",
	.reglist = {
			
		{ .offset = (uintptr_t)&mode_powerdown },
		{ .offset = (uintptr_t)&mode_powerup },
		{ .offset = (uintptr_t)&mode_648x488_30fps_raw10_9_6mhz },
		{ .offset = (uintptr_t)&mode_648x488_30fps_raw10_13_0mhz },
		{ .offset = (uintptr_t)&mode_648x488_15fps_raw10_9_6mhz },
		{ .offset = (uintptr_t)&mode_648x488_15fps_raw10_13_0mhz },
		{ .offset = 0 }
	}
};

