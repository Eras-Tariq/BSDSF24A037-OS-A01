CC = gcc
CFLAGS = -Wall -I../include

TARGET = ../bin/client_static
LIB = ../lib/libmyutils.a

MAIN = main.o
LIB_OBJS = mystrfunctions.o myfilefunctions.o

.PHONY: all run clean

all: $(LIB) $(TARGET)

$(LIB): $(LIB_OBJS)
	mkdir -p ../lib
	ar rcs $(LIB) $(LIB_OBJS)
	ranlib $(LIB)

mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o mystrfunctions.o

myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o myfilefunctions.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

$(TARGET): $(MAIN) $(LIB)
	mkdir -p ../bin
	$(CC) $(CFLAGS) $(MAIN) -L../lib -lmyutils -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(MAIN) $(LIB_OBJS) $(LIB)
