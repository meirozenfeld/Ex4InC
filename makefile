# -*- Makefile -*-
CC=gcc
AR=ar
OBJECTS_Frequency=frequency.o
OBJECTS_Trie=trie.o
FLAGS= -Wall -g

all: libmylib frequency

libmylib: $(OBJECTS_Trie)
	$(AR) -rcs libmylib $(OBJECTS_Trie)	
       
frequency: $(OBJECTS_Trie) $(OBJECTS_Frequency) 
	$(CC) $(FLAGS) -o frequency $(OBJECTS_Trie) $(OBJECTS_Frequency) 	

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c
	
frequency.o: frequency.c trie.h  
	$(CC) $(FLAGS) -c frequency.c

.PHONY: clean all

clean:
	rm -f *.o frequency libmylib