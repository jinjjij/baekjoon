/*
library

*/


#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
} NODE;


typedef struct heap{
    int cap;
    int size;
    NODE** arr;
} HEAP;


HEAP* createHeap(int cap);
void destroyHeap(HEAP* heap);

NODE* createNode();
void destroyNode(NODE* node);

int compare(NODE* n1, NODE* n2);

int addNode(HEAP* heap, NODE* node);
NODE* srchNode(HEAP* heap, NODE* key);
int deleteNode(HEAP* heap, NODE* node);

void traverseHeap(HEAP* heap);
void swap(HEAP* heap, int arg1, int arg2);


int main(void){

    return 0;
}


HEAP* createHeap(int cap){
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->arr = (NODE**)malloc(sizeof(NODE*) * cap);
    heap->cap = cap;
    heap->size = 0;
    return heap;
}


void destroyHeap(HEAP* heap){
    for(int i=0;i<heap->size;i++){
        free(heap->arr[i]);
    }
    free(heap);
}


NODE* createNode(int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    return node;
}


void destroyNode(NODE* node){
    free(node);
}


int compare(NODE* n1, NODE* n2){
    if(n1->data > n2->data){
        return 1;
    }else if(n1->data < n2->data){
        return -1;
    }else{
        return 0;
    }
}


int addNode(HEAP* heap, NODE* node){
    if(heap->size == heap->cap){
        return -1;
    }

    heap->arr[heap->size] = node;

    int parent;
    int cur = heap->size;
    while(1){
        
    }
    
}


NODE* srchNode(HEAP* heap, NODE* key);


int deleteNode(HEAP* heap, NODE* node);


void traverseHeap(HEAP* heap);


void swap(HEAP* heap, int arg1, int arg2){

    if(heap == NULL){
        fprintf(stderr, "Error occured in function swap\nheap is Null\n");
    }

    if(arg1 >= heap->size || arg2 >= heap->size){
        fprintf(stderr, "Error occured in function swap\n");
        fprintf(stderr, "arg1 : %d, arg2 : %d but heap size is %d\n", arg1, arg2, heap->size);
        return;
    }


    NODE* temp = heap->arr[arg1];
    heap->arr[arg1] = heap->arr[arg2];
    heap->arr[arg2] = temp;
}


