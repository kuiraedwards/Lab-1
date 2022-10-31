# list/Makefile
#
# Makefile for list implementation and test file.
#
# Kuira Edwards @02942519
list: main.c list.c
	gcc -o list main.c list.c
