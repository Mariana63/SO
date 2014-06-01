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


//d:a:nivel(:c:f):9
void parseA(int g, int li, char* distrito){
    int fl2 = 0;
    char buffer[50];
    int nivel=-1;
        
        write(pipek[g][1], "A", 1);
        while ((read(li, buffer, 1)) != 0 && (!fl2)){

            if (buffer[0]=='0' || buffer[0]=='1' || buffer[0]=='2'){
                nivel = buffer[0];
            }
            else if (buffer[0] == '9'){
                write(pipek[g][1], "FIM", 3); fl2=1;
            }

            else write(pipek[g][1], (&buffer[0]), 1);
        }
}


//li == :c:f:valor:9
void parseI(int g, int li, char* distrito){
    int fl2 = 0, j=0;
    char buffer[50]; memset(buffer, 0, 50);
    char valor[100]; memset(valor, 0, 100);
    char conc[15]; memset(conc, 0, 15);
    char freg[15]; memset(freg, 0, 15);
    char lixo[3];
    write(pipek[g][1], "I", 1);


        while ((read(li, buffer, 1)) != 0 && (!fl2)){

            //if(buffer[0]==':') buffer[0]='*';

            //CONCELHO
            while (buffer[0]!=':'){
                j=0;
                memset(conc, 0, 15);
                read(li, buffer, 1);
                conc[j] = buffer[0]; j++;
            }
            conc[j-1] = '\0';
            write(pipek[g][1], conc, strlen(conc));

            //TIRAR :

            //FREGUESIA
            while (buffer[0]!=':'){
                j=0;
                memset(freg, 0, 15);
                read(li, buffer, 1);
                freg[j] = buffer[0]; j++;
            }
            freg[j-1] = '\0';
            write(pipek[g][1], freg, strlen(freg));

            //TIRAR :

            //VALOR
            while (buffer[0]!=':'){
                j=0;
                memset(valor, 0, 15);
                read(li, buffer, 1);
                valor[j] = buffer[0]; j++;
            }
            valor[j-1] = '\0';
            write(pipek[g][1], valor, strlen(valor));



            if (buffer[0] == '9'){
                write(pipek[g][1], "FIM", 3); fl2=1;
            }
        }

    //incrementar();
}


//ler do li e escrever para o g (pipek[g][1])
//escrever em g: "d:c:f:valor"
void existe(int g, int li, char* distrito){
    int fl2 = 0;
    char buffer[50];
        
        write(pipek[g][1], distrito, strlen(distrito));
        write(pipek[g][1], ":", sizeof (char));
        while ((read(li, buffer, 1)) != 0 && (!fl2)){

            if (buffer[0]=='a') parseA(g, li, distrito);
            
            else if (buffer[0]=='i') parseI(g, li, distrito);

            else if (buffer[0] == '9'){
                write(pipek[g][1], "FIM", 3); fl2=1;
            }

            else write(pipek[g][1], (&buffer[0]), 1);
        }
}



void naoExiste(int g, int li, char* pref){
    char buffer[15];
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


            if (buffer[0]=='9') {  
                printf("Acaboude mandar po filho novo:\n");
                
                write(pipek[n - 1][1], (&buffer[0]), 1);
                
                fl = 1;
            } else {
                write(pipek[n - 1][1], (&buffer[0]), 1);
                
            }
        }//fork pa novo filho; add novo dist a lista e mandar pelo pipe

    }

}




int main() {
    char buffer[50], pref[15];
    int j=0, i = 0, f = 0, r, nivel;
    n = 0;

   
    mkfifo("/tmp/Serv", 0666);
    int li = open("/tmp/Serv", O_RDONLY);

    while (1) {
        if ((r = read(li, buffer, 1)) != 0) {
            j=0; memset(pref, 0, 15);
            pref[j] = buffer[0]; j++;
         
                while (buffer[0] != ':') {
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

