/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int beg;
    int end;
    int max;
    int min;
    struct node* left;
    struct node* right;
} Node;


Node* createNode(int beg, int end, int max, int min){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->beg = beg;
    newnode->end = end;
    newnode->max = max;
    newnode->min = min;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


void destroyNode(Node* node){
    if(node ==  NULL)   return;
    if(node->left != NULL){
        destroyNode(node->left);
    }
    if(node->right != NULL){
        destroyNode(node->right);
    }
}


typedef struct segTree{

} SegTree;


SegTree* createSegTree(void){

}


void destroySegTree(SegTree* segtree){
    
}



int main(void){
    
    return 0;
}