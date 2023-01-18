/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
} NODE;


typedef struct arr{
    NODE* last;
    NODE* first;
    int size;
} ARR;


ARR* createArr(void){
    ARR* arr = (ARR*)malloc(sizeof(ARR));
    arr->last = NULL;
    arr->first = NULL;
    arr->size = 0;

    return arr;
}


void destroyArr(ARR* arr){
    free(arr);
}


NODE* createNode(int data){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}


void destroyNode(NODE* node){
    if(node->next != NULL)  destroyNode(node->next);
    free(node);
}


int pushArr(ARR* arr, int new){
    NODE* newnode = createNode(new);

    if(arr->size == 0){
        arr->first = newnode;
        arr->last = newnode;
    }else{
        arr->last->next = newnode;
        arr->last = arr->last->next;
    }
    arr->size ++;
    
    return 1;
}


int getMaxMin(ARR* arr, int MaxMin, NODE** pre, NODE** node){
    if(arr->size == 0){
        return -1;
    }

    int max, min;
    if(MaxMin == 1){
        max = 1;
        min = 0;
    }else if(MaxMin == -1){
        max = 0;
        min = 1;
    }
    int ret = arr->first->data;

    NODE* cur = arr->first;
    NODE* curPre = NULL;
    while(cur != NULL){
        if((max && cur->data > ret) || (min && cur->data < ret)){
            node = cur;
            pre = curPre;
            ret = cur->data;
        }
        curPre = cur;
        cur = cur->next;
    }

    return ret;
}


void deleteNode(ARR** arr, NODE* pre, NODE* node){
    NODE* next;
    if(pre == NULL){
        
    }
}


int main(void){
    FILE* readMod;

    readMod = stdin;

    // test
    readMod = fopen("input.txt", "rt");

    int T,k;
    fscanf(readMod, "%d", &T);


    for(int t=0; t<T; t++){
        
        ARR* arr = createArr();

        fscanf(readMod, "%d", &k);

        
        char inputC;
        int inputI;

        for(int i=0;i<k;i++){
            fscanf(readMod, " %c %d", &inputC, &inputI);
            printf("\n>> %c : %d <<\n", inputC, inputI);

            if(inputC == 'I'){
                pushArr(arr, inputI);
            }

            int maxmin = 0;
            if(inputC == 'D'){
                getMaxMin(arr, maxmin, &pre, &node);
            }

        }

        destroyArr(arr);
    }

    // test
    fclose(readMod);

    return 0;
}