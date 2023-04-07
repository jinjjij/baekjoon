/*
https://www.acmicpc.net/problem/11725
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int x;
    int chlidNum;
    int cap;
    int* child;
}NODE;


void addChild(NODE* node, int child){
    if(node->chlidNum == node->cap){
        node->cap *= 2;
        node->child = realloc(node->child, node->cap);
    }
    node->child[node->chlidNum++] = child;
}


void buildTree(NODE* nodes, int this, int par, int* parent){
    if(parent[this] != 0)   return;
    parent[this] = par;
    //printf("this : %d, par : %d\n", this, par);

    for(int i=0;i<nodes[this].chlidNum;i++){
        if(nodes[this].child[i] != par)
            buildTree(nodes, nodes[this].child[i], this, parent);
    }
}


int main(void){
    int N;      //(2 ≤ N ≤ 100,000)
    scanf("%d", &N);


    NODE* nodes = (NODE*)calloc(N+1, sizeof(NODE));
    for(int i=0;i<N+1;i++){
        nodes[i].cap = 10;
        nodes[i].child = (int*)calloc(10, sizeof(int));
    }
    int* parent = (int*)calloc(N+1, sizeof(int));

    int a, b;
    for(int i=1;i<N;i++){
        scanf("%d %d", &a, &b);
        addChild(&(nodes[a]), b);
        addChild(&(nodes[b]), a);
    }

    buildTree(nodes, 1, 0, parent);

    for(int i=2;i<=N;i++){
        printf("%d\n", parent[i]);
    }

    for(int i=0;i<N+1;i++){
        free(nodes[i].child);
    }
    free(nodes);
    free(parent);    
    return 0;
}