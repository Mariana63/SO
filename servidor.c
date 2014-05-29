

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
                        
             read(li,buffer,1);
             nivel = buffer[0]-'0';
             printf("---%d---\n",nivel);
            
             //ler ate :
             memset(pref,0,15);
              while( i<nivel){
                 read(li,buffer,1);
                 
                 if(buffer[0]!=':')
                 {printf("ppref %s",pref);
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
           char *  ficheiro = strdup(pref);
           printf("%s\n,%d\n",ficheiro,nivel);
          // agregar(prefixo,nivel,ficheiro);
            }
             if (buffer[0]=='i'){
             write(1,"INC",5);            
                
            }
        
        }
    
    
    
    
    }


}