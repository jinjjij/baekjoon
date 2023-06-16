/*
https://www.acmicpc.net/problem/17103
*/

#include <stdio.h>
#include <math.h>



int Primes[1000000];


int isPrime(int N){
    if(N == 1)  return 0;
    if(N == 2)  return 1;

    int sqrtN = (int)sqrt((double)N);

    for(int i=2;i<=sqrtN;i++){
        if(Primes[i] && N%i==0)  return 0;
    }

    return 1;
}


int goldBachCount(int N){
    int count = 0;
    for(int i=2;i<=N/2;i++){
        if(Primes[i] && Primes[N-i]){
            count ++;
        }
    }
    return count;
}


int main(void){

    for(int i=1;i<=1000000;i++){
        Primes[i] = isPrime(i);
    }


    int T = 0;
    scanf("%d", &T);

    int N = 0;
    for(int t=0;t<T;t++){
        scanf("%d", &N);
        printf("%d\n", goldBachCount(N));
    }
    return 0;
}