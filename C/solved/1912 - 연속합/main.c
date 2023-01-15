/*
https://www.acmicpc.net/problem/1912 - 연속합
*/


#include <stdio.h>
#include <stdlib.h>




int main(void){
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int) * (N+10));
    int* prefixSum = (int*)malloc(sizeof(int) * (N+10));
    int sum = 0;
    int prefixMin = 0;
    int max = 0;

    for(int i=0;i<N;i++){
        
        // 입력
        scanf("%d", &arr[i]);
        sum += arr[i];

        // 변수 초기화
        
        if(i==0){
            prefixMin = arr[i];
            max = arr[i];
        }
        

        // 누적합
        prefixSum[i] = sum;

        // 누적합의 최솟값
        if(i==0){
            prefixMin = 0;
        }else if(prefixSum[i-1] < prefixMin){
            prefixMin = prefixSum[i-1];
        }

        // 현재까지의 최대 연속합
        int seqSum = prefixSum[i] - prefixMin;

        if(max < seqSum){
            max = seqSum;
        }

        //printf("i : %d\nmax : %d\nseqSum : %d\n", i,max,seqSum);
    }

    printf("%d", max);
    
    free(arr);
    free(prefixSum);
    return 0;
}