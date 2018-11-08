#include<stdio.h>
#include<iostream>
#include"basic.h"
using namespace std;
using namespace gate;
int main(int argc, char const *argv[])
{
    and_gate a;
    char x[]="1011";
    char y[]="00"; 
    char u[]="01";
    char w[]="10";
    char z[]="11";
    mux m;
    dmux dm;
    decoder dc;
    cout<<dc.decode(y)<<endl;
    cout<<dc.decode(u)<<endl;
    cout<<dc.decode(w)<<endl;
    cout<<dc.decode(z)<<endl;
    return 0;
}
