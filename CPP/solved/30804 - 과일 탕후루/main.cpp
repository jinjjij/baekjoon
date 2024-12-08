#include <iostream>

int GetMaxSuccessiveFruit(int size, int* arr){
    
    int max = 0;
    for(int i=0;i<size;i++){
        // i부터 시작해서 어디까지 연속인지 확인
        int used_int[2] = {0,0};
        int count = 0;
        int next_index = i;
        for(int j=i;j<size;j++){
            int tmp = arr[j];

            if(used_int[0] == tmp || used_int[1] == tmp){
                count++;
            }else if(used_int[0] == 0){
                used_int[0] = tmp;
                count++;
            }else if(used_int[1] == 0){
                used_int[1] = tmp;
                count++;
            }else{break;}

            if(tmp == used_int[0]){
                next_index ++;
            }
        }

        if(max < count){
            max = count;
        } 
        i = next_index-1;

    }

    return max;
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int* arr = (int*)malloc(sizeof(int) * N);
    for(int i=0;i<N;i++){
        std::cin >> arr[i];
    }

    std::cout << GetMaxSuccessiveFruit(N, arr);

    free(arr);
    return 0;
}