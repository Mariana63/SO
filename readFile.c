#include "readFile.h"
#include "struct.h"


struct Localidades *loc;


void printEstruturas(){

}



void populaEstruturas(char* distrito, char* concelho, char* freguesia, int nrComponentes, int nrCasos){
  
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


   


