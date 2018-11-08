#include<iostream>
#include<pthread.h>
#include<stdlib.h>
using namespace std;



void * function(void *ptr){
    for(int i=0;i<1000;i++){
        cout <<"thread is running :"<<i<<endl;
    }
    return NULL;
}
int main(){
    pthread_t thread1;
    char message1[]="Thread";
    int iret1=pthread_create(&thread1,NULL,function,(void *)message1);
    for(int i=0;i<1000;i++){
        cout <<"main is running :"<<i<<endl;
    }
}