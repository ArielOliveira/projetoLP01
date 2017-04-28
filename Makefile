multimat = ./bin/multimat

BIN_DIR = ./bin
OBJ_DIR = ./build
LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
DATA_DIR = ./data
TEST_DIR = ./test

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/

OBJS = $(OBJ_DIR)/main.o

RM = rm -rf

.PHONY: dir doxy clean

$(multimat): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

dir:
	mkdir bin
	mkdir build
	mkdir data
	mkdir include
	mkdir src
	mkdir doc
	mkdir lib
	mkdir test

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	$(RM) $(OBJ_DIR)/* $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*
