#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"basic.h"
using namespace std;
using namespace gate;

//and gate
char and_gate::input(char x,char y){
    return (x=='1' && x==y) ?'1':'0';
}
char and_gate::input(char x[]){
    char c='1';
    for(int i=0;i<strlen(x);i++)
    {
        c=this->input(c,x[i]);
    }
    return c;
}
char * and_gate::input(char x[],char y[])
{
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);
    }
    return out;
}

//nand gate
char nand_gate::input(char x,char y){
    return (x=='0' && y=='0') ?'1':'0';
}
char nand_gate::input(char x[]){
    char c='0';
    for(int i=0;i<strlen(x);i++)
    {
        c=this->input(c,x[i]);
    }
    return c;
}
char * nand_gate::input(char x[],char y[])
{
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);
    }
    return out;
}

//or gate
char or_gate::input(char x,char y){
    return (x=='1' || y=='1') ?'1':'0';
    }
char or_gate::input(char x[]){
    char c='0';
    for(int i=0;i<strlen(x);i++)
    {
        c=this->input(c,x[i]);
    }
    return c;
}
char * or_gate::input(char x[],char y[])
    {
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);
        }
    return out;
}

//nor gate
char nor_gate::input(char x,char y){
    return (x=='1' || y=='1') ?'0':'1';
    }
char nor_gate::input(char x[]){
    char c='1';
    for(int i=0;i<strlen(x);i++)
    {
        c=this->input(c,x[i]);
    }
    return c;
}
char * nor_gate::input(char x[],char y[])
    {
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);
        }
    return out;
}


//not gate
char not_gate::input(char x){
        return x=='1' ?'0':'1';
    }
char * not_gate::input(char x[])
    {
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i]);
    }
    return out;
}

//xor gate
char xor_gate::input(char x,char y){
    and_gate a1;
    not_gate n1;
    or_gate o1;
    char xnot=n1.input(x);
    char ynot=n1.input(y);
    return o1.input(a1.input(xnot,y),a1.input(x,ynot));
}
char * xor_gate::input(char x[],char y[])
    {
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);}
    return out;
}


//xnor gate
char xnor_gate::input(char x,char y){
    and_gate a1;
    not_gate n1;
    or_gate o1;
    char xnot=n1.input(x);
    char ynot=n1.input(y);
    return o1.input(a1.input(xnot,ynot),a1.input(x,y));
}
char * xnor_gate::input(char x[],char y[])
    {
    int len=strlen(x);
    char *out=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        out[i]=this->input(x[i],y[i]);}
    return out;
}
