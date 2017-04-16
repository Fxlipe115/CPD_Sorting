CC=g++ -std=c++11 -c

LINKER=g++

CFLAGS=-Wall -I./lib -O2

SRC=$(wildcard source/*.cpp)

OBJ=$(addprefix bin/,$(notdir $(SRC:.cpp=.o)))

EXEC=main

all: $(OBJ)
#uncomment on linux
#	@mkdir -p times
#	@mkdir -p stats
	$(LINKER) -o $(EXEC) $^ $(LFLAGS)

bin/%.o: source/%.cpp
#uncomment on linux
#	@mkdir -p bin
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm 	bin/*.o
