#include <stdio.h>
#include <time.h>
#include <stdlib.h>



char* _makeRandName(void){
    char* name = malloc(sizeof(char)*6);
    for(int i=0;i<5;i++){
        char c = rand();
        c%=52;
        
    }
}

int main(void){
    char filename[100] = "inputfile.txt";
    FILE* fptr = fopen(filename, "wt");

    int inputSize;
    scanf("%d", &inputSize);

    fprintf(fptr, "%d\n", inputSize);

    for(int i=0;i<inputSize;i++){
        
    }
}