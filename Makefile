CC = gcc
CFLAGS = -Wall -Iinclude

.PHONY: all run clean

all:
	$(MAKE) -C src

run:
	$(MAKE) -C src run

clean:
	$(MAKE) -C src clean
