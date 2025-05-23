#include <iostream>
#include <vector>


typedef long long int lld;


lld process(int left, int right, std::vector<int> arr){
    int mid = (left + right)/2;

    if(right == left){
//        fprintf(stderr, "\nprocess(%d, %d) = %d ended\n", left, right, arr[left]);
        return arr[left];
    }

    lld lOut = process(left, mid, arr);
    lld rOut = process(mid+1, right, arr);

    // 가운데 두줄을 포함하는 최댓값
    lld mMax = 0;
    int testHeight = std::min<int>(arr[mid], arr[mid+1]);

    for(int i=1;i<=testHeight;i++){
        int l = mid;
        int r = mid+1;

        while(true){
            if(l>left && arr[l-1] >= i){
                l--;
            }else{
                break;
            }
        }

        while(true){
            if(r<right && arr[r+1] >= i){
                r++;
            }else{
                break;
            }
        }

        lld curArea = (r-l+1)*i;
        if(curArea > mMax)  mMax = curArea;
//        fprintf(stderr, "\n%d(l:%d, r:%d)->%lld", i, l, r, curArea);
    }

    //fprintf(stderr, "\nprocess(%d, %d)(%lld, %lld, %lld) = %lld ended\n", left, right, lOut, rOut, mMax, std::max<lld>(std::max<lld>(lOut, rOut),mMax));
    return std::max<lld>(std::max<lld>(lOut, rOut),mMax);
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    while(true){
        // input
        std::cin >> n;

        if(n == 0){
            break;
        }

        std::vector<int> input;
        for(int i=0;i<n;i++){
            int tmp;
            std::cin >> tmp;
            input.push_back(tmp);
        }

        // output
        std::cout << process(0, n-1, input) << "\n";
    }

    return 0;
}

/*
    비교대상
    왼쪽 반 결과, 오른쪽 반 결과
    가운데 라인을 포함했을때의 최댓값값
*/