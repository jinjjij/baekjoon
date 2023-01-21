/*
https://www.acmicpc.net/problem/1068
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int num;
    int par;
    int disable;
    struct node* child[50];
    int childnum;
}NODE;


NODE* nodes[51];


void addChild(NODE* par, NODE* child){
    if(par==NULL || child==NULL)    return;
    par->child[par->childnum++] = child;
}


NODE* createNode(int num, int par){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->num = num;
    node->par = par;
    node->childnum = 0;
    node->disable = 0;

    return node;
}   


void disableNode(NODE* node){
    node->disable = 1;
    for(int i=0;i<node->childnum;i++){
        if(node->child[i]!=NULL){
            disableNode(node->child[i]);
        }
    }
}


void destroyNode(NODE* node){
    if(node == NULL)    return;
    for(int i=0;i<node->childnum;i++){
        if(node->child[i]!=NULL)    destroyNode(node->child[i]);
    }
    free(node);
}


int isLeaf(NODE* node){
    if(node == NULL)    return 0;
    int isleaf = 1;
    for(int i=0;i<node->childnum;i++){
        if(node->child[i]!=NULL && node->child[i]->disable == 0 ){
            isleaf = 0;
            break;
        }
    }

    return isleaf;
}


int leafNum(NODE* node){
    if(node->disable || node == NULL){
        return 0;
    }
    int ret = isLeaf(node);

    for(int i=0;i<node->childnum;i++){
        if(node->child[i]!=NULL && node->child[i]->disable == 0 ){
            ret += leafNum(node->child[i]);
        }
    }

    return ret;
}


void traverse(NODE* node, int lev){
    for(int i=0;i<lev;i++)  printf("\t");
    printf("%d", node->num);
    if(node->disable)   printf("*");
    printf("\n");

    for(int i=0;i<node->childnum;i++){
        traverse(node->child[i], lev+1);
    }
}


int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int par;
        scanf("%d", &par);
        nodes[i] = createNode(i, par);
        //printf("%d\n", nodes[i]->num);
    }

    for(int i=0;i<N;i++){
        if(nodes[i]==NULL)  continue;
        if(nodes[i]->par!=-1) addChild(nodes[nodes[i]->par], nodes[i]);
    }

    int del;
    scanf("%d", &del);
    disableNode(nodes[del]);

    int sum = 0;
    for(int i=0;i<N;i++){
        if(nodes[i]->par == -1){
            sum += leafNum(nodes[i]);
        }
    }
    printf("%d", sum);
    //printf("\ntraverse:\n");
    //traverse(nodes[0], 0);
    destroyNode(nodes[0]);
    return 0;
}