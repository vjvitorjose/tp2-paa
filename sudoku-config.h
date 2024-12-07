#include <stdio.h>
#include <stdlib.h>

int** criaSudoku();
void freeSudoku(int** sudoku);

int resolveSudoku(int** sudoku);
int verificaNumero(int** sudoku, int i, int j);
int verificaLinha(int** sudoku, int i, int j);
int verificaColuna(int** sudoku, int i, int j);
int verificaQuadrado(int** sudoku, int i, int j);

void imprimeSudoku(int** sudoku);

void zeraSudoku(int** sudoku);