#include<iostream>
using namespace std;
#define MAX_HEAPSIZE 20
typedef int DATA;
typedef struct{
    DATA data[MAX_HEAPSIZE];
    int heap_size;
}HEAP;

class heapManager{
    HEAP *heap;
    public:
    void init_heap(int heap_size=20){
        this->heap=(HEAP *)malloc(sizeof(HEAP));
    }
    void fill_heap(DATA *data,int size){
        for(int i=0;i<size;i++){
            this->heap->data[i]=data[i];
        }
        this->heap->heap_size=size;
    }
    void add_data(DATA data){
        if(this->heap->heap_size+1<=MAX_HEAPSIZE){
            this->heap->data[this->heap->heap_size]=data;
            int pos=this->heap->heap_size +=1;
            
            while((pos/2)>0 && (this->heap->data[(pos/2)-1]<this->heap->data[pos-1]))
            {
                swap(&this->heap->data[(pos/2)-1],&this->heap->data[pos-1]);
                pos=pos/2;
            }
        }
    }
    void swap(DATA *d1,DATA *d2){
        DATA tmp;
        tmp=*d1;
        *d1=*d2;
        *d2=tmp;
    }
    void max_heapify(int pos){
        HEAP *heap=this->heap;
        int heap_size=this->heap->heap_size;
        int left,right,largest=pos;
        left=(2*pos);
        right=(2*pos)+1;
        if((left<=heap_size) && (heap->data[left-1]>heap->data[pos-1])){
            largest=left;
        }
        else if((right<=heap_size) && (heap->data[right-1]>heap->data[largest-1])){
            largest=right;
        }
        if(largest!=pos){
            swap(&heap->data[largest-1],&heap->data[pos-1]);
            this->max_heapify(largest);
        }

    }
    void build_heap(){
        HEAP *heap=this->heap;
        int heap_size=this->heap->heap_size;
        for(int i=heap_size/2;i>=1;i--){
            this->max_heapify(i);
        }
    }
    void traverse(){
        HEAP *heap=this->heap;
        int heap_size=this->heap->heap_size;
        for(int i=0;i<heap_size;i++){
            printf("%d ->",heap->data[i]);
        }
        cout<<endl;
    }
    int delete_max(){
        HEAP * heap=this->heap;
        int heap_size=this->heap->heap_size;
        int data=this->heap->data[0];
        this->heap->data[0]=this->heap->data[heap_size-1];
        this->heap->heap_size -= 1;
        return data;
    }
    void sort_heap(){
        HEAP *heap=this->heap;
        int heap_size=this->heap->heap_size;
        int size=heap_size;
        for(int i=0;i<heap_size;i++){
            this->swap(&this->heap->data[0],&this->heap->data[heap_size-1]);
            this->heap->heap_size -=1;
            this->max_heapify(1);
            this->traverse();
        }
        this->heap->heap_size=size;
        
    }


};
int main(){
    DATA data[]={4,2,5,7,1,3};
    heapManager manager;
    manager.init_heap();
    manager.fill_heap(data,6);
    manager.traverse();
    manager.build_heap();
    manager.traverse();
    manager.add_data(9);
    manager.traverse();
    manager.delete_max();
    manager.traverse();
    manager.sort_heap();
    manager.traverse();
    return 0;
}