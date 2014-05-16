#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "biblioteca.h"
#include "readFile.h"
#include "struct.h"


int main() {

   // readFile("info.txt");
    //printEstruturas();

    int escolha;
    printf("1- Agregar\n2-Incrementar\n");
    scanf("%d",&escolha);

    if(escolha==1) {
        char* p[4]={NULL,NULL,NULL,NULL};
        int nivel;
        char prefixo[50];
        char ficheiro[50];


        printf("0, 1 ou 2:\n");
        scanf("%d",&nivel);
        printf("Digite o prefixo:\n");
        scanf("%s", prefixo);
        p[0]=prefixo;
        printf("Digite o nome do ficheiro:\n");
        scanf("%s", ficheiro);

        agregar(p, nivel, ficheiro);
    }



    else if(escolha==2) {
        char* p[4]={NULL,NULL,NULL,NULL};
        int nivel;
        printf("0, 1 ou 2:\n");
        scanf("%d",&nivel);

        if(nivel>=0){
            char distrito[30];
            printf("Digite o Distrito:\n");
            scanf("%s", distrito);
            p[0]=distrito;

                if(nivel>=1){
                    char concelho[30];
                    printf("Digite o Conselho:\n");
                    scanf("%s", concelho);
                    p[1]=concelho;

                        if(nivel==2){
                            char freguesia[30];
                            printf("Digite o Freguesia:\n");
                            scanf("%s", freguesia);
                            p[2]=freguesia;
                        }
                }
        }

        
        int valor;
        printf("Digite o valor a incrementar:\n");
        scanf("%d", &valor);

        incrementar(p, valor);
    }

    else printf("erro escolha\n");    


    return (EXIT_SUCCESS);
}