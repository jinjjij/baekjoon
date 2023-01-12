/*
https://www.acmicpc.net/problem/17356 - 욱 제

*/

#include <stdio.h>
#include <math.h>


int main(void){
    double A, B;

    scanf("%lf %lf", &A, &B);

    double M = (B-A)/(double)400;
    printf("%.20lf", (double)1/(double)(1 + pow(10, M)));

    return 0;
}