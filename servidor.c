



void servidor(){
    char*dist[32];
    int pipe[32][2];
    int n=0,r;
   mkfifo("/tmp/Serv",0666);
    int li = open("/tmp/Serv",O_RDONLY);
    while(1){
        
        if((r=read(li,buffer,X))!=0){
        
        
        
        
        }
    
    
    
    
    }


}