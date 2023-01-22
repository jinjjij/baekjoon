/*
https://www.acmicpc.net/problem/20053
*/

#include <stdio.h>


int main(void){
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++){
        int N, max, min;
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            int temp;
            scanf("%d", &temp);
            if(temp > max || i==0){
                max = temp;
            }

            if(temp < min || i==0){
                min = temp;
            }
        }

        printf("%d %d\n", min, max);
    }
    return 0;
}