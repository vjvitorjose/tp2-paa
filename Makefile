all: executavel

executavel: main.o in-out.o sudoku-config.o
	gcc -g main.o in-out.o sudoku-config.o -o executavel

main.o: main.c
	gcc -c main.c

in-out.o: in-out.c
	gcc -c in-out.c

sudoku-config.o: sudoku-config.c
	gcc -c sudoku-config.c

clean:
	rm -f *.o executavel