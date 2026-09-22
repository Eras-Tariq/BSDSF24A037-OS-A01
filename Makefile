CC = gcc
CFLAGS = -Wall -Iinclude

all:
	$(MAKE) -C src

run:
	$(MAKE) -C src run

clean:
	$(MAKE) -C src cleanO

