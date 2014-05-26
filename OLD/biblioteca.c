#include <stdio.h>
#include <string.h>
#include "biblioteca.h"
#include "readfile.h"


int agregar(char *prefixo[], unsigned nivel, char *path){
	char *distrito = strdup(  prefixo[0]);	
  char *concelho= strdup(  prefixo[1]);
  char *freguesia = strdup(  prefixo[2]);
  agrega(distrito,concelho,freguesia,nivel,path);
	return 0;
}



int incrementar(char *nome[], unsigned valor){
  char *distrito = strdup(  nome[0]);	
  char *concelho= strdup(  nome[1]);
  char *freguesia = strdup(  nome[2]);
  populaEstruturas(distrito,concelho,freguesia,valor,1);
  return 0;
}