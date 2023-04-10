/*
https://www.acmicpc.net/problem/

1 -> 4
2 -> 8
3 -> 12

*/

#include <stdio.h>

int main(void){
    long long int n;
    scanf("%lld", &n);
    printf("%lld", 4 * n);
    return 0;
}