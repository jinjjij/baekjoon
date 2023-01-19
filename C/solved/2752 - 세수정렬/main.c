/*
https://www.acmicpc.net/problem/2752 - 세수정렬
*/

#include <stdio.h>
#include <stdlib.h>


int cmp(const void* arg1, const void* arg2){
    return *(int*)arg1 - *(int*)arg2;
}


int main(void){
    int a[3];
    for(int i=0;i<3;i++){
        scanf("%d", &a[i]);
    }
    qsort(a, 3, sizeof(int), cmp);
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}