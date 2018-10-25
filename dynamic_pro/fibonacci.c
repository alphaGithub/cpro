#include<stdio.h>
#define MAX 20
void fibo(int *,int);
void add_to_table(int *,int,int);
int get_from_table(int *,int);
static int count=0;
int main(){
    int arr[MAX];
    int i,n;
    for(int i=0;i<MAX;i++){
        arr[i]=-1;
    }
    printf("ENTER THE NUMBER :");
    scanf("%d",&n);
    fibo(arr,n);
    for(i=0;i<=n;i++){
        printf("%d ->",arr[i]);
    }
    printf("\n\nNumber of calls made :%d",count);
    return 0;
}
void add_to_table(int *arr,int n,int value){
    arr[n]=value;
}
int get_from_table(int *arr,int n){
    return arr[n];
}
void fibo(int *arr,int n){
    int f1,f2,f;
    count++;
    if(n==0){
        add_to_table(arr,n,0);
        return;
    }
    if(n==1)
    {
        add_to_table(arr,n,1);
        return;
    }
    
    f1=get_from_table(arr,n-1);
    f2=get_from_table(arr,n-2);
    if (f1==-1){
        fibo(arr,n-1);
    }
    if (f2==-1){
        fibo(arr,n-2);
    }
    f1=get_from_table(arr,n-1);
    f2=get_from_table(arr,n-2);
    f=f1+f2;
    add_to_table(arr,n,f);
}