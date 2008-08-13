#include "dcc-pulautin.h"

#include "et8ek8-modes.h"

DECLARE_SMIA_REGLIST(standby,
		     SMIA_REGLIST_STANDBY,
		     { },
		     { SMIA_REG_DELAY, 0, 1 },
		     { SMIA_REG_TERM, 0, 0 });
/* static struct smia_reglist standby = { */
/* 	.size = sizeof(standby), */
/* 	.type = SMIA_REGLIST_STANDBY, */
/* 	.regs = { */
/* 		{ SMIA_REG_DELAY, 0, 1 }, */
/* 		{ SMIA_REG_TERM, 0, 0 }, */
/* 	} */
/* }; */

static struct smia_reglist mode1_16vga_2592x1968_13_12fps_dpcm10_8 = {
	.size = sizeof(mode1_16vga_2592x1968_13_12fps_dpcm10_8),
	.type = SMIA_REGLIST_MODE(0),
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
		{ SMIA_REG_8BIT, 0x125D, 0x83 },
		{ SMIA_REG_TERM, 0, 0}
	}
};

struct smia_meta_reglist smia_meta_reglist = {
	.version = "et8ek8 0001 2008-08-13",
	.reglist = {
		(uintptr_t)&standby,
		(uintptr_t)&mode1_16vga_2592x1968_13_12fps_dpcm10_8,
		(uintptr_t)NULL,
	}
};
