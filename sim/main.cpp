#include<stdio.h>
#include<iostream>
#include"basic.h"
using namespace std;
using namespace gate;
int main(int argc, char const *argv[])
{
    and_gate a;
    char x[]="1011";
    char y[]="10";  
    mux m;
    cout<<m.select(x,y); 
    return 0;
}
