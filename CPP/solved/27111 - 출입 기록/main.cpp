#include <iostream>
#define SIZE 200001


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    int* person = (int*)malloc(sizeof(int) * SIZE);
    for(int i=0;i<SIZE;i++){
        person[i] = 0;
    }

    int count = 0;
    for(int t = 0;t<N;t++){
        int a, b;
        std::cin >> a >> b;

        if(person[a] == b){
            count ++;
        }
        person[a] = b;
    }

    for(int i=0;i<SIZE; i++){
        if(person[i])  count ++;
    }

    std::cout << count;

    free(person);
    return 0;
}