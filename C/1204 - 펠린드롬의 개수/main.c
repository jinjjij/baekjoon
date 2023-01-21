/*
https://www.acmicpc.net/problem/1204 - 펠린드롬의 개수
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 835454957

int arr[60];
char s[50][110];
int len[50];
int N,K;


void init(void){
    for(int i=0;i<60;i++){
        arr[i] = -1;
    }
    arr[0] = 0;
}


int dp(int n){
    if(n < 0)   return -1;
    if(arr[n] != -1)    return arr[n];

    for(int i=0;i<N;i++){
        if(n - len[i] < 0)  continue;

        
    }
}   


int main(void){
    init();
    
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++){
        scanf("%s", &s[i]);
        len[i] = strlen(s[i]);
    }


    return 0;
}