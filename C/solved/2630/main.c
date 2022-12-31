#include <stdio.h>




int N;              // 입력으로 주어진 종이의 한 변의 길이
int arr[128][128];  // 입력 array
int whiteCount;
int blueCount;


void isSquare(int x, int y, int size){
    int flg = 1;

    for(int i=x; i < x+size; i++){
        for(int j=y; j<y+size; j++){
            if(arr[i][j] != arr[x][y]){
                flg = 0;
                break;
            }
        }
        if(!flg)
            break;
    }

    if(flg == 1){
        if(arr[x][y] == 1){
            blueCount ++;
        }else{
            whiteCount ++;
        }
    }else{
        int newSize = size/2;
        isSquare(x          , y          , newSize);
        isSquare(x + newSize, y          , newSize);
        isSquare(x          , y + newSize, newSize);
        isSquare(x + newSize, y + newSize, newSize);
    }
}


int main(void){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    whiteCount = 0;
    blueCount = 0;

    isSquare(0, 0, N);
    
    printf("%d\n%d", whiteCount, blueCount);
    return 0;
}