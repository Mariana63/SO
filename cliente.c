
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
    char buffer[100];
    memset(buffer, 0, 100);
    int n = open("/tmp/Serv", O_WRONLY);


char*   ficheiro ;
    
    write(1, "1- Agregar\n2-Incrementar\n", 25);
    read(0, buffer, 2);

    if (buffer[0] == '1') {
        char* p[3];
        char nivel;
        int nivel2;
        int i = 0;
        write(1, "0, 1 ou 2:\n", 12);
        read(0, buffer, 2);
        if (buffer[0] <= '2' && buffer[0] >= '0') {
            nivel2 = buffer[0] - '0';
            nivel = buffer[0];
            memset(buffer, 0, 100);

            if (nivel2 >= 0) {

                write(1, "Digite distrito:\n", 17);
                read(0, buffer, 30);
                buffer[strlen(buffer) - 1] = '\0';
                p[0] = strdup(buffer);

                memset(buffer, 0, 100);

                if (nivel2 >= 1) {

                    write(1, "Digite Concelho:\n", 17);
                    read(0, buffer, 30);
                    buffer[strlen(buffer) - 1] = '\0';
                    p[1] = strdup(buffer);
                    memset(buffer, 0, 100);
                    if (nivel2 == 2) {
                        write(1, "Digite freguesia:\n", 18);
                        read(0, buffer, 30);
                        buffer[strlen(buffer) - 1] = '\0';
                        p[2] = strdup(buffer);
                        memset(buffer, 0, 100);

                    }
                }
            }


            write(1, "Digite o nome do ficheiro:\n", 28);
                read(0, buffer, 30);

             
             ficheiro = strdup(buffer);

            //mandar para o pipe

             ficheiro[strlen(ficheiro)-1]= '\0';

                write(n, p[0], sizeof (char)*strlen(p[i]));
                  write(n, ":", 1);
                    write(n, "a:", sizeof (char)*2); 
                    write(n, &nivel, 1);
                      write(n, ":", 1);
                      i=1;
            while (i <= nivel2) {
                write(n, p[i], sizeof (char)*strlen(p[i]));
                write(n, ":", 1);
                write(n,ficheiro,sizeof(ficheiro));
                 write(n, ":", 1);
               

                i++;
            }
            write(n, "9", 1);



        }
    }else if (buffer[0] == '2') {
        char* p[3];
        char nivel;
        int nivel2;
        int i = 0;
        write(1, "0, 1 ou 2:\n", 12);
        read(0, buffer, 2);
        if (buffer[0] <= '2' && buffer[0] >= '0') {
            nivel2 = buffer[0] - '0';
            nivel = buffer[0];
            memset(buffer, 0, 100);

            if (nivel2 >= 0) {

                write(1, "Digite distrito:\n", 17);
                read(0, buffer, 30);
                buffer[strlen(buffer) - 1] = '\0';
                p[0] = strdup(buffer);

                memset(buffer, 0, 100);

                if (nivel2 >= 1) {

                    write(1, "Digite Concelho:\n", 17);
                    read(0, buffer, 30);
                    buffer[strlen(buffer) - 1] = '\0';
                    p[1] = strdup(buffer);
                    memset(buffer, 0, 100);
                    if (nivel2 == 2) {
                        write(1, "Digite freguesia:\n", 18);
                        read(0, buffer, 30);
                        buffer[strlen(buffer) - 1] = '\0';
                        p[2] = strdup(buffer);
                        memset(buffer, 0, 100);

                    }
                }
            }




            //mandar para o pipe



                write(n, p[0], sizeof (char)*strlen(p[i]));
                  write(n, ":", 1);
                    write(n, "i:", sizeof (char)*2); 
                    write(n, &nivel, 1);
                      write(n, ":", 1);
                      i=1;
            while (i <= nivel2) {
                write(n, p[i], sizeof (char)*strlen(p[i]));
                write(n, ":", 1);
              

                i++;
            }
             write(n, "9", 1);



        }
    }

    close(n);


    return (1);
}







