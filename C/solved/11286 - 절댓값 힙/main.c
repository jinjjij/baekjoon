/*
https://www.acmicpc.net/problem/11286
*/

#include <stdio.h>



/*
library

*/


#include <stdio.h>
#include <stdlib.h>


int abs(int n){
    return n<0?-n:n;
}


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

int compare(HEAP*, int, int);

int addNode(HEAP* heap, NODE* node);
int srchNode(HEAP* heap, int key);
NODE* popNode(HEAP* heap);
void deleteNode(HEAP*, int);

void traverseHeap(HEAP* heap);
void swap(HEAP* heap, int arg1, int arg2);


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


int compare(HEAP* heap, int arg1, int arg2){
    int data1, data2;
    data1 = heap->arr[arg1]->data;
    data2 = heap->arr[arg2]->data;
    
    if(abs(data1) < abs(data2)){
        return 1;
    }else if(abs(data1) == abs(data2)){
        if(data1<data2){
            return 1;
        }else{
            return -1;
        }
    }else{
        return -1;
    }




}


int addNode(HEAP* heap, NODE* node){
    if(heap->size == heap->cap){
        return -1;
    }

    heap->arr[heap->size] = node;

    int parent;
    int cur = heap->size;
    heap->size++;
    while(1){
        parent = (cur-1)/2;
        if(compare(heap, cur, parent) == 1){
            swap(heap, cur, parent);
            cur = parent;
        }else{
            break;
        }

        if(cur==0)  break;
    }
    
    return cur;
}


int srchNode(HEAP* heap, int key){
    for(int i=0;i<heap->size;i++){
        if(heap->arr[i]->data == key){
            return i;
        }
    }
    return -1;
}


NODE* popNode(HEAP* heap){
    NODE* ret = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;

    int cur,left,right;
    cur = 0;

    while(1){
        left = cur*2+1;
        right = cur*2+2;

        int max = cur;

        if(left < heap->size && compare(heap, left, max)==1)
            max = left;

        if(right < heap->size && compare(heap, right, max)==1)
            max = right;

        if(max == cur){
            break;
        }else{
            swap(heap, cur, max);
            cur = max;
        }
    }


    return ret;
}


void _traverse(HEAP* heap, int index, int level){
    int left = index*2+1;
    int right = index*2 + 2;

    if(right < heap->size)   _traverse(heap, right, level+1);
    for(int i=0;i<level;i++)    printf("\t");
    printf("%d\n", heap->arr[index]->data);
    if(left < heap->size)   _traverse(heap, left, level+1);
}


void traverseHeap(HEAP* heap){
    printf("\n<<traverse>>\n");
    if(heap->size != 0)     _traverse(heap, 0, 0);
}


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


void deleteNode(HEAP* heap, int key){
    int delIndex = srchNode(heap, key);
    if(delIndex==-1)    return;

    destroyNode(heap->arr[delIndex]);
    heap->arr[delIndex] = heap->arr[heap->size-1];
    heap->size--;

    int cur,left,right;
    cur = delIndex;

    while(1){
        left = cur*2+1;
        right = cur*2+2;

        int max = cur;

        if(left < heap->size && compare(heap, left, max)==1)
            max = left;

        if(right < heap->size && compare(heap, right, max)==1)
            max = right;

        if(max == cur){
            break;
        }else{
            swap(heap, cur, max);
            cur = max;
        }
    }

}


int main(void){
    int N;
    scanf("%d", &N);

    HEAP* heap = createHeap(N+10);


    int input = 0;
    for(int i=0;i<N;i++){
        scanf("%d", &input);

        NODE* node;

        if(input){
            node = createNode(input);
            addNode(heap, node);
        }else{
            if(heap->size==0){
                printf("0\n");
            }else{
                node = popNode(heap);
                printf("%d\n", node->data);
                destroyNode(node);
            }    
        }

    }


    destroyHeap(heap);
    return 0;
}