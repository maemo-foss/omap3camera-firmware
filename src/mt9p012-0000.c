/* Automatically generated code from Scooby
 * configuration file `stingraykmot_v06.ini' by makemodes.pl. */


#include <media/smiaregs.h>
#include <linux/videodev2.h>

/*
 *
 * Stingray KMOT Scooby sensor settings 
 *	v06 for ES1.0, tuned settings to reduce power consumption (Micron 24.10. "MI5135-1.ppt")
 *
 * mode
 * 0	power-down
 * 1	Mode_powerup_2592X1952@11FPS_RAW10
 * 2     Mode_2592X1944@13FPS_DPCM10-8
 * 3	Mode_2592X1944@11FPS_RAW10
 * 4	Mode_1296x972@30FPS_RAW10_2X2BIN
 * 5	Mode_1296x972@30FPS_RAW10_crop_1/2-1/2
 * 6	Mode_48x486@30FPS_RAW10_crop_1/4-1/4
 * 7	Mode_324X242@30FPS_RAW10_crop_1/8-1/8
 * 8	Mode_1296x1952@15FPS_2X1BIN_RAW10
 * 9	Mode_1296x972@15FPS_RAW10_crop_1/2-1/2
 * 10	Mode_648X486@15FPS_RAW10_crop_1/4-1/4
 * 11	Mode_324X242@15FPS_RAW10_crop_1/8-1/8
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
 * Sensor Mode0 - power down
 *
 *
 */
/* VBAT    3.80		Battery voltage */
/* VANA 	  2.80		Analog supply voltage */
/* VDIG 	  1.80		Digital supply voltage */
/* SPEED   400.0		I2C speed in kHz */
/* MODE 3		Actuator drive mode */

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
		{ SMIA_REG_DELAY, 0, 5 },
		/* VDIG  0		VDIG off */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VANA  0		VANA off */
		{ SMIA_REG_DELAY, 0, 5 },
		/* VBAT  0		VBAT off */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_powerup_2592X1952@11FPS_RAW10 */
static struct smia_reglist mode_powerup_2592x1952_11fps_raw10 = {	/* 2 */
	.type = SMIA_REGLIST_POWERON,
	.mode = {
		.width = 2592,
		.height = 1952,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 11
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x85 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0400, 0x00 },
		{ SMIA_REG_8BIT, 0x0401, 0x00 },	/* // SCALING_MODE */
		{ SMIA_REG_8BIT, 0x0404, 0x00 },
		{ SMIA_REG_8BIT, 0x0405, 0x10 },	/* // SCALE_M */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },
		{ SMIA_REG_8BIT, 0x0345, 0x08 },	/* // X_ADDR_START */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },
		{ SMIA_REG_8BIT, 0x0347, 0x08 },	/* // Y_ADDR_START */
		{ SMIA_REG_8BIT, 0x0348, 0x0A },
		{ SMIA_REG_8BIT, 0x0349, 0x27 },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x07 },
		{ SMIA_REG_8BIT, 0x034B, 0xA7 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x0A },
		{ SMIA_REG_8BIT, 0x034D, 0x20 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x07 },
		{ SMIA_REG_8BIT, 0x034F, 0xA0 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode  */
		{ SMIA_REG_8BIT, 0x0202, 0x06 },
		{ SMIA_REG_8BIT, 0x0203, 0x14 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x07 },
		{ SMIA_REG_8BIT, 0x0341, 0xEF },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x15 },
		{ SMIA_REG_8BIT, 0x0343, 0x00 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x03 },
		{ SMIA_REG_8BIT, 0x3015, 0xC2 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	1=raw10  */

/* Mode_2592X1944@13FPS_DPCM10-8 */
static struct smia_reglist mode_2592x1944_13fps_dpcm10_8 = {	/* 3 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 2592,
		.height = 1944,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 13
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10DPCM8
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x85 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x09 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x08 },	/* // ccp_data_format (raw8) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x74 },	/* // PLL_MULTIPLIER4.8MHz*116=556.8MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x08 },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },
		{ SMIA_REG_8BIT, 0x0345, 0x08 },	/* // X_ADDR_START */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },
		{ SMIA_REG_8BIT, 0x0347, 0x08 },	/* // Y_ADDR_START */
		{ SMIA_REG_8BIT, 0x0348, 0x0A },
		{ SMIA_REG_8BIT, 0x0349, 0x27 },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x07 },
		{ SMIA_REG_8BIT, 0x034B, 0xA7 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x0A },
		{ SMIA_REG_8BIT, 0x034D, 0x20 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x07 },
		{ SMIA_REG_8BIT, 0x034F, 0xA0 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode  */
		{ SMIA_REG_8BIT, 0x0202, 0x06 },
		{ SMIA_REG_8BIT, 0x0203, 0x14 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x07 },
		{ SMIA_REG_8BIT, 0x0341, 0xEF },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x10 },
		{ SMIA_REG_8BIT, 0x0343, 0x50 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x0A },
		{ SMIA_REG_8BIT, 0x3015, 0xC6 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      0	0=8bits/pixel, 1=10bits/pixel */

/* Mode_2592X1944@11FPS_RAW10 */
static struct smia_reglist mode_2592x1944_11fps_raw10 = {	/* 4 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 2592,
		.height = 1944,
		.window_origin_x = 0,
		.window_origin_y = 0,
		.window_width = 0,
		.window_height = 0,
		.pixel_clock = 0,
		.ext_clock = 9600000,
		.timeperframe = {
			.numerator = 1,
			.denominator = 11
		},
		.max_exp = 0,
		/* .max_gain = 0, */
		.pixel_format = V4L2_PIX_FMT_SGRBG10
	},
	.regs = {
		{ SMIA_REG_8BIT, 0x0100, 0x00 },	/* // MODE_SELECT (Stop Streaming) */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x85 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },
		{ SMIA_REG_8BIT, 0x0345, 0x08 },	/* // X_ADDR_START */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },
		{ SMIA_REG_8BIT, 0x0347, 0x08 },	/* // Y_ADDR_START */
		{ SMIA_REG_8BIT, 0x0348, 0x0A },
		{ SMIA_REG_8BIT, 0x0349, 0x27 },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x07 },
		{ SMIA_REG_8BIT, 0x034B, 0xA7 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x0A },
		{ SMIA_REG_8BIT, 0x034D, 0x20 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x07 },
		{ SMIA_REG_8BIT, 0x034F, 0xA0 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode  */
		{ SMIA_REG_8BIT, 0x0202, 0x06 },
		{ SMIA_REG_8BIT, 0x0203, 0x14 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x07 },
		{ SMIA_REG_8BIT, 0x0341, 0xEF },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x15 },
		{ SMIA_REG_8BIT, 0x0343, 0x00 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x03 },
		{ SMIA_REG_8BIT, 0x3015, 0xC2 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};
/* imageFormat      1	1=raw10  */

/* Mode_1296x972@30FPS_RAW10_2X2BIN */
static struct smia_reglist mode_1296x972_30fps_raw10_2x2bin = {	/* 5 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 972,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },
		{ SMIA_REG_8BIT, 0x0345, 0x08 },	/* // X_ADDR_START */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },
		{ SMIA_REG_8BIT, 0x0347, 0x08 },	/* // Y_ADDR_START */
		{ SMIA_REG_8BIT, 0x0348, 0x0A },
		{ SMIA_REG_8BIT, 0x0349, 0x25 },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x07 },
		{ SMIA_REG_8BIT, 0x034B, 0xAD },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x05 },
		{ SMIA_REG_8BIT, 0x034D, 0x10 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x03 },
		{ SMIA_REG_8BIT, 0x034F, 0xD4 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x14 },
		{ SMIA_REG_8BIT, 0x3041, 0x33 },	/* //Read Mode = 0x1433 (skip2x + Bin2x, SUMMING) */
		{ SMIA_REG_8BIT, 0x0202, 0x04 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x04 },
		{ SMIA_REG_8BIT, 0x0341, 0x23 },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x0E },
		{ SMIA_REG_8BIT, 0x0343, 0xD0 },	/* //CF // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x01 },
		{ SMIA_REG_8BIT, 0x3011, 0x68 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x0A },
		{ SMIA_REG_8BIT, 0x3015, 0x0A },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_1296x972@30FPS_RAW10_crop_1/2-1/2 */
static struct smia_reglist mode_1296x972_30fps_raw10_crop_1_2_1_2 = {	/* 6 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 972,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x02 },
		{ SMIA_REG_8BIT, 0x0345, 0x90 },	/* // X_ADDR_START (crop 1/2 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x01 },
		{ SMIA_REG_8BIT, 0x0347, 0xF0 },	/* // Y_ADDR_START (crop 1/2 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x07 },
		{ SMIA_REG_8BIT, 0x0349, 0x9F },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x05 },
		{ SMIA_REG_8BIT, 0x034B, 0xC3 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x05 },
		{ SMIA_REG_8BIT, 0x034D, 0x10 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x03 },
		{ SMIA_REG_8BIT, 0x034F, 0xD4 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x04 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x04 },
		{ SMIA_REG_8BIT, 0x0341, 0x23 },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x0E },
		{ SMIA_REG_8BIT, 0x0343, 0xC0 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x0B },
		{ SMIA_REG_8BIT, 0x3015, 0x60 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_48x486@30FPS_RAW10_crop_1/4-1/4 */
static struct smia_reglist mode_48x486_30fps_raw10_crop_1_4_1_4 = {	/* 7 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 48,
		.height = 486,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x03 },
		{ SMIA_REG_8BIT, 0x0345, 0xD8 },	/* // X_ADDR_START (crop 1/4 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x02 },
		{ SMIA_REG_8BIT, 0x0347, 0xE8 },	/* // Y_ADDR_START (crop 1/4 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x06 },
		{ SMIA_REG_8BIT, 0x0349, 0x5F },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x04 },
		{ SMIA_REG_8BIT, 0x034B, 0xD5 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x02 },
		{ SMIA_REG_8BIT, 0x034D, 0x88 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x01 },
		{ SMIA_REG_8BIT, 0x034F, 0xEE },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x02 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x02 },
		{ SMIA_REG_8BIT, 0x0341, 0x3D },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x1B },
		{ SMIA_REG_8BIT, 0x0343, 0x48 },	/* //44 // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x05 },
		{ SMIA_REG_8BIT, 0x3015, 0x3C },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_324X242@30FPS_RAW10_crop_1/8-1/8 */
static struct smia_reglist mode_324x242_30fps_raw10_crop_1_8_1_8 = {	/* 8 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 324,
		.height = 242,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x04 },
		{ SMIA_REG_8BIT, 0x0345, 0x78 },	/* // X_ADDR_START (crop 1/8 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x03 },
		{ SMIA_REG_8BIT, 0x0347, 0x60 },	/* // Y_ADDR_START (crop 1/8 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x05 },
		{ SMIA_REG_8BIT, 0x0349, 0xBB },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x04 },
		{ SMIA_REG_8BIT, 0x034B, 0x5A },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x01 },
		{ SMIA_REG_8BIT, 0x034D, 0x44 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x00 },
		{ SMIA_REG_8BIT, 0x034F, 0xFA },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x01 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x01 },
		{ SMIA_REG_8BIT, 0x0341, 0x4A },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x2F },
		{ SMIA_REG_8BIT, 0x0343, 0x58 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x2A },
		{ SMIA_REG_8BIT, 0x3015, 0x9E },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_1296x1952@15FPS_2X1BIN_RAW10 */
static struct smia_reglist mode_1296x1952_15fps_2x1bin_raw10 = {	/* 9 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 1952,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0304, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x00 },
		{ SMIA_REG_8BIT, 0x0345, 0x08 },	/* // X_ADDR_START */
		{ SMIA_REG_8BIT, 0x0346, 0x00 },
		{ SMIA_REG_8BIT, 0x0347, 0x08 },	/* // Y_ADDR_START */
		{ SMIA_REG_8BIT, 0x0348, 0x0A },
		{ SMIA_REG_8BIT, 0x0349, 0x25 },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x07 },
		{ SMIA_REG_8BIT, 0x034B, 0xA7 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x05 },
		{ SMIA_REG_8BIT, 0x034D, 0x10 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x07 },
		{ SMIA_REG_8BIT, 0x034F, 0xA0 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x18 },
		{ SMIA_REG_8BIT, 0x3041, 0x31 },	/* //Read Mode = 0x1831 (Bin2x only x-binning, SUMMING) */
		{ SMIA_REG_8BIT, 0x0202, 0x04 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x07 },
		{ SMIA_REG_8BIT, 0x0341, 0xEF },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x0F },
		{ SMIA_REG_8BIT, 0x0343, 0x62 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x01 },
		{ SMIA_REG_8BIT, 0x3011, 0x68 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x07 },
		{ SMIA_REG_8BIT, 0x3015, 0x8A },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_1296x972@15FPS_RAW10_crop_1/2-1/2 */
static struct smia_reglist mode_1296x972_15fps_raw10_crop_1_2_1_2 = {	/* 10 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 1296,
		.height = 972,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x02 },
		{ SMIA_REG_8BIT, 0x0345, 0x90 },	/* // X_ADDR_START (crop 1/2 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x01 },
		{ SMIA_REG_8BIT, 0x0347, 0xF0 },	/* // Y_ADDR_START (crop 1/2 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x07 },
		{ SMIA_REG_8BIT, 0x0349, 0x9F },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x05 },
		{ SMIA_REG_8BIT, 0x034B, 0xC3 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x05 },
		{ SMIA_REG_8BIT, 0x034D, 0x10 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x03 },
		{ SMIA_REG_8BIT, 0x034F, 0xD4 },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x04 },
		{ SMIA_REG_8BIT, 0x0203, 0x10 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x04 },
		{ SMIA_REG_8BIT, 0x0341, 0x23 },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x1D },
		{ SMIA_REG_8BIT, 0x0343, 0x88 },	/* //82 // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x1A },
		{ SMIA_REG_8BIT, 0x3015, 0x22 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_648X486@15FPS_RAW10_crop_1/4-1/4 */
static struct smia_reglist mode_648x486_15fps_raw10_crop_1_4_1_4 = {	/* 11 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 648,
		.height = 486,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x03 },
		{ SMIA_REG_8BIT, 0x0345, 0xD8 },	/* // X_ADDR_START (crop 1/4 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x02 },
		{ SMIA_REG_8BIT, 0x0347, 0xE8 },	/* // Y_ADDR_START (crop 1/4 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x06 },
		{ SMIA_REG_8BIT, 0x0349, 0x5F },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x04 },
		{ SMIA_REG_8BIT, 0x034B, 0xD5 },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x02 },
		{ SMIA_REG_8BIT, 0x034D, 0x88 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x01 },
		{ SMIA_REG_8BIT, 0x034F, 0xEE },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x02 },
		{ SMIA_REG_8BIT, 0x0203, 0x20 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x02 },
		{ SMIA_REG_8BIT, 0x0341, 0x3D },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x36 },
		{ SMIA_REG_8BIT, 0x0343, 0x88 },	/* // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x20 },
		{ SMIA_REG_8BIT, 0x3015, 0x78 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

/* Mode_324X242@15FPS_RAW10_crop_1/8-1/8 */
static struct smia_reglist mode_324x242_15fps_raw10_crop_1_8_1_8 = {	/* 12 */
	.type = SMIA_REGLIST_MODE,
	.mode = {
		.width = 324,
		.height = 242,
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
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x14 },	/* // default reset register */
		{ SMIA_REG_8BIT, 0x308E, 0xE0 },
		{ SMIA_REG_8BIT, 0x308F, 0x60 },	/* // RESERVED */
		{ SMIA_REG_8BIT, 0x3084, 0x24 },
		{ SMIA_REG_8BIT, 0x3085, 0x12 },
		{ SMIA_REG_8BIT, 0x3092, 0x0A },
		{ SMIA_REG_8BIT, 0x3093, 0x52 },
		{ SMIA_REG_8BIT, 0x3094, 0x52 },
		{ SMIA_REG_8BIT, 0x3095, 0x12 },
		{ SMIA_REG_8BIT, 0x3096, 0x12 },
		{ SMIA_REG_8BIT, 0x3097, 0x52 },
		{ SMIA_REG_8BIT, 0x3170, 0x09 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x3171, 0x88 },	/* <--- setting based on operating mode */
		{ SMIA_REG_8BIT, 0x301A, 0x00 },
		{ SMIA_REG_8BIT, 0x301B, 0x1A },
		{ SMIA_REG_8BIT, 0x306E, 0x90 },
		{ SMIA_REG_8BIT, 0x306F, 0x80 },	/* // Profile 1/2 */
		{ SMIA_REG_8BIT, 0x3064, 0x08 },
		{ SMIA_REG_8BIT, 0x3065, 0x05 },
		{ SMIA_REG_8BIT, 0x0111, 0x01 },	/* // class 1/2 */
		{ SMIA_REG_8BIT, 0x0112, 0x0A },
		{ SMIA_REG_8BIT, 0x0113, 0x0A },	/* // ccp_data_format (raw10) */
		{ SMIA_REG_8BIT, 0x0300, 0x00 },
		{ SMIA_REG_8BIT, 0x0301, 0x05 },	/* // VT_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0302, 0x00 },
		{ SMIA_REG_8BIT, 0x0303, 0x01 },	/* // VT_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0304, 0x00 },
		{ SMIA_REG_8BIT, 0x0305, 0x02 },	/* // PRE_PLL_CLK_DI 9.6MHz/2 = 4.8MHz */
		{ SMIA_REG_8BIT, 0x0306, 0x00 },
		{ SMIA_REG_8BIT, 0x0307, 0x7D },	/* // PLL_MULTIPLIER 4.8MHz*125 = 600MHz */
		{ SMIA_REG_8BIT, 0x0308, 0x00 },
		{ SMIA_REG_8BIT, 0x0309, 0x0A },	/* // OP_PIX_CLK_DIV */
		{ SMIA_REG_8BIT, 0x030A, 0x00 },
		{ SMIA_REG_8BIT, 0x030B, 0x01 },	/* // OP_SYS_CLK_DIV */
		{ SMIA_REG_8BIT, 0x0104, 0x01 },	/* //GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0344, 0x04 },
		{ SMIA_REG_8BIT, 0x0345, 0x78 },	/* // X_ADDR_START (crop 1/8 with ROI in array center) */
		{ SMIA_REG_8BIT, 0x0346, 0x03 },
		{ SMIA_REG_8BIT, 0x0347, 0x60 },	/* // Y_ADDR_START (crop 1/8 with ROI in array center)  */
		{ SMIA_REG_8BIT, 0x0348, 0x05 },
		{ SMIA_REG_8BIT, 0x0349, 0xBB },	/* // X_ADDR_END */
		{ SMIA_REG_8BIT, 0x034A, 0x04 },
		{ SMIA_REG_8BIT, 0x034B, 0x5A },	/* // Y_ADDR_END */
		{ SMIA_REG_8BIT, 0x034C, 0x01 },
		{ SMIA_REG_8BIT, 0x034D, 0x44 },	/* // X_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x034E, 0x00 },
		{ SMIA_REG_8BIT, 0x034F, 0xFA },	/* // Y_OUTPUT_SIZE */
		{ SMIA_REG_8BIT, 0x3040, 0x00 },
		{ SMIA_REG_8BIT, 0x3041, 0x11 },	/* //Read Mode (no skip, no bin) */
		{ SMIA_REG_8BIT, 0x0202, 0x01 },
		{ SMIA_REG_8BIT, 0x0203, 0x20 },	/* // COARSE_INTEGRATION_TIME */
		{ SMIA_REG_8BIT, 0x0340, 0x01 },
		{ SMIA_REG_8BIT, 0x0341, 0x4A },	/* // FRAME_LENGTH_LINES */
		{ SMIA_REG_8BIT, 0x0342, 0x5E },
		{ SMIA_REG_8BIT, 0x0343, 0xB8 },	/* //B2 // LINE_LENGTH_PCK  */
		{ SMIA_REG_8BIT, 0x3010, 0x00 },
		{ SMIA_REG_8BIT, 0x3011, 0xA8 },	/* // FINE_CORRECTION */
		{ SMIA_REG_8BIT, 0x3014, 0x59 },
		{ SMIA_REG_8BIT, 0x3015, 0xF8 },	/* // FINE_INTEGRATION_TIME_ */
		{ SMIA_REG_8BIT, 0x0104, 0x00 },	/* // GROUPED_PARAMETER_HOLD */
		{ SMIA_REG_8BIT, 0x0100, 0x01 },	/* // MODE_SELECT (Start Streaming) */
		{ SMIA_REG_TERM, 0, 0}
	}
};

struct smia_meta_reglist smia_meta_reglist = {
	.version = "2008-08-19",
	.reglist = {
		{ .offset = (uintptr_t)&mode0_powerdown },
		{ .offset = (uintptr_t)&mode_powerup_2592x1952_11fps_raw10 },
		{ .offset = (uintptr_t)&mode_2592x1944_13fps_dpcm10_8 },
		{ .offset = (uintptr_t)&mode_2592x1944_11fps_raw10 },
		{ .offset = (uintptr_t)&mode_1296x972_30fps_raw10_2x2bin },
		{ .offset = (uintptr_t)&mode_1296x972_30fps_raw10_crop_1_2_1_2 },
		{ .offset = (uintptr_t)&mode_48x486_30fps_raw10_crop_1_4_1_4 },
		{ .offset = (uintptr_t)&mode_324x242_30fps_raw10_crop_1_8_1_8 },
		{ .offset = (uintptr_t)&mode_1296x1952_15fps_2x1bin_raw10 },
		{ .offset = (uintptr_t)&mode_1296x972_15fps_raw10_crop_1_2_1_2 },
		{ .offset = (uintptr_t)&mode_648x486_15fps_raw10_crop_1_4_1_4 },
		{ .offset = (uintptr_t)&mode_324x242_15fps_raw10_crop_1_8_1_8 },
		{ .offset = 0 }
	}
};

