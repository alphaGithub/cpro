#include<stdlib.h>
#include<stdio.h>
#include "mylib.h"
int main(){
    int arr[]={5,3,8,2,9,1,7,10};
    printf("ARRAY TO BE SORTED : ");
    display_array(arr,8);
    build_heap(arr,7);
    display_array(arr,8);
    return 0;
}
