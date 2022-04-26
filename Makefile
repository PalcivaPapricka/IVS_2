CC = gcc
CFLAGS = -Wall -std=c11
LDLIBS = -lm
TOZIP = $(wildcard *.c) $(wildcard *.h) README.md

.PHONY: clean test main

all: main test_cc stddev

main:

test_cc: test.o count.o
	$(CC) test.o count.o -o test $(LDLIBS)

stddev: stddev.o count.o
	$(CC) stddev.o count.o -o stddev $(LDLIBS)

pack:
	TODO zabali projekt pro odevzdani asi pomoci promenne TOZIP

test:
	./test

doc:
	TODO generovani dokumentace

run:
	TODO spusti program

profile:
	TODO spusti program pro smerodatnou odchylku

clean:
	rm *.o test main stddev