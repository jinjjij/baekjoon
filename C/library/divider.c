
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* getDivs(int N, int* divNum){
    int* arr = (int*)malloc(sizeof(int) * N);
    int tmpidx = 0;

    for(int i=1;i<=(int)sqrt((double)N);i++){
        if(N%i==0){
            arr[tmpidx++] = i;
        }
    }

    int len = tmpidx;
    int temp = 0;

    for(int i=len-1;i>=0;i--){
        temp = N/arr[i]    ;
        if(temp == arr[i]){
            continue;
        }

        arr[tmpidx++] = temp;
    }

    *divNum = tmpidx;

    int* retArr = (int*)malloc(sizeof(int) * tmpidx);

    for(int i=0;i<tmpidx;i++){
        retArr[i] = arr[i];
    }


    free(arr);

    return retArr;
}


int main(void){
    int N = 0;
    scanf("%d", &N);
    int len = 0;

    int* divs = getDivs(N, &len);

    for(int i=0;i<len;i++){
        printf("%d, ", divs[i]);
    }
    return 0;
}