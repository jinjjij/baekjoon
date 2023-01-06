/*
https://www.acmicpc.net/problem/24060 - 알고리즘 수업 - 병합 정렬 1


문제
오늘도 서준이는 병합 정렬 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

N개의 서로 다른 양의 정수가 저장된 배열 A가 있다. 병합 정렬로 배열 A를 오름차순 정렬할 경우 배열 A에 K 번째 저장되는 수를 구해서 우리 서준이를 도와주자.

크기가 N인 배열에 대한 병합 정렬 의사 코드는 다음과 같다.

merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
    if (p < r) then {
        q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
        merge_sort(A, p, q);      # 전반부 정렬
        merge_sort(A, q + 1, r);  # 후반부 정렬
        merge(A, p, q, r);        # 병합
    }
}

# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
merge(A[], p, q, r) {
    i <- p; j <- q + 1; t <- 1;
    while (i ≤ q and j ≤ r) {
        if (A[i] ≤ A[j])
        then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
        else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
    }
    while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
        tmp[t++] <- A[i++];
    while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
        tmp[t++] <- A[j++];
    i <- p; t <- 1;
    while (i ≤ r)  # 결과를 A[p..r]에 저장
        A[i++] <- tmp[t++]; 
}
입력
첫째 줄에 배열 A의 크기 N(5 ≤ N ≤ 500,000), 저장 횟수 K(1 ≤ K ≤ 108)가 주어진다.

다음 줄에 서로 다른 배열 A의 원소 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

출력
배열 A에 K 번째 저장 되는 수를 출력한다. 저장 횟수가 K 보다 작으면 -1을 출력한다.

예제 입력 1 
5 7
4 5 1 3 2
예제 출력 1 
3

예제 입력 2 
5 13
4 5 1 3 2
예제 출력 2 
-1

*/


#include <stdio.h>
#include <stdlib.h>

int K;
int ret;




void merge(int* arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int t = 0;

    int* tmp = (int*)malloc(sizeof(int) * (right - left + 10));
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            tmp[t++] = arr[i++];
        }else{
            tmp[t++] = arr[j++];
        }
    }

    while(i <= mid){
        tmp[t++] = arr[i++];
    }

    while(j <= right){
        tmp[t++] = arr[j++];
    }

    i = left;
    t = 0;
    while(i <= right){
        arr[i++] = tmp[t++];
        K--;
        //printf("%d : %d\n", K, arr[i-1]);
        if(K == 0){
            ret = arr[i-1];
        }
    }
    free(tmp);
}

void merge_sort(int* arr, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}


int main(void){
    int N;

    scanf("%d %d", &N, &K);
    int* arr = (int*)malloc(sizeof(int) * (N+10));

    for(int n=0;n<N;n++){
        scanf("%d", &arr[n]);
    }

    ret = -1;
    merge_sort(arr, 0, N-1);

    printf("%d", ret);


    free(arr);

    return 0;
}