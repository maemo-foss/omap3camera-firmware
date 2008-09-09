dcc-pulautin

Sakari Ailus <sakari.ailus@nokia.com>
2008-09-09

dcc-pulautin is a Makefile (mostly) that converts sensor register lists
into binaries understandable to sensor drivers. The end result is a
binary with sensor driver name, sensor version and smia_reglist suffix,
for example et8ek8-0002.smia_reglist.

Usage:

KDIR=/where/is/kernel make
