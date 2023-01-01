// https://www.acmicpc.net/problem/7662

#include <stdio.h>


int T;      // 입력 데이터의 수를 나타내는 정수 T
int k;      // Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)


int main(void){
    FILE* readMod;

    readMod = stdin;

    // test
    readMod = fopen("input.txt", "rw");

    fscanf(readMod, "%d", &T);
    
    for(int t=0; t<T; t++){
        fscanf(readMod, "%d", &k);
        
        char inputC;
        int inputI;

        for(int i=0;i<k;i++){
            fscanf(readMod, "%c, %d", &inputC, &inputI);
            


        }
    }

    // test
    fclose(readMod);

    return 0;
}