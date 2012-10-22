CC=g++
CFLAGS=-g
all: simplecrypt
	
simplecrypt: main.cpp
	$(CC) $(CFLAGS) -o simplecrypt main.cpp FileFunctions.cpp KeyFunctions.cpp SimpleCrypt.h
	rm -r simplecrypt.dSYM
	
clean:
	rm simplecrypt
	
install:
	cp simplecrypt ~/bin/simplecrypt
