#include <stdio.h>
#include <string.h>
#include "biblioteca.h"


int incrementar(char *nome[], unsigned valor);






int agregar(char *prefixo[], unsigned nivel, char *path){

	if(fopen(path, "r")){printf("ok\n%s", *prefixo);}
	else printf("n");

	return 1;
}