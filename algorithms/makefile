CC=g++ -std=c++11 -c

CFLAGS=-Wall -ggdb3 -Ilib

SRC=$(wildcard source/*.cpp)

OBJ=$(addprefix bin/,$(notdir $(SRC:.cpp=.o)))


.PHONY: all
.PHONY: clean

all: $(OBJ)

bin/%.o: source/%.cpp
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -rf bin/*.o
