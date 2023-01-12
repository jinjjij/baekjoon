/*
https://www.acmicpc.net/problem/11023 - 더하기 3
*/


#include <stdio.h>


int main(void){
    int sum=0;
    int temp;
    while(scanf("%d",&temp)!=EOF){
        sum += temp;
        printf("sum : %d\n",sum);
    }
    printf("%d", sum);
    return 0;
}