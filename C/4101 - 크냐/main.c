/*
https://www.acmicpc.net/problem/4101 - 크냐?
*/

#include <stdio.h>


int main(void){
    int n, m;
    while(1){
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)    break;
        if(n>m) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}