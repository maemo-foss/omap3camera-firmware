ifeq ($(KDIR), )
$(error KDIR undefined!)
endif

CROSS_COMPILE ?= arm-linux-

.PHONY: all

ifeq ($(KERNELRELEASE), )
export MY_SRCS := $(wildcard src/*.c)
export MY_OBJS := $(patsubst %.c, %.o, $(MY_SRCS))

all:
	make -C $(KDIR) M=$(PWD) modules

	-rm *.mod.c

	for in in $(MY_OBJS); do \
		out="`echo "$$in" | sed 's/.o$$/.smia_reglist/'`"; \
		$(CROSS_COMPILE)objcopy -O binary $$in $$out; \
	done

	-find -name "*.mod.*" | xargs rm

distclean: clean
	-find -name *.smia_reglist | xargs rm

clean:
	-find -name "*.o" | xargs rm
	-find -name "*.ko" | xargs rm
	-find -name "*~" | xargs rm

else

obj-m = $(MY_OBJS)

endif
