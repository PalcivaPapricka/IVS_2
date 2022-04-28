CC = gcc
CFLAGS = -Wall -std=c11
LDLIBS = -lm

.PHONY: clean test main

all: main test_cc stddev doc

main: count.o
	$(CC) part1.c -o main  `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

test_cc: test.o count.o
	$(CC) test.o count.o -o test $(LDLIBS)

stddev: stddev.o count.o
	$(CC) stddev.o count.o -o stddev $(LDLIBS)

pack: clean
	cd .. && zip -r zipfile.zip *

test:
	./test

doc:
	doxygen Doxyfile
	cd latex && make

run:
	./main

profile:
	./stddev

clean: clean_doc
	rm -f *.o test main stddev

clean_doc:
	rm -f -r latex
