CC = gcc
CFLAGS = -Wall -I../include

TARGET = test

SRCS = main.c mystrfunctions.c myfilefunctions.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
