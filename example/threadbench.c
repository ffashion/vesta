#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int i=0;

int main(int argc, char const *argv[]){
    // for(int i=0;i<=;i++){

    // }
    pthread_t worker;
    pthread_mutex_lock(&mutex);
    for (; i <=10000000; i++){
       
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}
