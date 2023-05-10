/*
https://www.acmicpc.net/problem/4134
*/

#include <stdio.h>
#include <math.h>



typedef long long int lld;


// if prime, return 1
// else    , return 0
int isPrime(lld n){
    if(n==0)    return 0;
    if(n==1)    return 0;
    if(n==2)    return 1;

    int isPrime = 1;
    for(lld i=2;i<=(lld)sqrt((double)n);i++){
        if(n%i==0){
            isPrime = 0;
            break;
        }
    }

    return isPrime;
}



int main(void){
    // testcase
    int T;
    scanf("%d", &T);


    // testcase loop
    for(int t=0;t<T;t++){
    
        lld n;
        scanf("%lld", &n);

        while(!isPrime(n)){
            n++;
        }

        printf("%lld\n", n);
    }
    return 0;
}