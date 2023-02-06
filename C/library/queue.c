#include <stdio.h>
#include <stdlib.h>


/*
    QUEUE Library
*/

typedef struct _node{
    int data;
    struct _node* prev;
} NODE;


typedef struct _queue{
    NODE* back;
    NODE* front;
    int size;
} QUEUE;


QUEUE* createQueue(void);
NODE* createNode(int data, NODE* prev);

void destroyQueue(QUEUE* queue);
void destroyNode(NODE* node);

void enQueue(QUEUE* queue, int data);
int deQueue(QUEUE* queue);



QUEUE* createQueue(void){
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    queue->back = NULL;
    queue->front = NULL;
    queue->size = 0;
    return queue;
}


NODE* createNode(int data, NODE* prev){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->prev = prev;
    return node;
}

void destroyQueue(QUEUE* queue){
    if(queue->size!=0){
        destroyNode(queue->front);
    }
    free(queue);
}


void destroyNode(NODE* node){
    if(node->prev!=NULL)    destroyNode(node->prev);
    free(node);
}


void enQueue(QUEUE* queue, int data){
    NODE* node = createNode(data, NULL);
    if(queue->back != NULL)   queue->back->prev = node;
    queue->back = node;
    queue->size++;

    if(queue->size==1){
        queue->front = node;
    }
}


int deQueue(QUEUE* queue){
    NODE* n;
    if(queue->front!=NULL){
        n = queue->front;
        queue->front = queue->front->prev;
        queue->size--;
    }

    if(queue->size==0){
        queue->back = NULL;
        queue->front = NULL;
    }

    int ret = n->data;
    n->prev = NULL;
    destroyNode(n);
    return ret;
}


void printQueue(QUEUE* queue){
    NODE* cur = queue->front;
    printf("QUEUE : ");
    while(cur!=NULL){
        printf("%d\t", cur->data);
        cur = cur->prev;
    }
    printf("back\n");
}


/*
    queue library end
*/


int main(void){
    QUEUE* que = createQueue();

    enQueue(que, 1);
    printQueue(que);
    enQueue(que, 2);
    printQueue(que);
    enQueue(que, 3);
    printQueue(que);
    enQueue(que, 4);
    printQueue(que);
    enQueue(que, 5);
    printQueue(que);
    deQueue(que);
    printQueue(que);
    deQueue(que);
    printQueue(que);
    deQueue(que);
    printQueue(que);
    deQueue(que);
    printQueue(que);
    deQueue(que);
    printQueue(que);

    destroyQueue(que);
    return 0;
}