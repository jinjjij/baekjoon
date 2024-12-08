#include <iostream>


int GetDiff(int a ,int b){
    return a>b?a-b:b-a;
}



bool IsJollyJumper(size_t size, int* arr){
    bool ret = true;
    if(size == 0)   return true;


    std::qsort(arr, size, sizeof(int), [](const void* a, const void* b)->int{
        return *(int *)a - *(int *)b;
    });

    for(int i=0;i<size;i++){
        if(arr[i] != i+1){
            ret = false;
            break;
        }
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int arr[4000];
    int diffarr[4000];

    while(1){
        int n = 0;
        if(std::cin.eof()){
            break;
        }
        std::cin >> n;

        for(int i=0;i<n;i++){
            std::cin >> arr[i];
        }


        for(int i=0;i<n-1;i++){
            diffarr[i] = GetDiff(arr[i], arr[i+1]);
        }

        std::cout << (IsJollyJumper(n-1, diffarr)?"Jolly\n":"Not jolly\n");
    }
    
    return 0;
}

// 5 6 7 8 9 size=5