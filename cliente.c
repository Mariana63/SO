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
	char* p[5];
	int discriminacao;

	if(argc>1){
		
		if(fopen(argv[1], "r")){

		
			printf("Indique o nível de discrimizanção que deseja (0, 1 ou 2):\n");
			scanf("%d", &discriminacao);

				if(discriminacao==0 || discriminacao==1 || discriminacao==2){
					char* distrito=NULL;
					printf("Introduza o Distrito:\n");
					scanf("%s", distrito);
					p[0]=distrito;

					if(discriminacao==1 || discriminacao==2){
						printf("Introduza o Concelho:\n");
						char* concelho;
						scanf("%s", concelho);
						p[1]=concelho;


						if(discriminacao==2){
							printf("Introduza a Freguesia:\n");
							char* freguesia;
							scanf("%s", freguesia);
							p[2]=freguesia;
						}
					}
				}
				else printf("ERRO: Nível de discriminação errado.");
		}
		else printf("ERRO: Ficheiro não existe.");
	}

	else printf("ERRO: Não especificou o nome do ficheiro. Por favor, execute novamente.\n");
		


//agregar(p, discriminacao, argv[1]);
printf("%d", discriminacao);
printf("%s", p[0]);
printf("%s", p[1]);
printf("%s", p[2]);
return 0;

}


