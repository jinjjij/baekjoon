#include <iostream>

int GetPathNum_dynamic(int* data_arr, int n){
    if(n==1){
        data_arr[n] = 1;
        return 1;
    }

    if(n == 2){
        data_arr[n] = 2;
        return 2;
    }

    if(data_arr[n-1] == 0){
        data_arr[n-1] = GetPathNum_dynamic(data_arr, n-1);
    }

    if(data_arr[n-2] == 0){
        data_arr[n-2] = GetPathNum_dynamic(data_arr, n-2);
    }

    data_arr[n] = data_arr[n-1] + data_arr[n-2];
    return data_arr[n];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arr[41] = {0,};
    while(1){
        int input = 0;
        std::cin >> input;
        if(input == 0)  break;
        else    std::cout << GetPathNum_dynamic(arr, input) << "\n";
    }

    return 0;
}