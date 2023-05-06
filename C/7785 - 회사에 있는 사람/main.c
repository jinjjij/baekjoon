/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


// data : change this struct
typedef struct _data{
    char name[10];
} DATA;


DATA* createData(char* name){
    DATA* data = (DATA*)malloc(sizeof(DATA));
    strcpy(data->name, name);

    return data;
}


void destroyData(DATA* data){
    free(data);
}



typedef struct _node{
    uint32_t index;
    DATA* data;
    struct _node* next;
} NODE;


typedef struct _hashTable{
    int cap;
    NODE** table;
    int size;
} HASH;


uint32_t djb33_hash(const char* s, size_t len)
{
    uint32_t h = 5381;
    while (len--) {
        /* h = 33 * h ^ s[i]; */
        h += (h << 5);  
        h ^= *s++;
    }
    return h;
}


NODE* createNode(DATA* data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->index = djb33_hash(data->name, strlen(data->name));
    node->data = data;
    node->next = NULL;

    return node;
}


HASH* createHash(int cap){
    HASH* hash = (HASH*)malloc(sizeof(HASH));
    hash->cap = cap;
    hash->size = 0;
    hash->table = (NODE**)calloc(cap, sizeof(NODE*));

    return hash;
}



void destroyNode(NODE* node){
    if(node->data!=NULL)    destroyData(node->data);
    if(node->next!=NULL)    destroyNode(node->next);
    free(node);
}


void destroyHash(HASH* hash){
    for(int i=0;i<hash->cap;i++){
        if(hash->table[i]!=NULL)    destroyNode(hash->table[i]);
    }
    free(hash);
}


void addData(HASH* hash, DATA* data){
    NODE* newnode = createNode(data);

    newnode->index %= hash->cap;

    NODE* targetNode = hash->table[newnode->index];

    if(targetNode == NULL){
        hash->table[newnode->index] = newnode;
    }else{
        while(targetNode->next!=NULL){
            targetNode = targetNode->next;
        }
        targetNode->next = newnode;
    }
        
    hash->size ++;
}


DATA* pullData(HASH* hash, char* keyname){
    uint32_t keyIndex = djb33_hash(keyname, strlen(keyname));
    keyIndex %= hash->cap;

    NODE* cur = hash->table[keyIndex];

    int flg = 0;
    while(cur!=NULL){
        if(strcmp(cur->data->name, keyname) == 0){
            flg = 1;
            break;
        }
        cur = cur->next;
    }

    if(flg==0){
        return NULL;
    }else{
        return cur->data;
    }
}


DATA* deleteNode(HASH* hash, char* keyname){
    uint32_t keyIndex = djb33_hash(keyname, strlen(keyname));
    keyIndex %= hash->cap;

    NODE* cur = hash->table[keyIndex];
    NODE* prev = NULL;
    NODE* next;
    DATA* ret;
    if(cur != NULL)     next = cur->next;

    int flg = 0;
    while(cur!=NULL){
        if(strcmp(cur->data->name, keyname) == 0){
            flg = 1;
            break;
        }
        prev = cur;
        cur = cur->next;
        if(cur!=NULL)   next = cur->next;
    }

    if(prev != NULL){
        if(next != NULL){
            prev->next = next;
        }else{
            prev->next = NULL;
        }
    }else{
        hash->table[keyIndex] = NULL;
    }

    ret = cur->data;
    free(cur);

    if(flg==0){
        return NULL;
    }else{
        return ret;
    }
}



void printNode(NODE* node, int lev){

    printf("(%d)", node->index);
    if(lev==1){
        printf("\t");
    }
    printf("%s\n", node->data->name);

    if(node->next!=NULL){
        printNode(node->next, 1);
    }
}


void printHash(HASH* hash){
    printf("<<<<<<<<<< HASHTABLE >>>>>>>>>\n");
    for(int i=0;i<hash->cap;i++){
        if(hash->table[i]!=NULL)    printNode(hash->table[i], 0);
    }
}


int _cmp(const void* arg1, const void* arg2){
    char* n1 = ((DATA*)arg1)->name;
    char* n2 = ((DATA*)arg2)->name;
    int ret = strcmp(n1, n2);
    printf("cmp : %s, %s -> %d\n", n1, n2, ret);
    printf("%d\n", strlen(n1));

    return ret;
}


void printNames(HASH* hash){
    DATA* sortedNames[100];
    printf("printName debug1\n");
    int idx = 0;

    for(int i=0;i<hash->cap;i++){
        if(hash->table[i]!=NULL){
            sortedNames[idx++] = hash->table[i]->data;
            printf("sN[%d]:%s\n",idx-1, sortedNames[idx-1]->name);
        }
    }
    printf("idx = %d\n", idx);
    qsort(sortedNames, idx, sizeof(DATA*), _cmp);

    for(int i=0;i<idx;i++){
        printf("%s\n", sortedNames[i]->name);
    }
}


int main(void){
    HASH* hash = createHash(1000);
    int N = 0;
    scanf("%d", &N);

    char tmpName[10];
    char state[10];

    for(int i=0;i<N;i++){
        scanf(" %s %s", tmpName, state);

        if(!strcmp(state, "enter")){
            DATA* data = createData(tmpName);
            addData(hash, data);
        }else if(!strcmp(state, "leave")){
            DATA* delData = deleteNode(hash, tmpName);
        }
    }

    printNames(hash);


    destroyHash(hash);
    return 0;
}