#include<iostream>
#include<unistd.h>
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define freq 1
using namespace std;
class logical_clock{
    int f=freq;
    int stop=0;
    char c='0';
    int t=100;
    public:
    void * start(void *);
};
void * logical_clock::start(void * ptr){

    cout<<"clock is going to start";
    int i=0;
    while((!this->stop) || (i<10)){
        this->c= c=='0'?'1':'0';
        cout<<this->c;
        i++;
    }
}
int main()
{
    pthread_t thread_clock;
    char message[]="clock";
    logical_clock lc;
    pthread_create(&thread_clock,NULL,lc.start,(void *)message);
    int i=0;
    
    return 0;
}