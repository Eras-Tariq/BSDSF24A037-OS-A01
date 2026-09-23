CC = gcc
CFLAGS = -Wall -I../include

TARGET = ../bin/client
SRCS = main.c mystrfunctions.c myfilefunctions.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS)
	mkdir -p ../bin
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
