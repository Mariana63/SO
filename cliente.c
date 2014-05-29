
#include <fcntl.h>

int main(int argc, char*argv[]){
char buffer[100];

int n= open("/tmp/Serv",O_WRONLY);


read(0,buffer,100);
write(n,buffer,sizeof(buffer));




}