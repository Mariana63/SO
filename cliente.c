
#include <fcntl.h>
#include <string.h>
#include<stdio.h>
int main(int argc, char*argv[]) {
    char buffer[100];
    memset(buffer, 0, 100);
    int n = open("/tmp/Serv", O_WRONLY);



    int escolha;
    write(1, "1- Agregar\n2-Incrementar\n", 25);
    read(0, buffer, 2);

    if (buffer[0] == '1') {
        char *p;
        char nivel;
        char prefixo[50];
        char *ficheiro;


        write(1, "Nivel 0, 1 ou 2:\n", 17);
        read(0, buffer, 2);
        if (buffer[0] <= '2' && buffer[0] >= '0') {
            nivel= buffer[0];
            write(1, "Digite o prefixo:\nNivel 1:Braga:\nNivel 2 Braga:Braga:\nNivel 3 Braga:Braga:Gualtar:\n", 85);



            if ((read(0, buffer, 30)) != 0) {
                p = strdup(buffer);
               
               
                memset(buffer, 0, 100);
                write(1, "Digite o nome do ficheiro:\n", 28);
                read(0, buffer, 30);

                ficheiro = strdup(buffer);
                //mandar para o pipe
                write(n, "a:", sizeof (char)*2);
                
                write(n, &nivel, 1);
               
                 p[strlen(p)-1] = '\0';
                write(n, p, sizeof (char)*strlen(p));
               
                write(n, ':', 1);
                ficheiro[strlen(ficheiro)-1]='\0';
                write(n, ficheiro, sizeof (ficheiro));
                
                write(n, ':', 1);
            } else {
                /*/erro*/
            }
        } else {
            /*/errro*/
        }













    } else if (buffer[0] == '2') {
        char* p;
        int nivel;
        write(1, "0, 1 ou 2:\n", 12);
        read(0, buffer, 1);
        if (buffer[0] <= 2 && buffer[0] >= 0) {
            nivel = atoi(buffer[0]);


            /*   if (nivel >= 0) {
                   char distrito[30];
                   write(1, "Digite o nome do ficheiro:\n", 28);
                   scanf("%s", distrito);
                   p[0] = distrito;

                   if (nivel >= 1) {
                       char concelho[30];
                       printf("Digite o Conselho:\n");
                       scanf("%s", concelho);
                       p[1] = concelho;

                       if (nivel == 2) {
                           char freguesia[30];
                           printf("Digite o Freguesia:\n");
                           scanf("%s", freguesia);
                           p[2] = freguesia;
                       }
                   }
               }


               int valor;
               printf("Digite o valor a incrementar:\n");
               scanf("%d", &valor);

               //mandar para o pipe*/
        }
    }

    close(n);


    return (1);
}







