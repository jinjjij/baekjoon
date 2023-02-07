#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct _data{
    char addr[21];
    char pw[21];  
} DATA;


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


DATA* createData(char* addr, char* pw){
    DATA* data = (DATA*)malloc(sizeof(DATA));
    strcpy(data->addr, addr);
    strcpy(data->pw, pw);

    return data;
}


NODE* createNode(DATA* data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->index = djb33_hash(data->addr, strlen(data->addr));
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

void destroyData(DATA* data){
    free(data);
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


DATA* pullData(HASH* hash, char* keyaddr){
    uint32_t keyIndex = djb33_hash(keyaddr, strlen(keyaddr));
    keyIndex %= hash->cap;

    NODE* cur = hash->table[keyIndex];

    int flg = 0;
    while(cur!=NULL){
        if(strcmp(cur->data->addr, keyaddr) == 0){
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



void printNode(NODE* node, int lev){

    printf("(%d)", node->index);
    if(lev==1){
        printf("\t");
    }
    printf("%s:%s\n", node->data->addr, node->data->pw);

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
