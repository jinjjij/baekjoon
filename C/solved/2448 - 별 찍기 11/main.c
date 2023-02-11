/*
https://www.acmicpc.net/problem/2448 - 별 찍기 11
*/

#include <stdio.h>



char arr[3100][7000];


void initArr(void){
    for(int i=0;i<3100;i++){
        for(int j=0;j<7000;j++){
            arr[i][j] = 0;
        }
    }
}


void setArr(int size, int row, int col){
    int size_h = size*2-1;
    int size_v = size;

    if(size == 3){
        arr[row  ][col+2] = 1;
        arr[row+1][col+1] = 1;
        arr[row+1][col+3] = 1;
        arr[row+2][col  ] = 1;
        arr[row+2][col+1] = 1;
        arr[row+2][col+2] = 1;
        arr[row+2][col+3] = 1;
        arr[row+2][col+4] = 1;
    }else{
        setArr(size/2, row           , col + size/2  );
        setArr(size/2, row + size/2  , col           );
        setArr(size/2, row + size/2  , col + size    );
    }
}


void printArr(int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size*2+1;j++){
            if(arr[i][j])   printf("*");
            else            printf(" ");
        }
        printf("\n");
    }
}


int main(void){
    int N;
    scanf("%d", &N);
    initArr();
    setArr(N,0,0);
    printArr(N);
    return 0;
}
