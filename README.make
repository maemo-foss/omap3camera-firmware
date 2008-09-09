makemodes.pl and dcc-pulautin

Sakari Ailus <sakari.ailus@nokia.com>
Tuukka Toivonen <tuukka.o.toivonen@nokia.com>
2008-09-09

makemodes.pl is a perl script which converts sensor register lists from
FIXME into C code.

dcc-pulautin is a Makefile (mostly) that converts sensor register lists
as C code into binaries understandable to sensor drivers. The end
result is a binary with sensor driver name, sensor version and
smia_reglist suffix, for example et8ek8-0002.smia_reglist.

To convert the register lists into C code:

KDIR=/where/is/kernel make modes

To compile the register lists in C form into binaries:

KDIR=/where/is/kernel make
