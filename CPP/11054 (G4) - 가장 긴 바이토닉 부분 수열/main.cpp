#include <iostream>
#include <vector>



int dp_asc_value[1001];
int dp_asc_max[1001];
int dp_desc_value[1001];
int dp_desc_min[1001];

int init(void){
    for(int i=0;i<1001;i++){
        dp_asc_value[i] = 0;
        dp_asc_max[i] = 0;
        dp_desc_value[i] = 0;
        dp_desc_min[i] = 0;
    }
}


int bitonic(std::vector<int> arr){
    // 1~n 사이의 특정값 k 에 대해서
    // 1_k 까지 증가수열  + k~n 까지의 감소수열 - 1

    int n = arr.size();
    printf("\nn = %d\n", n);
    int maxLength = 0;

    printf("[asc]\n");
    // iterate ascending
    for(int i=0;i<n;i++){

        if(i==0){
            dp_asc_max[i] = arr[i];
            dp_asc_value[i] = 1;
            printf("%d ", dp_asc_value[i]);
            continue;
        }

        dp_asc_value[i] = dp_asc_value[i-1];
        dp_asc_max[i] = dp_asc_max[i-1];
        for(int j=0;j<i;j++){
            if(arr[i] > dp_asc_max[j]){
                dp_asc_value[i] = std::max(dp_asc_value[i], dp_asc_value[j] + 1);
                dp_asc_max[i] = arr[i];            
            }else if(arr[i] == dp_asc_max[j]){
                dp_asc_value[i] = dp_asc_value[i];
                dp_asc_max[i] = arr[i];    
            }
        }

        printf("%d ", dp_asc_value[i]);
    }

    printf("\n[desc]\n");
    // iterate descending
    for(int i=n-1;i>=0;i--){

        if(i==n-1){
            dp_desc_min[i] = arr[i];
            dp_desc_value[i] = 1;
            printf("%d ", dp_desc_value[i]);
            continue;
        }

        dp_desc_value[i] = dp_desc_value[i+1];
        dp_desc_min[i] = dp_desc_min[i+1];
        for(int j=n-1;j>i;j--){
            if(arr[i] > dp_desc_min[j]){
                dp_desc_value[i] = std::max(dp_desc_value[i], dp_desc_value[j] + 1);
                dp_desc_min[i] = arr[i];            
            }
        }
        printf("%d ", dp_desc_value[i]);
    }


    // iterate through 0 ~ size of arr    
    for(int i=0;i<n;i++){
        
        // max length of ascending series in range 0 ~ i
        // max length of descending series in range i ~ size
        // returns ascending + descending length - 1
        maxLength = std::max(maxLength, dp_asc_value[i] + dp_desc_value[i] - 1);
    }


    return std::min(n, maxLength);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::vector<int> A;

    init();

    std::cin >> N;

    int tmp;
    for(int i=0;i<N;i++){
        std::cin >> tmp;
        A.push_back(tmp);
    }
    std::cout << bitonic(A);

    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9
1 5 2 1 4 3 4 5 2 1

k=0
1 + 5 - 1 = 5

k=1
2 + 5 - 1 = 6

k=2
2 + 4 - 1 = 5

k=3
2 + 4 - 1 = 5

k=4
3 + 4 - 1 = 6

k=5
3 + 3 - 1 = 5

k=6
4 + 3 - 1 = 6

k=7
5 + 3 - 1 = 7 <<<

k=6
5 + 2 - 1 = 6

k=7
5 + 1 - 1 = 5

*/