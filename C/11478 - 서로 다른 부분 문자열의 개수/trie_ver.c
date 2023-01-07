/*
https://www.acmicpc.net/problem/11478 - 서로 다른 부분 문자열의 개수

트라이 구조 이용하면 시간초과 남 -> 해시로 재구현
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    char data;
    struct node** child;
} NODE;


typedef struct trie{
    struct node** root;
} TRIE;


NODE* createNode(char data){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->child = (NODE**)malloc(sizeof(NODE*) * 26);

    for(int i=0;i<26;i++){
        newnode->child[i] = NULL;
    }

    newnode->data = data;

    return newnode;
}


TRIE* createTrie(void){
    TRIE* newTrie = (TRIE*)malloc(sizeof(TRIE));
    newTrie->root = (NODE**)malloc(sizeof(NODE*) * 26);

    for(int i=0;i<26;i++){
        newTrie->root[i] = NULL;
    }

    return newTrie;
}


void destroyNode(NODE* node){
    for(int i=0;i<26;i++){
        if(node->child[i] != NULL){
            destroyNode(node->child[i]);
        }
    }

    free(node->child);
    free(node);
}


void destroyTrie(TRIE* trie){
    for(int i=0;i<26;i++){
        if(trie->root[i] != NULL){
            destroyNode(trie->root[i]);
        }
    }

    free(trie->root);
    free(trie);
}





int addToTrie(TRIE* trie, char* S, int offset, int size){
    int dupFlg = 1;
    NODE* curNode = trie->root[S[offset] - 'a'];

    if(trie->root[S[offset] - 'a'] == NULL){
        trie->root[S[offset] - 'a'] = createNode(S[offset] - 'a');
        dupFlg = 0;
    }
    curNode = trie->root[S[offset] - 'a'];

    // debug
    //printf("%c", S[offset]);

    for(int i=1;i<size;i++){

        // debug
        //printf("%c", S[offset+i]);

        if(curNode->child[S[offset+i] - 'a'] == NULL){
            curNode->child[S[offset+i] - 'a'] = createNode(S[offset+i] - 'a');
            dupFlg = 0;
        }
        curNode = curNode->child[S[offset+i] - 'a'];
    }

    //debug
    //printf("\t\t dup(%d)\n", dupFlg);

    return dupFlg;
}


int partialString(char* S, int size){
    int count = 0;
    TRIE* trie = createTrie();


    for(int i=0;i<strlen(S) - size+1;i++){
        if(!addToTrie(trie, S, i, size)){
            count++;
        }
    }


    destroyTrie(trie);

    //debug
    //printf("partialString() return : %d\n", count);

    return count;
}


int main(void){
    char S[1001];
    scanf("%s", S);

    int len = strlen(S);
    int count = 0;

    for(int i=1;i<=len;i++){
        count += partialString(S, i);
    }
    
    printf("%d", count);
    return 0;
}