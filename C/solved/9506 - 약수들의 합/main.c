/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* getDivs(int N, int* divNum){
    int* arr = (int*)malloc(sizeof(int) * N);
    int tmpidx = 0;

    for(int i=1;i<=(int)sqrt((double)N);i++){
        if(N%i==0){
            arr[tmpidx++] = i;
        }
    }

    int len = tmpidx;
    int temp = 0;

    for(int i=len-1;i>=0;i--){
        temp = N/arr[i]    ;
        if(temp == arr[i]){
            continue;
        }

        arr[tmpidx++] = temp;
    }

    *divNum = tmpidx;

    int* retArr = (int*)malloc(sizeof(int) * tmpidx);

    for(int i=0;i<tmpidx;i++){
        retArr[i] = arr[i];
    }


    free(arr);

    return retArr;
}


int main(void){
    int N = 0;
    int len = 0;
    int* arr;
    while(1){
        scanf("%d", &N);
        if(N == -1)     break;

        arr = getDivs(N, &len);

        int divSum = 0;
        for(int i=0;i<len-1;i++){
            divSum += arr[i];
        }

        if(N == divSum){
            printf("%d = ", N);
            printf("1");
            for(int i=1;i<len-1;i++){
                printf(" + ");
                printf("%d", arr[i]);
            }
            printf("\n");
        }else{
            printf("%d is NOT perfect.\n", N);
        }
    }
    return 0;
}