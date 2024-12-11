#include "in-out.h"

int leituraSudoku(FILE* file, int** sudoku){
    
}

int leituraBacktracking(char* arqentrada, char* arqsaida){

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

    char buffer[21];

    while(!feof(entrada)){

        fgets(buffer, sizeof(buffer), entrada);

        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                for(int j = 0; j < 3; j++){
                    if(buffer[j*2] == 'v')
                        buffer[j*2] = '0';
                    sudoku[(k*3)+l][j] = buffer[j*2] - '0';
                }
                for(int j = 4; j < 7; j++){
                    if(buffer[j*2-1] == 'v')
                        buffer[j*2-1] = '0';
                    sudoku[(k*3)+l][j-1] = buffer[j*2-1] - '0';
                }
                for(int j = 7; j < 10; j++){
                    if(buffer[j*2] == 'v')
                        buffer[j*2] = '0';
                    sudoku[(k*3)+l][j-1] = buffer[j*2] - '0';
                }
                fgets(buffer, sizeof(buffer), entrada);
            }
            fgets(buffer, sizeof(buffer), entrada);
        }

        backtracking(sudoku);
        escreveSudoku(saida, sudoku);

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

        if(i != 0 && i%3 == 0)
            fprintf(saida, "\n");

        fprintf(saida, "%d", sudoku[i][0]);
        for(int j = 1; j < 9; j++){

            if(j%3 == 0)
                fprintf(saida, " ");

            fprintf(saida, " %d", sudoku[i][j]);

        }

        fprintf(saida, "\n");

    }

    fprintf(saida, "\n\n");

    return 1;

}

int leituraHeuristica(char* arqentrada, char* arqsaida){

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

    char buffer[21];

    while(!feof(entrada)){

        fgets(buffer, sizeof(buffer), entrada);

        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                for(int j = 0; j < 3; j++){
                    if(buffer[j*2] == 'v')
                        buffer[j*2] = '0';
                    sudoku[(k*3)+l][j] = buffer[j*2] - '0';
                }
                for(int j = 4; j < 7; j++){
                    if(buffer[j*2-1] == 'v')
                        buffer[j*2-1] = '0';
                    sudoku[(k*3)+l][j-1] = buffer[j*2-1] - '0';
                }
                for(int j = 7; j < 10; j++){
                    if(buffer[j*2] == 'v')
                        buffer[j*2] = '0';
                    sudoku[(k*3)+l][j-1] = buffer[j*2] - '0';
                }
                fgets(buffer, sizeof(buffer), entrada);
            }
            fgets(buffer, sizeof(buffer), entrada);
        }
        
        heuristica(sudoku);
        escreveSudoku(saida, sudoku);

    }

    fclose(entrada);
    fclose(saida);
    freeSudoku(sudoku);
    return 1;

}