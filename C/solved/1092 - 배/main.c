/*
https://www.acmicpc.net/problem/1092
*/

#include <stdio.h>
#include <stdlib.h>


int cmp(const void* arg1, const void* arg2){
    return *(int*)arg1 - *(int*)arg2;
}



int main(void){
    int N,M;



    scanf("%d", &N);
    int* crane = (int*)malloc(sizeof(int) * N);
    int* craneIndex = (int*)malloc(sizeof(int) * N);
    for(int i=0;i<N;i++)    scanf("%d", &crane[i]);

    scanf("%d", &M);
    int* box = (int*)malloc(sizeof(int) * M);
    for(int i=0;i<M;i++)    scanf("%d", &box[i]);

    qsort(box, M, sizeof(int), cmp);
    qsort(crane, N, sizeof(int), cmp);

/*
    printf("box : ");
    for(int i=0;i<M;i++){
        printf("%d ", box[i]);
    }
    printf("\ncrane : ");
    for(int i=0;i<N;i++){
        printf("%d ", crane[i]);
    }printf("\n");
*/


    int j=0;
    for(int i=0;i<N;i++){
        //printf("%dloop :\n", i);
        
        //printf("crane[%d] = %d\t box[%d] = %d\n", i, crane[i], j, box[j]);
        while(j<M && crane[i] >= box[j]){
            //printf("crane[%d] = %d\t box[%d] = %d\n", i, crane[i], j, box[j]);
            j++;
        }
        craneIndex[i] = j-1;
        //printf("craneIndex[%d] : %d\n", i, craneIndex[i]);
    }
    //printf("\n");

    int time = 1;
    int boxSize = M;
    int flg = 0;
    while(1){
        flg = 1;
        for(int i=0;i<N;i++){
            if(craneIndex[i] == -1) continue;

            while(box[craneIndex[i]]==0 && craneIndex[i] > 0){
                craneIndex[i]--;
            }
            
            if(box[craneIndex[i]] != 0){
                flg = 0;
                box[craneIndex[i]] = 0;
                boxSize--;
                //printf("crane #%d : (%d)index = %d moved\n", i, time, craneIndex[i]);
                
            }
        }

        if(boxSize == 0){
            break;
        }

        if(flg){
            time = -1;
            break;
        }

        time++;
    }

    printf("%d", time);
    free(crane);
    free(craneIndex);
    free(box);
    return 0;
}