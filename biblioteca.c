#include <stdio.h>
#include <string.h>


//int incrementar(char *nome[], unsigned valor);

int agregar(char *prefixo[], unsigned nivel, char *path){

	if(fopen(path, "r")){printf("ok\n%s", *prefixo);}
	else printf("n");

	return 1;
}


int main(int argc, char* argv[]){
	FILE *f;
	

	if(argc>1){
		
		if(fopen(argv[1], "r")){

		
		}
		else printf("ERRO: Ficheiro não existe.");
	}

	else printf("ERRO: Não especificou o nome do ficheiro. Por favor, execute novamente.\n");
		


//agregar(p, discriminacao, argv[1]);


return 0;

}


