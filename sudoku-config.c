#include "sudoku-config.h"

int** criaSudoku(){

    int** sudoku = malloc(9*sizeof(int*));
    for(int i = 0; i < 9; i++){
        sudoku[i] = (int*)malloc(9*sizeof(int));
    }
    return sudoku;

}

void freeSudoku(int** sudoku){

    if(!sudoku)
        return;

    for(int i = 0; i < 9; i++){
        free(sudoku[i]);
    }
    free(sudoku);
    
}

void imprimeSudoku(int** sudoku){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

}

int resolveSudoku(int** sudoku){

    if(sudoku == NULL)
        return 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(sudoku[i][j] == 0)
                sudoku[i][j]++;

            while(!verificaNumero(sudoku, i, j) && sudoku[i][j] <= 9)
                sudoku[i][j]++;

            if(sudoku[i][j] == 10){

                sudoku[i][j] = 0;

                if(j > 0){
                    j -= 2;
                }

                else{
                    i--;
                    j = 7;
                }

                sudoku[i][j+1]++;

            }

        }
    }

    return 1;

}

int verificaNumero(int** sudoku, int i, int j){

    if(!verificaLinha(sudoku, i, j))
        return 0;
    if(!verificaColuna(sudoku, i, j))
        return 0;
    if(!verificaQuadrado(sudoku, i, j))
        return 0;

    return 1;

}

int verificaLinha(int** sudoku, int i, int j){

    for(int c = 0; c < 9; c++){
        if(c == j)
            continue;
        if(sudoku[i][c] == sudoku[i][j])
            return 0;
    }

    return 1;

}

int verificaColuna(int** sudoku, int i, int j){

    for(int l = 0; l < 9; l++){
        if(l == i)
            continue;
        if(sudoku[l][j] == sudoku[i][j])
            return 0;
    }

    return 1;

}

int verificaQuadrado(int** sudoku, int i, int j){

    for(int l = i-(i%3); l < i-(i%3)+3; l++){
        for(int c = j-(j%3); c < j-(j%3)+3; c++){
            if(l == i && c == j)
                continue;
            if(sudoku[l][c] == sudoku[i][j])
                return 0;
        }
    }

    return 1;

}

void zeraSudoku(int** sudoku){

    if(!sudoku)
        return;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = 0;
        }
    }

}