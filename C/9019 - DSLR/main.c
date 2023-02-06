/*
https://www.acmicpc.net/problem/9019
*/

#include <stdio.h>
#include <stdlib.h>

int prev[10000];

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


int D(int n){
    return (2*n)%10000;
}


int S(int n){
    if(n==0){
        return 9999;
    }else{
        return n-1;
    }
}


int L(int n){
    int first = n/1000;
    n *= 10;
    n %= 10000;
    return n + first;
}   


int R(int n){
    int last = n%10;
    n/=10;
    return last*1000 + n;
}


int reverse(int prev_arg, int cur_arg){
    if(cur_arg == D(prev_arg))  return 1;
    if(cur_arg == S(prev_arg))  return 2;
    if(cur_arg == L(prev_arg))  return 3;
    if(cur_arg == R(prev_arg))  return 4;
    return -1;
}


void DSLR(int A, int B, char* result){
    QUEUE* que = createQueue();
    
    enQueue(que, A);
    
    while(que->size >= 0){
        int cur = deQueue(que);
        if(cur == B){
            break;
        }

        //D
        int d = D(cur);
        if(prev[d] != -1){
            prev[d] = cur;
            enQueue(que, d);
        }
        //S
        int s = S(cur);
        if(prev[s] != -1){
            prev[s] = cur;
            enQueue(que, s);
        }
        //L
        int l = L(cur);
        if(prev[l] != -1){
            prev[l] = cur;
            enQueue(que, l);
        }
        //R
        int r = R(cur);
        if(prev[r] != -1){
            prev[r] = cur;
            enQueue(que, r);
        }
    }

    int cur = B;
    int temp[10000];
    int size = 0;
    while(cur!=A){
        temp[size++] = reverse(prev[cur], cur);
        cur = prev[cur];
    }

    for(int i=0;i<size;i++){
        int a = temp[size-i-1];
        switch(a){
            case 1:
                result[i] = 'D';
                break;
            case 2:
                result[i] = 'S';
                break;
            case 3:
                result[i] = 'L';
                break;
            case 4:
                result[i] = 'R';
                break;
        }
    }
    result[size] = 0;

    destroyQueue(que);
}



void initMem(void){
    for(int i=0;i<10000;i++){
        prev[i] = -1;
    }
}


int main(void){
    int T;
    scanf("%d", &T);
    int A,B;
   
    for(int t=0;t<T;t++){
        scanf("%d %d", &A, &B);
        char result[10000] = "";
        initMem();
        DSLR(A, B, result);
        printf("%s\n", result);
    }
    return 0;
}