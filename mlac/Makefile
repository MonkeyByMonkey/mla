CC ?= gcc

ifneq ($(TARGET),)
	CC = $(TARGET)-gcc
endif

CFLAGS += -std=c99

all: mlac

mlac: args.o io.o format.o mlac.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm -f *.o mlac

install: all
	install -d $(DESTDIR)/usr/local/bin
	install mlac $(DESTDIR)/usr/local/bin

.PHONY: clean all install
