#include <stdio.h>
#include <string.h>
#include "biblioteca.h"


int agregar(char *prefixo[], unsigned nivel, char *path){
	printf("AGREGAR - BIBLIOTECA\n");
	printf("%s\n", prefixo[0]);
	printf("%s\n", prefixo[1]);
	printf("%s\n", prefixo[2]);
	printf("%d\n", nivel);
	printf("%s\n", path);
	return 0;
}



int incrementar(char *nome[], unsigned valor){
	printf("INCREMENTAR - BIBLIOTECA\n");
	printf("%s\n", nome[0]);
	printf("%s\n", nome[1]);
	printf("%s\n", nome[2]);
	printf("%d\n",valor);
	return 0;
}