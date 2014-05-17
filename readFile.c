﻿#include "readFile.h"


//inicializar estrutura
struct Localidades *loc;


void printEstruturas(){
struct Localidades *aux = loc;
    while(aux!= NULL){
        while(aux->prefixo!=NULL){
            if(aux->prefixo->next == NULL) printf("Nº de casos: %d\n", aux->prefixo->c.nrCasos);
             else printf("Região: %s\n", aux->prefixo->c.regiao);    
                
            aux->prefixo=(loc->prefixo)->next;
        }
        printf("NOVA LINHA\n");
        aux=aux->next;
    }
}



void populaEstruturas(char* distrito, char* concelho, char* freguesia, int nrComponentes, int nrCasos){
    Localidade *la = (Localidade*) malloc(sizeof(Localidade));
    la->c.regiao=strdup(distrito);
  
    Localidade *lb  = (Localidade*)malloc(sizeof(Localidade));
    lb->c.regiao=strdup(concelho);


    la->next=lb;
    
    if(nrComponentes==3){
        Localidade *lc  =(Localidade*) malloc(sizeof(Localidade));
        lc->c.regiao=strdup(freguesia);

        lb->next = lc;  
      
       Localidade *ca =(Localidade*) malloc(sizeof(Localidade));
       ca->c.nrCasos = nrCasos;
       ca->next = NULL;

       lc->next = ca;
    }

    else{
        Localidade *cb =(Localidade*) malloc(sizeof(Localidade));
        cb->c.nrCasos = nrCasos;
        cb->next = NULL;

        lb->next = cb;
    }
    
    Localidades *aux = malloc(sizeof(Localidades));
    aux->prefixo = la;
    aux->next = loc;
    loc = aux; 
}



void trataLinha(char* linha){
    char *distrito, *concelho, *freguesia;
    int nrCasos=0;
    char palavra[N]; 
    memset(&palavra, 0, N);
    int i=0, j=0, nrComponentes=0;

      while(linha[i]!= '\n'){
        if(linha[i]==':'){
            nrComponentes++;


            if(nrComponentes==1){distrito=strdup(palavra);}
            if(nrComponentes==2){concelho=strdup(palavra);}
            if(nrComponentes==3){freguesia=strdup(palavra);}
            memset(&palavra, 0, N);
            j=0; i++;
        } 

        else{
            palavra[j]=linha[i];
            i++; j++;
        }
    }
    nrCasos=atoi(palavra);
    populaEstruturas(distrito, concelho, freguesia, nrComponentes, nrCasos);
}


void readFile(char* fileName){
    char linha[N];
    loc = NULL;
    FILE* f = fopen(fileName,"r");


    if(f!= NULL) { while(fgets(linha,N,f)) {trataLinha(linha);}}
    fclose(f);
}


   


