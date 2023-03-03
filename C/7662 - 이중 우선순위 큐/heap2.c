/*
https://www.acmicpc.net/problem/7662
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

int compare(HEAP*, int, int);

int addNode(HEAP* heap, NODE* node);
void popNode(HEAP* heap);

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
    if(data1 > data2){
        return 1;
    }else if(data1 < data2){
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


void popNode(HEAP* heap){
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


    destroyNode(ret);
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


int T,k;


int main(void)
{
    FILE* readMod;

    readMod = stdin;

    // test
    //readMod = fopen("input.txt", "rt");

    fscanf(readMod, "%d", &T);

    for(int t=0; t<T; t++){

        fscanf(readMod, "%d", &k);
        HEAP* maxHeap = createHeap(k+10);
        HEAP* minHeap = createHeap(k+10);

        
        char inputC;
        int inputI;
        int count = 0;

        for(int i=0;i<k;i++){
            fscanf(readMod, " %c %d", &inputC, &inputI);

            if(inputC == 'I'){
                NODE* maxNode = createNode(inputI);
                NODE* minNode = createNode(-inputI);
                addNode(maxHeap, maxNode);
                addNode(minHeap, minNode);
                count++;
            }

            if(inputC == 'D' && inputI == 1){       // 최댓값 삭제
                if(maxHeap->size == 0){
                    continue;
                }
                popNode(maxHeap);
                count--;
            }

            if(inputC == 'D' && inputI == -1){      // 최솟값 삭제
                if(minHeap->size == 0){
                    continue;
                }
                popNode(minHeap);
                count--;
            }

            if(count == 0){
                maxHeap->size = 0;
                minHeap->size = 0;
            }
        }

        if(count==0){
            printf("EMPTY\n");
        }else{
            NODE* max = maxHeap->arr[0];
            NODE* min = minHeap->arr[0];

            printf("%d %d\n", max->data, -min->data);

            destroyNode(max);
            destroyNode(min);
        }


        destroyHeap(maxHeap);
        destroyHeap(minHeap);
    }

    // test
    //fclose(readMod);

    return 0;
}
