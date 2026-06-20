CC=gcc

CFLAGS=-Wall

TARGET=release/fintrack

SRC=src/main.c src/transaction.c src/fileio.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

dist:
	tar -czf dist/fintrack.tar.gz src include Makefile
