#include<unistd.h>
#include<stdio.h>

int main(){

    printf("before exec system call, the process id:%d",getpid());
    execl("bin/ls","ls",NULL);
}
