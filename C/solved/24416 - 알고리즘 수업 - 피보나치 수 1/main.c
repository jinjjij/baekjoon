/*
https://www.acmicpc.net/problem/24416 - 알고리즘 수업 - 피보나치 수 1 

230105 - 230106 solved
*/




#include <stdio.h>


int f[50];
int code1, code2;


int fib(int n){
    if(n == 1 || n == 2 ){
        code1 ++;
        return 1;
    }else{
        return fib(n-1) + fib(n-2);
    }
}


int fibonacci(int n){
    f[2] = 1;
    f[1] = f[2];

    for(int i=3;i<n+1;i++){
        code2 ++;
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}



int main(void){
    code1 = 0;
    code2 = 0;

    int n = 0;
    scanf("%d", &n);

    fib(n);
    fibonacci(n);


    printf("%d %d", code1, code2);

    return 0;
}