CC := /usr/bin/gcc
#CC := arm-linux-gnueabi-gcc

CFLAGS += -fPIC -DPIC

CFLAGS += -I.

LDFLAGS += -L./lib

OBJ = test.o filerw.o filecopy.o

all: serial

serial: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

test.o: test.c filerw.h
	$(CC) -c test.c
filerw.o: filerw.c filerw.h
	$(CC) -c filerw.c
filecopy.o:filecopy.c filerw.h
	$(CC) -c filecopy.c

clean:
	-rm serial $(OBJ)
