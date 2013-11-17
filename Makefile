CC ?= gcc

ifeq ($(TARGET),)
  TARGET = $(shell $(CC) -dumpmachine)
endif

all:
	make -C mlac

dist: all
	-mkdir -p dist/root
	make -C mlac DESTDIR=../dist/root install
	install -d dist/root/usr/local/share/doc/mla
	install FORMAT COPYING dist/root/usr/local/share/doc/mla
	tar -C dist/root -czf dist/mla-$(TARGET).tar.gz .

clean:
	-rm -rf dist
	make -C mlac clean

.PHONY: all dist clean
