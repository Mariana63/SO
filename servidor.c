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
    int i=0, f=-1;
    while (i<n && f==-1) {
        if ((strcmp(dist[i], s)) == 0) {
            printf("AKI D\n"); f=i;}
        else i++;
    }
return f;
}

int incrementar(char* nome[], unsigned  valor, int g){
    //fazer

    return 1;
}


int agregar(char* prefixo[], unsigned nivel, char* path, int g){
    //fazer

    return 1;
}

//li = :nivel(:c:f):ficheiro:9
void parseA(int g, int li, char* distrito){
    int fl2 = 0, j=0;
    char nivel;
    int nn;
    char buffer[50]; memset(buffer, 0, 50);
    char conc[15]; memset(conc, 0, 15);
    char freg[15]; memset(freg, 0, 15);
    char fic[15]; memset(fic, 0, 15);
    int n=0;


        if ((read(li, buffer, 1)) != 0 && (!fl2)){
            //NIVEL
            if(n==0){
                if(buffer[0]==':') read(li, buffer, 1);
                nivel = buffer[0];
                write(pipek[g][1], &nivel, 1);
                n=1; j=0;
                read(li, buffer, 1);
            }
            nn = atoi(&nivel);
            
                //CONCELHO
                if(n==1){
                    if(buffer[0]==':') read(li, buffer, 1);
                    conc[j] = buffer[0]; j++;

                    while (buffer[0]!=':'){
                        read(li, buffer, 1);
                        conc[j] = buffer[0];
                        j++;
                    }

                    conc[j-1] = '\0';
                    write(pipek[g][1], conc, strlen(conc));
                    n=2; j=0;
                }

                
                 //FREGUESIA
                if(n==2){
                    if(buffer[0]==':') read(li, buffer, 1);
                    freg[j] = buffer[0]; j++;

                    while (buffer[0]!=':'){
                        read(li, buffer, 1);
                        freg[j] = buffer[0];
                        j++;
                    }

                    freg[j-1] = '\0';
                    write(pipek[g][1], freg, strlen(freg));
                    n=3; j=0;
                }
            

            //FICHEIRO
            if(n==3){
                if(buffer[0]==':') read(li, buffer, 1);
                fic[j] = buffer[0]; j++;

                while (buffer[0]!=':'){
                    read(li, buffer, 1);
                    fic[j] = buffer[0];
                    j++;
                }

                fic[j-1] = '\0';
                write(pipek[g][1], fic, strlen(fic));
                n=4; j=0;
            }

        }
    char* nome[3];
    nome[0]=strdup(distrito);
    nome[1]=strdup(conc);
    nome[2]=strdup(freg);

    agregar(nome,nn,fic, g);
}


//li == :c:f:valor:9
void parseI(int g, int li, char* distrito){
    int fl2 = 0, j=0;
    char buffer[50]; memset(buffer, 0, 50);
    char valor[100]; memset(valor, 0, 100);
    char conc[15]; memset(conc, 0, 15);
    char freg[15]; memset(freg, 0, 15);
    int n=0;


        if ((read(li, buffer, 1)) != 0 && (!fl2)){
            //CONCELHO
            if(n==0){
                if(buffer[0]==':') read(li, buffer, 1);
                conc[j] = buffer[0]; j++;

                while (buffer[0]!=':'){
                    read(li, buffer, 1);
                    conc[j] = buffer[0];
                    j++;
                }

                conc[j-1] = '\0';
                write(pipek[g][1], conc, strlen(conc));
                n=1; j=0;
            }

            //FREGUESIA
            if(n==1){
                if(buffer[0]==':') read(li, buffer, 1);
                freg[j] = buffer[0]; j++;

                while (buffer[0]!=':'){
                    read(li, buffer, 1);
                    freg[j] = buffer[0];
                    j++;
                }

                freg[j-1] = '\0';
                write(pipek[g][1], freg, strlen(freg));
                n=2; j=0;
            }

            //VALOR
             if(n==2){
                if(buffer[0]==':') read(li, buffer, 1);
                valor[j] = buffer[0]; j++;

                while (buffer[0]!=':'){
                    read(li, buffer, 1);
                    valor[j] = buffer[0];
                    j++;
                }

                valor[j-1] = '\0';
                write(pipek[g][1], valor, strlen(valor));
                n=2; j=0;
            }
        }
    char* nome[3];
    nome[0]=strdup(distrito);
    nome[1]=strdup(conc);
    nome[2]=strdup(freg);
    unsigned valor2 = atoi(valor);
    incrementar(nome, valor2, g);
}


//ler do li e escrever para o g (pipek[g][1])
void existe(int g, int li, char* distrito){
    int fl = 0;
    char buffer[50];
        
        while ((read(li, buffer, 1)) != 0 && !fl) {
            if (buffer[0]=='9') {
                write(pipek[g][1], (&buffer[0]), 1); 
                fl = 1;
            }
            else write(pipek[g][1],(&buffer[0]), 1);
        }
}



void naoExiste(int g, int li, char* distrito){
    char buffer[15];
    dist[n] = strdup(distrito);
    printf("distrito NOVO:%s\n",dist[n]);
    pipe(pipek[n]);
    n++;
    

    if(!fork()) {
        char *Dist = strdup(distrito);
        close(pipek[n-1][1]);
        
            while(1){
                if((read(pipek[n-1][0],buffer,1))!=0){
                    if (buffer[0]=='a') {parseA(g, li, distrito);}
                    else if (buffer[0]=='i') {parseI(g, li, distrito);}
                    printf("--%c--\n",buffer[0]);   
                }
            }
    }

    else {
        close(pipek[n-1][0]);
        int fl = 0;
        while ((read(li, buffer, 1)) != 0&& !fl) {
            if (buffer[0]=='9') {
                write(pipek[n - 1][1], (&buffer[0]), 1);
                fl = 1;
            }

            else write(pipek[n - 1][1], (&buffer[0]), 1); 
        }
    }
}




int main() {
    char buffer[50], pref[15];
    int j=0, i = 0, f = 0, r, nivel; n = 0;

    mkfifo("/tmp/Serv", 0666);
    int li = open("/tmp/Serv", O_RDONLY);

    while (1) {
        if ((r = read(li, buffer, 1)) != 0) {
            j=0; memset(pref, 0, 15);
            pref[j] = buffer[0]; j++;
         
                while (buffer[0] != ':'){
                    read(li, buffer, 1);
                    pref[j] = buffer[0];
                    j++;
                }

                pref[j-1] = '\0';
               
                int g = fAct(pref);
                if (g != -1) existe(g, li, pref);
                else naoExiste(g, li, pref);
        }
    }

    return (EXIT_SUCCESS);
}

