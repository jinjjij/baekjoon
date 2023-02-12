/*
https://www.acmicpc.net/problem/1394
*/

#include <stdio.h>
#include <string.h>
#define N 900528


int main(void){
    char set[101];
    scanf("%s", set);
    int len = strlen(set);

    int numset[300];
    for(int i=0;i<len;i++){
        numset[set[i]] = i+1;
    }

    char p;
    int count = 0;
    char pw[1000001];
    scanf("%s", pw);
    int pwlen = strlen(pw);
    for(int i=0;i<pwlen;i++){
        p = pw[i];
        count *= len;
        count += numset[p];
        count %= N;
    }

    printf("%d", count);
    return 0;
}