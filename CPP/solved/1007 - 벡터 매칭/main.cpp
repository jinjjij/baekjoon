#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


long long absMin(long long a, long long b){
    a = a>0?a:-a;
    b = b>0?b:-b;
    return a<b?a:b;
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;

    for(int t=0;t<T;t++){
        int N = 0;
        std::cin >> N;

        std::vector<int> x(N);
        std::vector<int> y(N);
        for(int i=0;i<N;i++){
            std::cin >> x[i] >> y[i];
        }

        long long min = INT64_MAX;

        std::vector<bool> bitmask(N, false);
        std::fill(bitmask.begin(), bitmask.begin() + N/2, true);

        do{
            int sumX = 0;
            int sumY = 0;

            for(int i=0;i<N;i++){
                if(bitmask[i]){
                    sumX += x[i];
                    sumY += y[i];
                }else{
                    sumX -= x[i];
                    sumY -= y[i];
                }
            }

            min = absMin(min, (long long)sumX * sumX + (long long)sumY * sumY);

            //std::cout << "(" << minX << ", " << minY << ")\n";

        }while(std::prev_permutation(bitmask.begin(), bitmask.end()));

        std::cout << std::fixed << std::setprecision(12) << std::sqrt(min) << "\n";
    }
    
    return 0;
}