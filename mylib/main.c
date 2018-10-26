#include<stdio.h>
#include "mylib.h"
int main(int argc, char const *argv[])
{
    int arr[7]={5,3,7,2,8,1,0};
    bubble_sort(arr,7,0);
    display_array(arr,7);
    insertion_sort(arr,7,1);
    display_array(arr,7);
    selection_sort(arr,7,0);
    display_array(arr,7);
    quick_sort(arr,0,6,1);
    display_array(arr,7);
    merge_sort(arr,0,7,0);
    display_array(arr,7);
    heap_sort(arr,7);
    display_array(arr,7);
    
    return 0;
}
