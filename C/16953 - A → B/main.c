/*
https://www.acmicpc.net/problem/16953
*/

#include <stdio.h>
#include <stdlib.h>



int dfs(int n, int target, int* arr){
    


    if(n>target){
        return -1;
    }else if(n == target){
        return 0;
    }
    if(arr[n]!=-1)  return arr[n];

    int min = -1;
    int temp;

    temp = dfs(n*10+1,target, arr);
    if((min==-1 || min>temp) && temp!=-1){
        min = temp+1;
    }

    temp = dfs(n*2,target, arr);
    if((min==-1 || min>temp) && temp!=-1){
        min = temp+1;
    }


    //printf("dfs(%d,%d)=%d\n", n,target, min);

    arr[n] = min;
    return min;
}


int main(void){
    int A,B;
    scanf("%d %d", &A, &B);
    int* arr = (int*)malloc(sizeof(int) * (B+1));
    for(int i=0;i<B;i++){
        arr[i] = -1;
    }
    int temp = dfs(A, B, arr)+1;
    if(temp==0) temp = -1;
    printf("%d", temp);
    free(arr);
    return 0;
}