/*
https://www.acmicpc.net/problem/25305 - 커트라인


문제
2022 연세대학교 미래캠퍼스 슬기로운 코딩생활에 $N$명의 학생들이 응시했다.

이들 중 점수가 가장 높은  k 명은 상을 받을 것이다. 이 때, 상을 받는 커트라인이 몇 점인지 구하라.

커트라인이란 상을 받는 사람들 중 점수가 가장 가장 낮은 사람의 점수를 말한다.

입력
첫째 줄에는 응시자의 수 N 과 상을 받는 사람의 수 k 가 공백을 사이에 두고 주어진다.

둘째 줄에는 각 학생의 점수 x 가 공백을 사이에 두고 주어진다.

출력
상을 받는 커트라인을 출력하라.

제한
 1 ≤ N ≤ 1,000
 1 ≤ k ≤ N
 0 ≤ x ≤ 10,000

예제 입력 1 
5 2
100 76 85 93 98

예제 출력 1 
98

*/

#include <stdio.h>


void swap(int* arg1, int* arg2){
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}


void sort(int* arr, int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}


int main(void){
    int N = 0;
    int k = 0;
    int x[1001] = {0,};

    scanf("%d %d", &N, &k);
    
    for(int i=0;i<N;i++){
        scanf("%d", &x[i]);
    }

    sort(x, N);

    printf("%d", x[k-1]);

    
    return 0;
}