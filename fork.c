#include<stdio.h>
#include<unistd.h>
int main(){
    fork();
    fork();
   printf("hello i am process Pid=%d \n",getpid());
}
