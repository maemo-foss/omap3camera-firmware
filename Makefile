export DESTDIR

TARGET ?= /lib/firmware

all:

install:
	mkdir -p $(DESTDIR)$(TARGET)
	cp bin/*.bin $(DESTDIR)$(TARGET)
