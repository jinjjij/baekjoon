/*
https://www.acmicpc.net/problem/2485
*/

#include <stdio.h>


int Euclid(int N, int M){
    if(N<1 || M<1){
        return -1;
    }

    if(N==1 || M == 1){
        return 1;
    }

    if(N<M){
        int tmp = M;
        M = N;
        N = tmp;
    }

    if(N%M == 0){
        return M;
    }else{
        return Euclid(M, N%M);
    }
}


int main(void){
    int N;
    scanf("%d", &N);

    int deltaPos[100001];
    int prevPos = 0;
    int curPos;
    int gcd = 0;;

    for(int i=0;i<N;i++){
        scanf("%d", &curPos);

        if(i == 0)
            prevPos = curPos;
        else{
            int tmp = curPos - prevPos;
            deltaPos[i-1] = tmp;

            if(gcd == 0){
                gcd = tmp;
            }
            else{
                gcd = Euclid(gcd, tmp);
            }

            prevPos = curPos;
        }
    }

    int result = 0;
    for(int i=0;i<N-1;i++){
        result += deltaPos[i]/gcd - 1;
    }

    printf("%d", result);
    return 0;
}