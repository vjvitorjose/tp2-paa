#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "in-out.h"
#include "sudoku-config.h"

int main(int argc, char** argv){

    int opt;
    char entrada[100];
    char saida[100];

    
    while((opt = getopt(argc, argv, "a:b:")) != -1){
        
        switch(opt){

            case 'a':
                strcpy(entrada , optarg);
                break;

            case 'b':
                strcpy(saida , optarg);
                break;

        }
    }

    leituraHeuristica(entrada, saida);

    return 0;

}