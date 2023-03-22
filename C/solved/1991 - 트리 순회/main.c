/*
https://www.acmicpc.net/problem/1991
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char data;
    struct node* left;
    struct node* right;
} NODE;


NODE* createNode(char data){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


void destroyNode(NODE* node){
    if(node->left != NULL)      destroyNode(node->left);
    if(node->right != NULL)     destroyNode(node->right);

    free(node);
}


int idx(char a){
    return a-'A';
}


void _preorder(NODE* node){
    if(node == NULL){
        return;
    }
    printf("%c", node->data);
    _preorder(node->left);
    _preorder(node->right);
}


void _inorder(NODE* node){
    if(!node)   return;
    _inorder(node->left);
    printf("%c", node->data);
    _inorder(node->right);
}


void _postorder(NODE* node){
    if(!node)   return;
    _postorder(node->left);
    _postorder(node->right);
    printf("%c", node->data);
}



void traversal(NODE* root){
    // 0 : pre-order        root -> left -> right
    // 1 : in-order         left -> root -> right
    // 2 : post-order       left -> right -> root
    if(!root)   return;

    _preorder(root);    printf("\n");
    _inorder(root);     printf("\n");
    _postorder(root);   printf("\n");
}


int main(void){
    NODE* nodes[30];
    int N;
    scanf("%d", &N);
    char a,b,c;

    for(int n=0;n<N;n++){
        nodes[n] = createNode('A'+n);
    } 

    char l,r;
    for(int i=0;i<N;i++){
        scanf(" %c %c %c", &a, &l, &r);

        if(l!='.'){
            nodes[idx(a)]->left = nodes[idx(l)];
        }

        if(r!='.'){
            nodes[idx(a)]->right = nodes[idx(r)];
        }
    }

    traversal(nodes[0]);
    return 0;
}