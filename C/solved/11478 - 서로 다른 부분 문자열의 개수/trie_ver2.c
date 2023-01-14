/*
https://www.acmicpc.net/problem/11478 - 서로 다른 부분 문자열의 개수

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int data;
    struct node* child[26];
} NODE;


NODE* createNode(int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    for(int i=0;i<26;i++){
        node->child[i] = NULL;
    }
    node->data = data;
    return node;
}


void destroyNode(NODE* node){
    for(int i=0;i<26;i++){
        if(node->child[i] != NULL)
            destroyNode(node->child[i]);
    }
    free(node);
}


int partial(char* S, int num){
    int ret = 0;
    NODE* root = createNode(-1);
    NODE* curNode;

    for(int i=0;i<strlen(S)-num+1;i++){
        curNode = root;
        int flg = 0;
        for(int j=i;j<i+num;j++){
            int index = S[j]-'a';
            if(curNode->child[index] == NULL){
                curNode->child[index] = createNode(index);
            }else{
                if(j == i+num-1){
                    flg = 1;
                }
            }
            curNode = curNode->child[index];
        }

        if(!flg){
            ret++;
        }
    }

    destroyNode(root);
    return ret;
}


int main(void){
    char S[1001];
    scanf("%s", S);

    int len = strlen(S);
    int count = 0;

    
    for(int i=1;i<=len;i++){
        count += partial(S, i);
    }
    
    printf("%d", count);
    return 0;
}