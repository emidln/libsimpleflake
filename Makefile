AR=ar
CC=gcc
EXE_CFLAGS=-Wall -Wextra -O2 -g -pedantic
EXE_LDFLAGS=-lbsd
STATIC_LIB_CFLAGS=$(EXE_CFLAGS)
STATIC_LIB_LDFLAGS=$(EXE_LDFLAGS)
SHARED_LIB_CFLAGS=$(EXE_CFLAGS) -fPIC
SHARED_LIB_LDFLAGS=$(EXE_LDFLAGS) -shared

all: clean build run

libsimpleflake.a:
	$(CC) ${STATIC_LIB_CFLAGS} -c libsimpleflake.c
	$(AR) -cvq libsimpleflake.a libsimpleflake.o

libsimpleflake.so:
	$(CC) ${SHARED_LIB_CFLAGS} ${SHARED_LIB_LDFLAGS} -o libsimpleflake.so libsimpleflake.c

simpleflake: libsimpleflake.a
	$(CC) ${EXE_CFLAGS} ${EXE_LDFLAGS} -o simpleflake simpleflake.c libsimpleflake.a

build: simpleflake libsimpleflake.so

run: build
	chmod 755 simpleflake
	./simpleflake

clean:
	rm -f simpleflake libsimpleflake.o libsimpleflake.so libsimpleflake.a

.PHONY: all build clean run
