#include<stdio.h>
#include<unistd.h>
int main()
{
    int n;
    char buff[]="hello bro";
    n=write (1,buff,9);
    printf("value of n is %d\n",n);
}
