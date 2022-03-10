CC := gcc
CFLAGS := -Wall -pedantic
BIN_NAME := files
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
