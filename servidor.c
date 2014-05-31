

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
char*dist[32];
int pipek[32][2];
int n;

int fAct(char*s) {

    int i = 0, f = -1;
    while (i < n && f == -1) {
        if ((strcmp(dist[i], s)) == 0) {
            f = i;
        } else i++;

    }
    return f;
}

void main() {
    char buffer[100];
    n = 0;
    int j = 0, i = 0, f = 0;
    int r, nivel;
   
    char pref[15];
    mkfifo("/tmp/Serv", 0666);
    int li = open("/tmp/Serv", O_RDONLY);

    while (1) {

        if ((r = read(li, buffer, 2)) != 0) {

            if (buffer[0] == 'a') {
                write(1, "ARG\n", 5);
                while (buffer[0] != ':') {
                    read(li, buffer, 1);
                    pref[j] = buffer[0];
                    j++;
                }
                pref[j] = '\0';
                int g = fAct(pref);
                if (g != -1) {
                    while ((read(li, buffer, 1)) != 0) {
                        if (buffer[0] >= '1' && buffer[0] <= '9') {
                            write(pipek[g][1], buffer[0], 1);
                            break;
                        } else {
                            write(pipek[g][1], buffer[0], 1);
                        }

                        //mandar para o filho pelo pipe g
                    }
                } else {
                    dist[n] = strup(pref);
                    pipe(pipek[n]);
                    n++;

                    if (!fork()) {
                        close(pipek[n][1]);

                    } else {
                        close(pipek[n][0]);
                        while ((read(li, buffer, 1)) != 0) {
                            if (buffer[0] >= '1' && buffer[0] <= '9') {
                                write(pipek[n - 1][1], buffer[0], 1);
                                break;
                            } else {
                                write(pipek[n - 1][1], buffer[0], 1);
                            }
                        }//fork pa novo filho; add novo dist a lista e mandar pelo pipe

                    }
                }

            } else if (buffer[0] == 'i') {
                write(1, "INC\n", 5);
                while (buffer[0] != ':') {
                    read(li, buffer, 1);
                    pref[j] = buffer[0];
                    j++;
                }
                pref[j] = '\0';
                int g = fAct(pref);
                if (g != -1) {
                    while ((read(li, buffer, 1)) != 0) {
                        if (buffer[0] >= '1' && buffer[0] <= '9') {
                            write(pipek[g][1], buffer[0], 1);
                            break;
                        } else {
                            write(pipek[g][1], buffer[0], 1);
                        }

                        //mandar para o filho pelo pipe g
                    }
                } else {
                    dist[n] = strup(pref);
                    pipe(pipek[n]);
                    n++;

                    if (!fork()) {
                        close(pipek[n][1]);

                    } else {
                        close(pipek[n][0]);
                        while ((read(li, buffer, 1)) != 0) {
                            if (buffer[0] >= '1' && buffer[0] <= '9') {
                                write(pipek[n - 1][1], buffer[0], 1);
                                break;
                            } else {
                                write(pipek[n - 1][1], buffer[0], 1);
                            }
                        }//fork pa novo filho; add novo dist a lista e mandar pelo pipe

                    }
                }
            }

        }


    }
}
    /* read(li,buffer,1);
                 nivel = buffer[0];
                 printf("nI:%d\n",nivel);
                  memset(pref,0,15);
                  while( i<=nivel){
                 
                     read(li,buffer,1);
                      printf("I:-%c- \n",buffer[0]);
                     if(buffer[0]==':')
                     {printf("I,cenas.%s\n",pref);
                     char *aux = strdup(pref);
                         prefixo[i] = aux;
                         memset(pref,0,15);
                         i++;
                         j=0;
                     }else
                     {
                 
                
                     pref[j] = buffer[0];
                     j++;
                
                     }
                  printf("NivelI: %d,prefixo %s-buff-%c",i,prefixo[i],buffer[0]);  
                 }*/

    /*read(li,buffer,1);
                 nivel = buffer[0]-'0';
                 printf("nA:%d\n",nivel);
            
        
                 memset(pref,0,15);
               
                  while( i<=nivel){
                  
                     read(li,buffer,1);
                     printf("A:-%c-\n",buffer[0]);
                     if(buffer[0]==':')
                     {printf("A,cenas\n");
                         prefixo[i] = strdup(pref);
                         memset(pref,0,15);
                         i++;
                     }else
                     {
                 
                
                     pref[j] = buffer[0];
                     j++;
                
                     }
                 
                 }
                 j=0;
                 while(buffer[0]!=':'){
                 
                     pref[j]= buffer[0];
                }
                 pref[strlen(pref)-1]='\0';
               char *  ficheiro = strdup(pref);
             printf("NiVA: %d, %s-%c",nivel,ficheiro,buffer[0]); 
              // agregar(prefixo,nivel,ficheiro);*/