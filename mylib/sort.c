#include<stdio.h>
void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
void bubble_sort(int *arr,int len,int order){
    int i,j;
    for(i=0;i<len;i++){
        for(j=0;j<len-i-1;j++){
            if(order?(arr[j]<arr[j+1]):(arr[j]>arr[j+1])){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}