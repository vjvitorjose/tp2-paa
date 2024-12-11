#include <stdio.h>
#include <stdlib.h>

int** criaSudoku();
void freeSudoku(int** sudoku);

int backtracking(int** sudoku);
int verificaNumero(int** sudoku, int i, int j);
int verificaLinha(int** sudoku, int i, int j);
int verificaColuna(int** sudoku, int i, int j);
int verificaQuadrado(int** sudoku, int i, int j);

int heuristica(int** sudoku);
int exclusao(int** sudoku, int i, int j);
int exclusaoLinha(int** sudoku, int i, int j);
int exclusaoColuna(int** sudoku, int i, int j);
int exclusaoQuadrado(int** sudoku, int i, int j);

void imprimeSudoku(int** sudoku);

void zeraSudoku(int** sudoku);

int** criaAuxiliar(int** sudoku);