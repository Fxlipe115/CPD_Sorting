CC=g++ -std=c++11 -c

CFLAGS=-Wall -ggdb3 -I"../algorithms/lib" -O3

LINKER=g++

LIBS=quick_sort heap_sort sorting_alg

ALGDIR=../algorithms/

OBJDIR=$(addprefix $(ALGDIR),bin/)

SRCDIR=$(addprefix $(ALGDIR),source/)

SRC=$(addprefix $(SRCDIR),$(addsuffix .c,$(LIBS)))

OBJ=$(addprefix $(OBJDIR),$(addsuffix .o,$(LIBS)))

MAIN=main.cpp

MAINBIN=$(MAIN:.cpp=.o)

EXEC=$(basename $(MAIN))


.PHONY: all
.PHONY: clean
.PHONY: $(OBJ)

all: $(EXEC)

$(EXEC): $(MAINBIN) $(OBJ)
	$(LINKER) -o $@ $^

$(MAINBIN): $(MAIN)
	$(CC) -o $@ $< $(CFLAGS)

$(OBJ):
	$(MAKE) -C  $(ALGDIR) -s $(addprefix bin/,$(notdir $@))

clean:
	rm -rf $(OBJDIR)*
