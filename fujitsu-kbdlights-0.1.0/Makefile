# Makefile stolen from "fsc_btns" driver.

KERNELRELEASE	:= $(shell uname -r)
KERNEL_SOURCE	:= /lib/modules/$(KERNELRELEASE)/build
PWD		:= $(shell pwd)

ifdef DEFS
EXTRA_CFLAGS	+= $(DEFS)
endif


all: fujitsu_kbdlights

fujitsu_kbdlights: fujitsu_kbdlights.c
	gcc -o fujitsu_kbdlights fujitsu_kbdlights.c

install: fujitsu_kbdlights
	cp fujitsu_kbdlights /usr/bin
	chmod +s /usr/bin/fujitsu_kbdlights

uninstall:
	rm -f /usr/bin/fujitsu_kbdlights

clean:
	rm -f fujitsu_kbdlights

%:
	@echo; \
	 echo " *** unknown target $@ *** "; \
	 echo

.PHONY: all install uninstall clean
