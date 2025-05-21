#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h> 

using namespace std;

int shared = 1;

void* func1(void*) {
    int x = shared;
    x++;
    sleep(2);
    shared = x;
    cout << "from thread 1, value of shared: " << shared << endl;
    return NULL;
}

void* func2(void*) {
    int y = shared;
    y--;
    sleep(2);
    shared = y;
    cout << "from thread 2, value of shared: " << shared << endl;
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
