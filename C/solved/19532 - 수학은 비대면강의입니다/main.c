/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>

int main(void){
    int a,b,c,d,p,q;
    scanf("%d %d %d %d %d %d", &a, &b, &p, &c, &d, &q);
    int x = (p*d-b*q)/(a*d-b*c);
    int y = (a*q-p*c)/(a*d-b*c);
    printf("%d %d", x, y);
    return 0;
}