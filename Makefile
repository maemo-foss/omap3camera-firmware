ifeq ($(KDIR), )
$(error KDIR undefined!)
endif

CROSS_COMPILE ?= arm-linux-

.PHONY: all

ifeq ($(KERNELRELEASE), )
export MY_SRCS := $(wildcard *.c)
export MY_OBJS := $(patsubst %.c, %.o, $(MY_SRCS))

all:
	make -C $(KDIR) M=$(PWD) modules

	-rm *.mod.c

	for in in $(MY_OBJS); do \
		out="`echo "$$in" | sed 's/.o$$/.smia_reglist/'`"; \
		$(CROSS_COMPILE)objcopy -O binary $$in $$out; \
	done

distclean: clean
	-rm *.smia_reglist

clean:
	-rm *.o *.ko *~

else

obj-m = $(MY_OBJS)

endif
