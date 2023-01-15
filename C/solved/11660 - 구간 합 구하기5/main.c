/*
https://www.acmicpc.net/problem/11660 - 구간 합 구하기 5
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int input;
    int N, M;

    scanf("%d %d", &N, &M);
    int** prefix = (int**)malloc(sizeof(int*) * N);
    

    for(int i=0;i<N;i++){
        prefix[i] = (int*)malloc(sizeof(int) * N);
        for(int j=0;j<N;j++){
            scanf("%d", &input);
            int sum = 0;

            if(i>0){
                sum += prefix[i-1][j];
            }
            if(j>0){
                sum += prefix[i][j-1];
            }
            if(i>0 && j>0){
                sum -= prefix[i-1][j-1];
            }
            sum += input;

            prefix[i][j] = sum;
        }
    }

    int x1, x2, y1, y2;
    for(int i=0;i<M;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--;
        y1--;
        x2--;
        y2--;
        int sum = 0;

                            sum += prefix[x2][y2];
        if(x1>0)            sum -= prefix[x1-1][y2];
        if(y1>0)            sum -= prefix[x2][y1-1];
        if(x1>0 && y1>0)    sum += prefix[x1-1][y1-1];

        printf("%d\n", sum);
    }

    for(int i=0;i<N;i++){
        free(prefix[i]);
    }
    free(prefix);

    return 0;
}