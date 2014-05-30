

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
void main(){
    char buffer[100];
    char*dist[32];
    int pipe[32][2];
    int n=0,j=0,i =0;
    int r,nivel;
    char*prefixo[3];
    char pref[15];
   mkfifo("/tmp/Serv",0666);
    int li = open("/tmp/Serv",O_RDONLY);
  
    while(1){
        
        if((r=read(li,buffer,2))!=0){
        
          if (buffer[0]=='a'){
                write(1,"ARG\n",5); 
             
                        
             read(li,buffer,1);
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
          // agregar(prefixo,nivel,ficheiro);
            }
          else if (buffer[0]=='i'){
             write(1,"INC\n",5); 
             read(li,buffer,1);
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
             }
                
            }
        
        }
    
    
    
    
    }

}