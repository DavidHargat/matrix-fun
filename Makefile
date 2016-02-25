
all: main
.PHONY: all

clean:
	rm main
.PHONY: clean

run: all
	./main
.PHONY: run

main: main.c
	gcc -Wall -o main main.c -I.

