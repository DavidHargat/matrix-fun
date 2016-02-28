
SRC=main.c
DEP=matrix.h
LIB=-lm
OPT=-Wall -I.

all: main
.PHONY: all

clean:
	rm main
.PHONY: clean

run: all
	./main
.PHONY: run

main: $(SRC) $(DEP)
	gcc $(OPT) -o $@ $^ $(LIB)

