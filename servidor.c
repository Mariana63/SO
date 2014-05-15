#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "biblioteca.h"


int main(int argc, char* argv[]) {

char* p[4]={NULL,NULL,NULL,NULL};


    if ((strcmp(argv[1],"agregar")==0)){
        if(argc!=5) printf("Não especificou corretamente os comandos. Por favor, execute novamente.\nexecutavel agregar nivel prefixo ficheiro\n");
        else agregar(argv[3], atoi(argv[2]), argv[4]);      
    }



    if ((strcmp(argv[1],"incrementar")==0)){
        if(argc<=4) printf("Não especificou corretamente os comandos. Por favor, execute novamente.\nexecutavel incrementar nivel n1 n2 n3 valor\n");
        else {
            int nivel=atoi(argv[2]);
            for(int i=0; i<=nivel; i++) {p[i]=argv[3+i];}
            incrementar(p, argv[nivel+4]);
        }
    }

    return (EXIT_SUCCESS);
}