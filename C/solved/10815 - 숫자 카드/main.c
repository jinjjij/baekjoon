/*
https://www.acmicpc.net/problem/10815 - 숫자 카드

230106 - 230106 solved

*/

#include <stdio.h>
#include <stdlib.h>


int cmp(const void* arg1, const void* arg2){
//    printf("cmp : %d %d\n", *(int*)arg1, *(int*)arg2);
    return *(int*)arg1 - *(int*)arg2;
}


int main(void){
    int N,M;

    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int) * N);

    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), cmp);

    scanf("%d", &M);

    int input;
    for(int i=0;i<M;i++){
        scanf("%d", &input);
        void* bsret = bsearch(&input, arr, N, sizeof(int), cmp);
        int ret;
        if(bsret != NULL){
            ret = 1;
        }else{
            ret = 0;
        }

        printf("%d ", ret);
    }

    return 0;
}