#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char*dist[32];
int pipek[32][2];
int n;

int fAct(char*s) {

    int i = 0, f = -1;
    while (i < n && f == -1) {
        if ((strcmp(dist[i], s)) == 0) {
         
            printf("AKI D\n");
            f = i;
        } else i++;

    }
    return f;
}

int main() {
    char buffer[100];
    n = 0;
    int j = 0, i = 0, f = 0;
    int r, nivel;
   
    char pref[15];
    mkfifo("/tmp/Serv", 0666);
    int li = open("/tmp/Serv", O_RDONLY);

    while (1) {

        if ((r = read(li, buffer, 1)) != 0) {
            j=0;
            memset(pref, 0, 15);
           pref[j] = buffer[0];
           j++;
         
                while (buffer[0] != ':') {
                    read(li, buffer, 1);
                    pref[j] = buffer[0];
                    j++;
                }
                pref[j-1] = '\0';
               
                int g = fAct(pref);
                if (g != -1) {
                    int fl2 = 0;
                    write(pipek[g][1], pref, strlen(pref));
                        write(pipek[g][1], ":", sizeof (char));
                    while ((read(li, buffer, 1)) != 0 && (!fl2)) {
                        if (buffer[0] == '9') {
                            printf("Acabou de mandar para o que existe_:\n");
                            write(pipek[g][1], (&buffer[0]), 1);
                            fl2=1;
                        } else {
                            write(pipek[g][1], (&buffer[0]), 1);
                           
                        }

                        //mandar para o filho pelo pipe g
                    }
                } else {
                    dist[n] = strdup(pref);
                    printf("distrito NOVO:%s\n",dist[n]);
                    pipe(pipek[n]);
                    n++;
                    

                    if (!fork()) {
                        char *Dist = strdup(pref);
                         
                        close(pipek[n-1][1]);
                        
                        while(1){
                        
                            if((read(pipek[n-1][0],buffer,1))!=0){
                                
                                 if ( buffer[0] == '9'){
                                 
                                 
                                 }
                                printf("--%c--\n",buffer[0]);
                                
                            }
                        
                        
                        
                        }
                        

                    } else {
                        close(pipek[n-1][0]);
                          
                       write(pipek[n-1][1], pref, strlen(pref));
                        write(pipek[n-1][1], ":", sizeof (char));
                        int fl = 0;
                        while ((read(li, buffer, 1)) != 0&& !fl) {
                            if (buffer[0] >= '1' && buffer[0] <= '9') {  
                                printf("Acaboude mandar po filho novo:\n");
                                
                                write(pipek[n - 1][1], (&buffer[0]), 1);
                                
                                fl = 1;
                            } else {
                                write(pipek[n - 1][1], (&buffer[0]), 1);
                                
                            }
                        }//fork pa novo filho; add novo dist a lista e mandar pelo pipe

                    }
                }

           

        }


    }

    return (EXIT_SUCCESS);
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