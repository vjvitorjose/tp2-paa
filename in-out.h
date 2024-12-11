#include <stdio.h>
#include <stdlib.h>

#include "sudoku-config.h"

int leituraBacktracking(char* arqentrada, char* arqsaida);
int leituraHeuristica(char* arqentrada, char* arqsaida);
int escreveSudoku(FILE* saida, int** sudoku);