#include<stdio.h>
#include "mylib.h"
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void display_array(int *arr,int len){
    int i=0;
    printf("\nArray ->");
    for(i=0;i<len;i++){
        printf("%d ->",arr[i]);
    }
    printf("\n");
}
void bubble_sort(int *arr,int len,int order){
    int i,j;
    for(i=0;i<len-1;i++){
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
        for(j=i-1;j>=0 && (order?(arr[j]<k):(arr[j]>k));j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
    }
}
void selection_sort(int *arr,int len,int order){
    int i,j,max,min,pos;
    for(i=0;i<len-1;i++){
        min=max=arr[i];
        pos=i;
        for(j=i;j<len;j++){
            if(order?(arr[j]>max):(arr[j]<min)){
                if(order)
                    {
                    min=arr[j];
                    pos=j;
                    }
                else{
                    max=arr[j];
                    pos=j;
                }
                    
            }
            if(pos!=i){
                swap(&arr[pos],&arr[i]);
            }
        }
    }
}

int pivot(int *arr,int p,int  r,int order){
    int i,j;
    int k=arr[r];
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(order?(arr[j]>k):(arr[j]<k)){
            i += 1;
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
    int left[n1];
    int right[n2];
    int i,j,k=p;
    for(i=0;i<n1;i++){ left[i]=arr[k++];}
    for(j=0;j<n2;j++) { right[j]=arr[k++];}
    
    i=j=0;
    k=p;
    while(i<n1 && j<n2){
        if(order?(left[i]>right[j]):(left[i]<right[j])){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }

    while(i<n1){
        arr[k++]=left[i++];
    }
    while(i<n2){
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
    int largest=pos;
    int left=pos*2;
    int right=(pos*2)+1;
    if(pos>(heap_size/2)){ return ;}
    if(arr[left-1]>arr[pos-1] && left<=heap_size){
        largest=left;
    }
    else{
        largest=pos;
    }
    if(arr[right-1]>arr[largest-1] && right<=heap_size){
        largest=right;
    }
    if(largest!=pos){
        swap(&arr[pos-1],&arr[largest-1]);
        max_heapify(arr,largest,heap_size);
    }

}
void build_heap(int *arr,int heap_size){
    int i=0;
    for(i=heap_size/2;i>=1;i--){
        max_heapify(arr,i,heap_size);
        
    }
}
void heap_sort(int *arr,int heap_size){
    int i;
    int HEAP_SIZE=heap_size;
    build_heap(arr,heap_size);
    for(i=0;i<HEAP_SIZE;i++){
        swap(&arr[0],&arr[heap_size-1]);
        heap_size=heap_size-1;
        max_heapify(arr,1,heap_size);
    }
}