#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

int shared = 1;
pthread_mutex_t l;


void* fun1(void*) {
    int x;
    pthread_mutex_lock(&l);
    x = shared;
    x++;
    sleep(2);
    shared = x;
    cout << "Shared value from thread1: " << shared << endl;
    pthread_mutex_unlock(&l);
    return NULL;
}

void* fun2(void*) {
    int y;
    pthread_mutex_lock(&l);
    y = shared;
    y--;
    sleep(2);
    shared = y;
    cout << "Shared value from thread2: " << shared << endl;
    pthread_mutex_unlock(&l);
    return NULL;
}

int main() {
    pthread_mutex_init(&l,NULL);
   cout<<"Initial value of Shared: "<<shared<<endl;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout<<"Final value of shared: "<<shared<<endl;

    return 0;
}
