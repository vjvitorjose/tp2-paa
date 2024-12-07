#include "in-out.h"

int leituraSudoku(char* arqentrada, char* arqsaida){

    FILE* entrada = fopen(arqentrada, "r");
    if(!entrada)
        return 0;

    FILE* saida = fopen(arqsaida, "w");
    if(!saida){
        fclose(entrada);
        return 0;
    }

    int** sudoku = criaSudoku();
    if(!sudoku){
        fclose(entrada);
        fclose(saida);
        return 0;
    }

    int i = 0;
    char buffer[19];

    while(!feof(entrada)){

        fgets(buffer, sizeof(buffer), entrada);

        if(i == 8){
            for(int j = 0; j < 9; j++){
                if(buffer[j*2] == 'v')
                    buffer[j*2] = '0';
                sudoku[i][j] = buffer[j*2] - '0';
            }
            resolveSudoku(sudoku);
            escreveSudoku(saida, sudoku);
            i = 0;
            fgets(buffer, sizeof(buffer), entrada);
            continue;
        }

        for(int j = 0; j < 9; j++){
            if(buffer[j*2] == 'v')
                buffer[j*2] = '0';
            sudoku[i][j] = buffer[j*2] - '0';
        }

        i++;

    }

    fclose(entrada);
    fclose(saida);
    freeSudoku(sudoku);
    return 1;

}

int escreveSudoku(FILE* saida, int** sudoku){

    if(!saida || !sudoku)
        return 0;

    for(int i = 0; i < 9; i++){
        fprintf(saida, "%d", sudoku[i][0]);
        for(int j = 1; j < 9; j++){
            fprintf(saida, " %d", sudoku[i][j]);
        }
        fprintf(saida, "\n");
    }

    fprintf(saida, "\n");

    return 1;

}