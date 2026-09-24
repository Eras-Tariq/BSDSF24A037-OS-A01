CC = gcc
CFLAGS = -Wall -I../include
PICFLAGS = -fPIC

STATIC_TARGET = ../bin/client_static
DYNAMIC_TARGET = ../bin/client_dynamic

STATIC_LIB = ../lib/libmyutils.a
DYNAMIC_LIB = ../lib/libmyutils.so

MAIN = main.o
LIB_OBJS = mystrfunctions.o myfilefunctions.o
PIC_OBJS = mystrfunctions_pic.o myfilefunctions_pic.o

.PHONY: all run clean

all: $(STATIC_LIB) $(DYNAMIC_LIB) $(STATIC_TARGET) $(DYNAMIC_TARGET)

# Static Library
$(STATIC_LIB): $(LIB_OBJS)
	mkdir -p ../lib
	ar rcs $(STATIC_LIB) $(LIB_OBJS)
	ranlib $(STATIC_LIB)

# Dynamic Library
$(DYNAMIC_LIB): $(PIC_OBJS)
	mkdir -p ../lib
	$(CC) -shared -o $(DYNAMIC_LIB) $(PIC_OBJS)

# Normal object files for static library
mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o mystrfunctions.o

myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o myfilefunctions.o

# Position Independent object files for dynamic library
mystrfunctions_pic.o: mystrfunctions.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c mystrfunctions.c -o mystrfunctions_pic.o

myfilefunctions_pic.o: myfilefunctions.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c myfilefunctions.c -o myfilefunctions_pic.o

# Main program
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Static executable
$(STATIC_TARGET): $(MAIN) $(STATIC_LIB)
	mkdir -p ../bin
	$(CC) $(CFLAGS) $(MAIN) $(STATIC_LIB) -o $(STATIC_TARGET)

# Dynamic executable
$(DYNAMIC_TARGET): $(MAIN) $(DYNAMIC_LIB)
	mkdir -p ../bin
	$(CC) $(CFLAGS) $(MAIN) -L../lib -lmyutils -o $(DYNAMIC_TARGET)

run: $(DYNAMIC_TARGET)
	LD_LIBRARY_PATH=../lib ./$(DYNAMIC_TARGET)

clean:
	rm -f $(STATIC_TARGET) $(DYNAMIC_TARGET) $(MAIN) $(LIB_OBJS) $(PIC_OBJS) $(STATIC_LIB) $(DYNAMIC_LIB)
install: $(DYNAMIC_TARGET) $(DYNAMIC_LIB)
	mkdir -p /usr/local/bin
	mkdir -p /usr/local/lib
	mkdir -p /usr/local/share/man/man1
	cp $(DYNAMIC_TARGET) /usr/local/bin/client
	cp $(DYNAMIC_LIB) /usr/local/lib/
	cp ../man/man3/*.1 /usr/local/share/man/man1/
