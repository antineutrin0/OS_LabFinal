#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> 

using namespace std;

int shared = 1;
sem_t s;

void* fun1(void*) {
    int x;
    sem_wait(&s);
    x = shared;
    x++;
    sleep(2);
    shared = x;
    cout << "Shared value from thread1: " << shared << endl;
    sem_post(&s);
    return NULL;
}

void* fun2(void*) {
    int y;
    sem_wait(&s);
    y = shared;
    y--;
    sleep(2);
    shared = y;
    cout << "Shared value from thread2: " << shared << endl;
    sem_post(&s);
    return NULL;
}

int main() {
    sem_init(&s, 0, 1);
   cout<<"Initial value of shared: "<<shared<<endl;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    cout<<"Final value of shared: "<<shared<<endl;

    return 0;
}

