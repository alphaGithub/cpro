#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"basic.h"

using namespace gate ;

//full adder 
char full_adder::sum(char x,char y,char z){
    xnor_gate x1;
    return x1.input(x1.input(x,y),z);
}
char full_adder::carry(char x,char y ,char z){
    and_gate A,B,C;
    or_gate o1,o2;
    return o2.input(o1.input(A.input(x,y),B.input(y,z)),C.input(x,z));
}
char * full_adder::add(char x[],char y[],char cin){
    int len=strlen(x);
    char * sum=(char *)malloc(sizeof(char)*len);
    for(int i=len-1;i>=0;i--){
        sum[i]=this->sum(x[i],y[i],cin);
        cin=this->carry(x[i],y[i],cin);
    }
    return sum;
}

//multiplexer
char mux::select(char input[],char select[]){
    int n=strlen(input);
    int s=strlen(select);
    int b=1;
    int pos=0;
    for(int i=s-1;i>=0;i--){
        if(select[i]=='1'){
            pos +=b;
        }
        b=b*2;
    }
    return input[n-1-pos];
}