/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>

int mem[2][100000] = {0,};
int arr[2][100000] = {0,};


int process(int n, int up){
    if(mem[up][n] != -1){
        return mem[up][n];
    }

    if(n==0){
        mem[up][n] = arr[up][0];
        return arr[up][0];
    }

    if(n==1){
        if(up){
            mem[up][n] = arr[1][1] + arr[0][0];
            return arr[1][1] + arr[0][0];
        }else{
            mem[up][n] = arr[0][1] + arr[1][0];
            return arr[0][1] + arr[1][0];
        }
    }

    int max = 0;
    int temp = 0;

    temp = process(n-2, !up);
    if(max < temp)  max = temp;

    temp = process(n-1, !up);
    if(max < temp)  max = temp;

    max += arr[up][n];

    mem[up][n] = max;
    return max;
}


int main(void){
    int T;
    int n;

    scanf("%d", &T);
    for(int t=0;t<T;t++){
        scanf("%d", &n);
        for(int i=0;i<n;i++)    scanf("%d", &arr[0][i]);
        for(int i=0;i<n;i++)    scanf("%d", &arr[1][i]);
        for(int i=0;i<n;i++){
            mem[0][i] = -1;
            mem[1][i] = -1;
        }

        int max = process(n-1, 1);
        int temp = process(n-1, 0);
        if(max<temp)    max = temp;

        printf("%d\n", max);
    }
    return 0;
}