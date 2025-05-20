#include<stdio.h>
#include<unistd.h>
 int main(){
  printf("hello this is before fork\n");
 pid_t p=fork();
 if(p<0)
{
 printf("There is an error with the process\n");
}
else if(p==0)
{
 printf("child is running with  pid %d\n",getpid());
 printf("my parent pid %d\n",getppid());
 pid_t q=fork();
 printf("i am the siblings of the child\n");
 }
else {
  printf("parent is running with pid %d\n",getpid());
  printf("my child pid %d\n",p);
}
}
