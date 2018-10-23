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

int pivot(int *arr,int p,int r,int order){
   int k=arr[r];
    int j;
    int i=p-1;
    for(j=p;j<=r-1;j++){
        if(order?(arr[j]>k):(arr[j]<k))
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    arr[r]=arr[i+1];
    arr[i+1]=k;
    return i+1;
}

void quick_sort(int *arr,int p,int r,int order){
    if(p<r){
    int q=pivot(arr,p,r,order);
    quick_sort(arr,p,q-1,order);
    quick_sort(arr,q+1,r,order);
    }
}

void merge(int *arr,int p,int q,int r,int order){
    int n1=q-p+1;
    int n2=r-q;
    int left[n1],right[n2];
    int i,j,k;
    for(i=p,k=0;i<=q;i++,k++)
        left[k]=arr[i];
    for(j=q+1,k=0;j<=r;j++,k++)
        right[k]=arr[j];
    i=0;j=0;k=p;
    while(i<n1 && j< n2){
        if(order?(left[i]>right[j]):(left[i]<right[j])){
            arr[k]=left[i];
            i++;k++;
        }
        else{
            arr[k]=right[j];
            j++;k++;
        }
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}
void merge_sort(int *arr,int p ,int r,int order){
    if(p<r){
        int q=(p+r)/2;
        merge_sort(arr,p,q,order);
        merge_sort(arr,q+1,r,order);
        merge(arr,p,q,r,order);
    }
}
void max_heapify(int *arr,int pos,int heap_size){
    int l_child,r_child,largest;
    l_child=(2*(pos));
    r_child=(2*(pos))+1;
    largest=pos;
    if(l_child<=heap_size && arr[l_child] > arr[pos]){
        largest=l_child;
    }
    else if(r_child<=heap_size && arr[r_child] >arr[pos]){
        largest=r_child;
    }
    if(largest!=pos){
        swap(&arr[pos],&arr[largest]);
        max_heapify(arr,largest,heap_size);
    }
    printf("heap :%d %d %d \n",l_child,r_child,largest);
}
void build_heap(int *arr,int len){
    int heap_size=len,i;
    for(i=len/2-1;i>=0;i--){
        max_heapify(arr,i,heap_size);
        display_array(arr,7);
    }
    display_array(arr,len);
}