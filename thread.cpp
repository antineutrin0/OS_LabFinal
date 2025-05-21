
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int num[] = {3, 4, 6, 7};

void* sum(void* arg) {
    
      int* num = (int*)arg;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += num[i];
}

     int* result = new int(res);  
      pthread_exit((void*)result); 
}

int main() {
    pthread_t thread1;
    void* result;

    pthread_create(&thread1, NULL, sum, (void*)num);
    pthread_join(thread1, &result);
      int* sum_result = (int*)result;
    cout << "Inside the main process" << endl;
    cout << "The sum is: " << *sum_result << endl;
   

    return 0;
}


