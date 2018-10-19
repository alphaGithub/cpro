#include<stdlib.h>
#include<stdio.h>
#include "mylib.h"
int main(){
    int arr[]={5,3,8,2,9,1,7};
    insertion_sort(arr,7,0);
    display_array(arr,7);
    return 0;
}