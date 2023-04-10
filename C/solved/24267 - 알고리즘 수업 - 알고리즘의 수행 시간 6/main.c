/*
https://www.acmicpc.net/problem/24266
*/

#include <stdio.h>

int main(void){
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n3",n*(n-1)*(n-2)/6);
    return 0;
}