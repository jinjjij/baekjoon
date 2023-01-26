/*
https://www.acmicpc.net/problem/2559
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){
    int N,K;
    int max = -100 * 100001;
    scanf("%d %d", &N, &K);

    int* arr = (int*)malloc(sizeof(int) * N);

    int sum = 0;
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        sum += arr[i];

        if(i>K-1){
            sum -= arr[i-K];
        }

        if(i>K-2){
            if(max < sum){
                max = sum;
            }
        }
    }

    printf("%d", max);
    free(arr);

    return 0;
}