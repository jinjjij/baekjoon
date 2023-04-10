/*
https://www.acmicpc.net/problem/10101
*/

#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if(a==b && b==c && a==60){
        printf("Equilateral");
    }
    else if(a+b+c != 180){
        printf("Error");
    }
    else if(a==b || b==c || c==a){
        printf("Isosceles");
    }
    else{
        printf("Scalene");
    }
    return 0;
}