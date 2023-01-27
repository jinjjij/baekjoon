/*
https://www.acmicpc.net/problem/16139
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200000


void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n') {}
}



int main(void){
    char str[SIZE+10];
    int N;

    scanf("%s", str);
    clear_stdin();
    scanf("%d", &N);

    int sum[26] = {0,};
    int prefixSum[26][SIZE+10] = {0,};
    char c;
    int len = strlen(str);

    for(int i=0;i<len;i++){
        sum[str[i]-'a']++;
        for(int j=0;j<26;j++){
            prefixSum[j][i] = sum[j];
        }
    }

    int from, to, ret;

    for(int i=0;i<N;i++){
        clear_stdin();
        scanf("%c %d %d", &c, &from, &to);
        ret = prefixSum[c-'a'][to];
        if(from){
            ret -= prefixSum[c-'a'][from-1];
        }

        printf("%d\n", ret);
    }

    return 0;
}