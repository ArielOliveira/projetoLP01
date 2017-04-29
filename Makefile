multimat = ./bin/multimat

BIN_DIR = ./bin
OBJ_DIR = ./build
LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
DOC_DIR = ./doc
DATA_DIR = ./data
OUTPUT_DIR = ./data/output
TEST_DIR = ./test

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/

OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/matriz.o $(OBJ_DIR)/fileHandler.o


RM = rm -rf

.PHONY: dir doxy clean

$(multimat): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/matriz.o: $(SRC_DIR)/matriz.cpp $(INC_DIR)/matriz.h
	$(CC) -c $(CPPFLAGS) $< -o $@

$(OBJ_DIR)/fileHandler.o: $(SRC_DIR)/fileHandler.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p data
	mkdir -p data/input
	mkdir -p data/output	
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*
	$(RM) $(OUTPUT_DIR)/*
