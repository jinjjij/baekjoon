/*
https://www.acmicpc.net/problem/2357
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


void buildSegTree(Node* node, int* arr, int left, int right){
    node->beg = left;
    node->end = right;

    if(left == right){
        node->max = arr[left];
        node->min = arr[left];
        return;
    }
    int mid = (left + right)/2;
    node->left = createNode(0,0,0,0);
    buildSegTree(node->left, arr, left, mid);
    node->right = createNode(0,0,0,0);
    buildSegTree(node->right, arr, mid+1, right);

    int lmax = node->left->max;
    int lmin = node->left->min;
    int rmax = node->right->max;
    int rmin = node->right->min;

    if(lmax > rmax){
        node->max = lmax;
    }else{
        node->max = rmax;
    }

    if(lmin < rmin){
        node->min = lmin;
    }else{
        node->min = rmin;
    }
}


void getMinMax(Node* node, int* min, int* max, int beg, int end){
    //printf("getMinMax(%d-%d)\n", beg,end);
    //예외처리
    if(beg < node->beg || node->end < end){
        fprintf(stderr, "Error!\n");
        return ;
    }

    if(beg == node->beg && end == node->end){
        *min = node->min;
        *max = node->max;
        return;
    }

    int mid = (node->beg + node->end)/2;

    int lmin,lmax,lFlg;
    lFlg = 0;
    if(node->right != NULL && node->left->beg <= beg && beg <= node->left->end ){
        getMinMax(node->left, &lmin, &lmax, beg, mid);
        lFlg = 1;
    }

    int rmin,rmax, rFlg;
    rFlg = 0;
    if(node->right != NULL && node->right->beg <= end && end <= node->right->end ){
        getMinMax(node->right, &rmin, &rmax, mid+1, end);
        rFlg = 1;
    }


    if(lFlg){
        if(rFlg){
            if(lmin < rmin) *min = lmin;
            else            *min = rmin;

            if(lmax > rmax) *max = lmax;
            else            *max = rmax;
        }else{
            *min = lmin;
            *max = lmax;
        }
    }else{
        if(rFlg){
            *min = rmin;
            *max = rmax;
        }else{
            fprintf(stderr, "error!");
        }
    }
}


int main(void){
    int N,M;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    Node* root = createNode(0,N-1,0,0);
    buildSegTree(root, arr, 0, N-1);
    //displaySegTree(root, 0);

    int max,min;
    for(int i=0;i<M;i++){
        int beg, end;
        scanf("%d %d", &beg, &end);
        getMinMax(root, &min, &max, beg-1, end-1);
        printf("%d %d\n", min, max);
    }

    destroyNode(root);
    free(arr);
    return 0;
}