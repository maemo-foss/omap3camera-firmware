export DESTDIR

all:

install:
	echo $(DESTDIR)
	cp *.smia_reglist $(DESTDIR)/lib/firmware/
