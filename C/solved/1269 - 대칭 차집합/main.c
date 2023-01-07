/*
https://www.acmicpc.net/problem/1269 - 대칭 차집합

230107 - 230107 solved
*/


#include <stdio.h>
#include <stdlib.h>


int cmp(const void* arg1, const void* arg2){
    return (*(int*)arg1 - *(int*)arg2);
}


int main(void){
    int a,b;
    int c = 0;

    scanf("%d %d", &a, &b);
    int* A = (int*)malloc(sizeof(int) * a);
    int* B = (int*)malloc(sizeof(int) * b);

    for(int i=0;i<a;i++){
        scanf("%d", &A[i]);
    }

    for(int i=0;i<b;i++){
        scanf("%d", &B[i]);
    }

    qsort(A, a, sizeof(int), cmp);
    qsort(B, b, sizeof(int), cmp);

    int i = 0;
    int j = 0;

    while(i<a && j<b){
        if(A[i] == B[j]){
            c++;
            i++;
            j++;
        }else{
            if(A[i]<=B[j])
                i++;
            else
                j++;
        }
    }


    printf("%d", a+b-c-c);

    free(A);
    free(B);
    return 0;
}
