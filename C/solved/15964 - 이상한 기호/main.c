/*
https://www.acmicpc.net/problem/15964
*/

#include <stdio.h>



int main(void){
    long a,b;
    scanf("%ld %ld", &a, &b);
    printf("%ld", (a+b)*(a-b));
    return 0;
}