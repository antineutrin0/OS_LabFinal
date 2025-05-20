#include<unistd.h>
int main(){

       int n;    
char buf[50];
     n=read(0,buf,50);
     write(1,buf,n);

}
