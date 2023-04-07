/*
https://www.acmicpc.net/problem/27866
*/

#include <stdio.h>


int main(void){
    char S[1001];
    scanf("%s", S);
    int N;
    scanf(" %d", &N);
    printf("%c",S[N-1]);
    return 0;
}