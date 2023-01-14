/*
https://www.acmicpc.net/problem/11478 - 서로 다른 부분 문자열의 개수

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct node{
    char* data;
    uint32_t hash;
    struct node* next;
} NODE;


typedef struct hashset{
    int capacity;
    int size;

    NODE** table;
} HASH_SET;


uint32_t djb33_hash(char* s, size_t len){
    uint32_t h = 5381;
    while(len--){
        h += (h<<5);
        h ^= *s++;
    }

    return h;
}


NODE* createNode(char* data){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    
    newnode->data = data;
    newnode->hash = djb33_hash(data, strlen(data));
    newnode->next = NULL;

    return newnode;
}


HASH_SET* createHASHSET(int capacity){
    HASH_SET* newset = (HASH_SET*)malloc(sizeof(HASH_SET));

    newset->capacity = capacity;
    newset->size = 0;
    newset->table = (NODE**)malloc(sizeof(NODE*) * capacity);
    for(int i=0;i<capacity;i++){
        newset->table[i] = NULL;
    }

    return newset;
}


void destroyNode(NODE* node){
    if(node->next != NULL)
        destroyNode(node->next);
    
    free(node->data);
    free(node);
}


void destroyHASHSET(HASH_SET* hashset){
    for(int i=0;i<hashset->capacity;i++){
        if(hashset->table[i] != NULL)
            destroyNode(hashset->table[i]);
    }

    free(hashset);
}


void addNode(HASH_SET* hashset, NODE* node){

    int index = node->hash % hashset->capacity;
    int dupFlg = 0;


    if(hashset->table[index] == NULL){      // 중복 X
        hashset->table[index] = node;
    }else{                                  // 중복
        NODE* curNode = hashset->table[index];

        while(1){
            if(strcmp(curNode->data, node->data) == 0){
                //printf("Dup!! : %s\n", curNode->data);
                destroyNode(node);
                return;
            }

            if(curNode->next != NULL){
                curNode = curNode->next;
            }else{
                break;
            }
        }

        curNode->next = node;
    }
    hashset->size ++;

}


int partial(char* S){
    int len = strlen(S);
    HASH_SET* hash = createHASHSET(100000);


    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            char buff[2000];
            strncpy(buff, S + i, j-i+1);
            buff[j-i+1] = 0;
            char* nodestr = strdup(buff);

            NODE* node = createNode(nodestr);

            addNode(hash, node);
        }
    }

    int ret = hash->size;
    destroyHASHSET(hash);
    return ret;
}



int main(void){
    char S[2001];
    scanf("%s", S);
    printf("%d", partial(S));
    return 0;
}