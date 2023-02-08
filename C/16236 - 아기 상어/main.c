/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>

int N;
int board[21][21];



int abs(int n){
    return n<0?-n:n;
}


int taxiDistance(int x1, int y1, int x2, int y2){
    return abs(y2 - y1) + abs(x2 - x1);
}


int getPos(int size, int x, int y, int* minDist){
    int pos = 0;
    int min = 100;
    int minPos = -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int dist = taxiDistance(x,y,i,j);
            if(board[i][j]!=0 && board[i][j]<=size && dist < min){
                minPos = i*N+j;
                min = dist;
            }
        }
    }

    *minDist = min;
    return minPos;
}


int main(void){
    int x,y,size;
    size = 2;

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &board[i][j]);
            if(board[i][j]==9){
                x=i;y=j;
            }
        }
    }

    int time = 0;
    int pos = y+x*N;
    int nextPos = -1;
    int dist = 0;
    int feedCount = 0;
    while(1){
        nextPos = getPos(size, pos/N, pos%N, &dist);
        printf("%d, %d -> %d\n", nextPos/N, nextPos%N, time);
        if(nextPos==-1){
            break;
        }
        time += dist;
        feedCount ++;
        if(feedCount == size){
            size++;
            feedCount = 0;
            printf("promoted! : %d\n", size);
        }

        board[nextPos/N][nextPos%N] = 0;
        pos = nextPos;
    }

    printf("%d", time);
    return 0;
}