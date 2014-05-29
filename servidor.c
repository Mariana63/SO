

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
void main(){
    char buffer[100];
    char*dist[32];
    int pipe[32][2];
    int n=0;
    int r;
   mkfifo("/tmp/Serv",0666);
    int li = open("/tmp/Serv",O_RDONLY);
    while(1){
        
        if((r=read(li,buffer,2))!=0){
        
            if (buffer[0]=='a'){
write(1,"Areg1n",5);            
                
            }
        
        }
    
    
    
    
    }


}