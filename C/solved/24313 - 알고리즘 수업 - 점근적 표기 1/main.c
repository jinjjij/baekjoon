/*
https://www.acmicpc.net/problem/24313
*/

#include <stdio.h>

int main(void){
    int a0,a1,c,n0;
    scanf("%d %d", &a1, &a0);
    scanf("%d", &c);
    scanf("%d", &n0);

    if(c*n0 >= a1*n0 + a0){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}