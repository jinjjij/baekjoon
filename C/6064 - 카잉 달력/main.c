/*
https://www.acmicpc.net/problem/6064
*/

#include <stdio.h>


// N>M
// return gcd
int exEuclid(int N, int M, int* x, int* y){
    if(N%M==0){
        *x = 1;
        *y = -N/M;
        return M;
    }

    int x1,y1;
    int ret = exEuclid(M, N%M, &x1, &y1);
    int x2 = 1;
    int y2 = -N/M;

    *x = x1*y2;
    *y = x2 + y1*y2;

    return ret;
}


int main(void){
    int N,M,x,y;
    N = 12;
    M = 10;
    int gcd = exEuclid(N,M,&x,&y);
    printf("exEuclid(%d, %d) = %d, x(%d), y(%d)",N,M,gcd,x,y);
    return 0;
}