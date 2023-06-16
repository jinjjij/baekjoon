#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
    // if 인풋이 2개가 아님 -> 디폴트 값으로 진행
    // test할 프로그램 이름
    char programName[100];
    // 인풋 파일이름
    char inputFileName[100];

    if(argc == 3){
        strcpy(programName,argv[1]);
        strcpy(inputFileName,argv[2]);
    }else if(argc == 1){
        strcpy(programName,"a.exe");
        strcpy(inputFileName,"input.txt");
    }else{
        fprintf(stderr, "test.exe \"program name\" \"input file name\"\n");
    }
    
    // 아웃풋 파일에 인풋 + 결과
    FILE* inputFile = fopen(inputFileName, "rt");
    FILE* outputFile = fopen("testOut.txt", "wt");

    

    // 콘솔창에 성공/실패/전체 출력

    fclose(inputFile);
    fclose(outputFile);
}