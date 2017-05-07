CC=g++ -std=c++11 -c

LINKER=g++

CFLAGS=-Wall -I./lib -O2

SRC=$(wildcard source/*.cpp)

OBJ=$(addprefix bin/,$(notdir $(SRC:.cpp=.o)))

EXEC=main

all: $(OBJ)
#comment on windows
	@mkdir -p data/times
	@mkdir -p data/stats
	$(LINKER) -o $(EXEC) $^ $(LFLAGS)

bin/%.o: source/%.cpp
#comment on windows
	@mkdir -p bin
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm 	bin/*.o
