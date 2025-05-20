#include<unistd.h>
#include<fcntl.h>

int main(){

int n,fd;
char buf[50];
fd=open("test.txt",O_RDONLY);
n=read(fd,buf,5);
write(1,buf,5);
}
