#define NUM_THREADS 20
#include <stdio.h>
#include <pthread.h>

int saldo;
pthread_mutex_t saldoLock=PTHREAD_MUTEX_INITIALIZER;

void* suma100(void* arg){
    //cahr* c=(char*)arg;
   //printf("hola crayola desde un hilo \n");
    //pthread_exit(NULL);
    int lsaldo =saldo;
    pthread_mutex_lock(&saldoLock);
    lsaldo=saldo;
    lsaldo+=100;
    saldo = lsaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}

int main(){
    pthread threads[NUM_THREADS];
    saldo=0;
    char* s = "soy un argumento";
    for(int i=0;i<NUM_THREADS;i++){
        pthread_create(&threads[i],NULL,printHola,(void *) s);
    }
    for(int i=0;i<NUM_THREADS;i++){
        pthread_create(&threads[i],NULL);
    }
    pthread_exit(NULL);
}