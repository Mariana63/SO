
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

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
            nivel = buffer[0];
            write(1, "Digite o prefixo:\nNivel 1:Braga:\nNivel 2 Braga:Braga:\nNivel 3 Braga:Braga:Gualtar:\n", 84);



            if ((read(0, buffer, 30)) != 0) {
                p = strdup(buffer);


                memset(buffer, 0, 100);
                write(1, "Digite o nome do ficheiro:\n", 28);
                read(0, buffer, 30);

                ficheiro = strdup(buffer);
                //mandar para o pipe
                

               

                p[strlen(p) - 1] = '\0';
                write(n, p, sizeof (char)*strlen(p));
                write(n, "a:", sizeof (char)*2);
                 
                ficheiro[strlen(ficheiro) - 1] = '\0';
                write(n, ficheiro, sizeof (ficheiro));

                write(n, ":", 1);
                write(n, &nivel, 1);
            } else {
                /*/erro*/
            }
        } else {
            /*/errro*/
       
        
        }
    } else if (buffer[0] == '2') {
        char* p[3];
        int nivel;
        int i = 0;
        write(1, "0, 1 ou 2:\n", 12);
        read(0, buffer, 2);
        if (buffer[0] <= '2' && buffer[0] >= '0') {
            nivel = buffer[0] - '0';

            memset(buffer, 0, 100);

            if (nivel >= 0) {

                write(1, "Digite distrito:\n", 17);
                read(0, buffer, 30);
                buffer[strlen(buffer) - 1] = '\0';
                p[0] = strdup(buffer);

                memset(buffer, 0, 100);

                if (nivel >= 1) {

                    write(1, "Digite Concelho:\n", 17);
                    read(0, buffer, 30);
                    buffer[strlen(buffer) - 1] = '\0';
                    p[1] = strdup(buffer);
                    memset(buffer, 0, 100);
                    if (nivel == 2) {
                        write(1, "Digite freguesia:\n", 18);
                        read(0, buffer, 30);
                        buffer[strlen(buffer) - 1] = '\0';
                        p[2] = strdup(buffer);
                        memset(buffer, 0, 100);

                    }
                }
            }




            //mandar para o pipe
            
          
           
           
            while (i <= nivel) {
                write(n, p[i], sizeof (char)*strlen(p[i]));
                write(n, ":", 1);

                
                i++;
            }
            write(n, "i:", sizeof (char)*2);
             write(n, &nivel, 1);



        }
    }

    close(n);


    return (1);
}







