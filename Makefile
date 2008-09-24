export DESTDIR

TARGET ?= /lib/firmware

all:

install:
	mkdir -p $(DESTDIR)$(TARGET)
	cp *.smia_reglist $(DESTDIR)$(TARGET)
