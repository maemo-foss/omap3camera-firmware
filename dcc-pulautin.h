#include <media/smiaregs.h>

#define DECLARE_SMIA_REGLIST(_name, _type, _mode, ...)	\
	static struct smia_reglist _name = {		\
		.type = _type,				\
		.mode = _mode,				\
		.regs = { __VA_ARGS__ }			\
	};
