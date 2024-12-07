#include <stdio.h>
#include <stdlib.h>

#include "sudoku-config.h"

int leituraSudoku(char* arqentrada, char* arqsaida);
int escreveSudoku(FILE* saida, int** sudoku);