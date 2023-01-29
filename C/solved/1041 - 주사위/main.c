/*
https://www.acmicpc.net/problem/1041
*/

#include <stdio.h>


typedef long long lld;



int min1(int* arr){
    int min = arr[0];
    for(int i=0;i<6;i++){
        if(min>arr[i])  min = arr[i];
    }
    return min;
}

int max1(int* arr){
    int max = arr[0];
    for(int i=0;i<6;i++){
        if(max<arr[i])  max = arr[i];
    }
    return max;
}


int min2(int* arr){
    int min = arr[0] + arr[1];

    for(int i=0;i<6;i++){
        for(int j=0;j<i;j++){
            if(i==j)    continue;
            if(i==5 && j==0)    continue;
            if(i==4 && j==1)    continue;
            if(i==3 && j==2)    continue;

            int ijsum = arr[i]+arr[j];
            if(min > ijsum)     min = ijsum;
        }
    }

    return min;
}


int min3(int* arr){
    //abc 012
    int temp = arr[0] + arr[1] + arr[2];
    int min = temp;
    // ace 024
    temp = arr[0] + arr[2] + arr[4];
    if(min>temp)    min = temp;
    // ade 034
    temp = arr[0] + arr[3] + arr[4];
    if(min>temp)    min = temp;
    // abd 013
    temp = arr[0] + arr[1] + arr[3];
    if(min>temp)    min = temp;
    // fbc 512
    temp = arr[5] + arr[1] + arr[2];
    if(min>temp)    min = temp;
    // fce 524
    temp = arr[5] + arr[2] + arr[4];
    if(min>temp)    min = temp;
    // fde 534
    temp = arr[5] + arr[3] + arr[4];
    if(min>temp)    min = temp;
    // fbd 513
    temp = arr[5] + arr[1] + arr[3];
    if(min>temp)    min = temp;

    return min;
}


int main(void){
    lld N;
    int a[6];
    scanf("%d", &N);
    for(int i=0;i<6;i++)    scanf("%d", &a[i]);

    lld ret = 0;


    if(N==1){
        for(int i=0;i<6;i++){
            ret += a[i];
        }
        ret -= max1(a);
    }else{
        // 1
        ret += (N-2) * (5*N-6) * min1(a);

        // 2
        ret += (8*N - 12) * min2(a);

        // 3
        ret += 4 * min3(a);
    }

    

    printf("%lld", ret);

    return 0;
}