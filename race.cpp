#include<bits/stdc++.h>
#include<pthread.h>

using namespace std;

int shared=1;
void *func1(){

int x=shared;
x++;
sleep(1);
shared=x;
cout<<"from thread 1, value of shared: "<<shared<<endl;
return;
}

void *func2(){


int y=shared;
y--;
sleep(1);
shared=y;
cout<<"from thread 1, value of shared: "<<shared<<endl;
return;
}

int main(){

pthread_t thread1,thread2;
cout<<"Initial value of Shared: "<<shared<<endl;
pthread_create(&thread1,NULL,func1,NULL);
pthread_create(&thread2,NULL,func2,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

cout<<"Final value of Shared: "<<shared<<endl;
return 0;

}
