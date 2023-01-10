/*
https://www.acmicpc.net/problem/11478 - 서로 다른 부분 문자열의 개수

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int partial(char* S, int num){
    int ret = 0;

    return ret;
}


int main(void){
    char S[1001];
    scanf("%s", S);

    int len = strlen(S);
    int count = 0;

    
    for(int i=1;i<=len;i++){
        count += partial(S, i);
    }
    
    printf("%d", count);
    return 0;
}