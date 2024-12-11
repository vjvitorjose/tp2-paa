#include "sudoku-config.h"

int** criaSudoku(){

    int** sudoku = malloc(9*sizeof(int*));
    for(int i = 0; i < 9; i++){
        sudoku[i] = (int*)malloc(9*sizeof(int));
    }
    zeraSudoku(sudoku);
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
    printf("--------------------------------\n");

}

int backtracking(int** sudoku){

    if(sudoku == NULL)
        return 0;

    int** auxiliar = criaAuxiliar(sudoku);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(auxiliar[i][j])
                continue;

            if(sudoku[i][j] == 0)
                sudoku[i][j]++;

            while(!verificaNumero(sudoku, i, j) && sudoku[i][j] <= 9)
                sudoku[i][j]++;

            if(sudoku[i][j] == 10){

                sudoku[i][j] = 0;

                do{
                    if(j > 0){
                        j--;
                    }

                    else{
                        i--;
                        j = 8;
                    }
                }while(auxiliar[i][j] == 1);

                sudoku[i][j]++;
                j--;

            }

        }
    }

    freeSudoku(auxiliar);

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

int** criaAuxiliar(int** sudoku){

    int** auxiliar = malloc(9*sizeof(int*));
    for(int i = 0; i < 9; i++){
        auxiliar[i] = (int*)malloc(9*sizeof(int));
    }

    zeraSudoku(auxiliar);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] != 0)
                auxiliar[i][j] = 1;
        }
    }

    return auxiliar;

}

int heuristica(int** sudoku){

    if(!sudoku)
        return 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0)
                exclusao(sudoku, i, j);
        }
    }

    return 1;

}

int* flagsLinha(int** sudoku, int i, int j){

    int* flags = malloc(9*sizeof(int));

    for(int c = 0; c < 9; c++){
        flags[c] = 0;
    }

    for(int c = 0; c < 9; c++){
        if(sudoku[i][c] != 0)
            flags[sudoku[i][c]-1] = 1;
    }

    return flags;

}

int* flagsColuna(int** sudoku, int i, int j){

    int* flags = malloc(9*sizeof(int));

    for(int l = 0; l < 9; l++){
        flags[l] = 0;
    }

    for(int l = 0; l < 9; l++){
        if(sudoku[l][j] != 0)
            flags[l] = 1;
    }

    return flags;
    
}

int* flagsQuadrado(int** sudoku, int i, int j){

    int* flags = malloc(9*sizeof(int));

    for(int l = 0; l < 9; l++){
        flags[l] = 0;
    }

    for(int l = i-(i%3); l < i-(i%3)+3; l++){
        for(int c = j-(j%3); c < j-(j%3)+3; c++){
            if(sudoku[l][c] != 0)
                flags[(l*3)+c] = 1;
        }
    }

    return flags;

}

int exclusao(int** sudoku, int i, int j){

    if(!exclusaoLinha(sudoku, i, j))
        if(!exclusaoColuna(sudoku, i, j))
            if(!exclusaoQuadrado(sudoku, i, j))
                return 0;
    return 1;

}

int exclusaoLinha(int** sudoku, int i, int j){

    int* flags = flagsLinha(sudoku, i, j);

    int counter = 0;
    for(int c = 0; c < 9; c++){
        if(flags[c] == 1){
            counter++;
        }
    }

    if(counter != 8)
        return 0;

    for(int c = 0; c < 9; c++){
        if(flags[c] == 0)
            sudoku[i][j] = c+1;
    }

    free(flags);
    return 1;

}

int exclusaoColuna(int** sudoku, int i, int j){

    int* flags = flagsColuna(sudoku, i, j);

    int counter = 0;
    for(int l = 0; l < 9; l++){
        if(flags[l] == 1){
            counter++;
        }
    }

    if(counter != 8)
        return 0;

    for(int l = 0; l < 9; l++){
        if(flags[l] == 0)
            sudoku[i][j] = l+1;
    }

    free(flags);
    return 1;

}

int exclusaoQuadrado(int** sudoku, int i, int j){

    int* flags = flagsQuadrado(sudoku, i, j);

    int counter = 0;
    for(int l = 0; l < 9; l++){
        if(flags[l] == 1){
            counter++;
        }
    }

    if(counter != 8)
        return 0;

    for(int l = 0; l < 9; l++){
        if(flags[l] == 0)
            sudoku[i][j] = l+1;
    }

    free(flags);
    return 1;

}

// int solitaria(int** sudoku, int i, int j){

//     if(!solitariaLinha(sudoku, i, j))
//         if(!solitariaColuna(sudoku, i, j))
//             if(!solitariaQuadrado(sudoku, i, j))
//                 return 0;
//     return 1;

// }

// int copiaLinha(int** matriz, int i, int* origem){
//     for(int j = 0; j < 9; j++){
//         matriz[i][j] = origem[j];
//     }
// }

// int solitariaLinha(int** sudoku, int i, int j){

//     int** solucoes = criaSudoku();

//     int* flags = NULL;
//     for(int c = 0; c < 9; c++){
//         if(c != j){
//             flags = flagsLinha(sudoku, i, j);
//             copiaLinha(solucoes, c, flags);
//             free(flags);
//         }
//     }

//     int counter = 0;

//     for(int c = 0; c < 9; c++){
//         for(int l = 0; l < 9; l++){
//             counter += solucoes[l][c];
//             if(counter == 1)
//         }
//     }

//     freeSudoku(solucoes);

// }