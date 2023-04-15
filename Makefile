# list/Makefile
#
# Makefile for list implementation and test file.
#
# Kuira Edwards @02942519
list: main.c list.c list.h
	gcc -o list list.c main.c -I.
