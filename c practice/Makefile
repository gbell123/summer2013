CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -g
EXECUTABLES = testLL testBST

all: $(EXECUTABLES)

testLL: linkedList.c utilities.c linkedlist.h utilities.h
	$(CC) $(CFLAGS) -o testLL linkedList.c utilities.c

testBST: binarySearchTree.c utilities.c binarySearchTree.h utilities.h
	$(CC) $(CFLAGS) -o testBST binarySearchTree.c utilities.c

clean:
	rm testLL
	rm testBST
	rm -r *.dSYM

.PHONY: all clean