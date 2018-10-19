#include<stdio.h>
#include "mylib.h"
void display_array(int *arr,int len){
    int i=0;
    printf("ARRAY : ");
    for(i=0;i<len;i++){
        printf("%d ->",arr[i]);
    }
    printf("\n");
}
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
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void insertion_sort(int *arr,int len,int order){
    int i,j,k;
    for(i=1;i<len;i++){
        k=arr[i];
        j=i-1;
        for(j=i-1;j>=0 && (order?(k>arr[j]):(k<arr[j]));){
            arr[j+1]=arr[j];
            j=j-1;
            }
            arr[j+1]=k;
        }
    }
