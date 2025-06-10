#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


struct goodNum {
    int offset;
    int left, right;
    
    long long score() const {
        return 1LL * (offset + 1) * (right - left - offset + 1) - 1;
    }

    // min-heap 기준 (좋은 수가 더 위로)
    bool operator<(const goodNum& other) const {
        long long a = this->score();
        long long b = other.score();
        if (a != b) return a > b;          // 작은 score 우선 (min-heap)
        return left > other.left;          // score 같으면 작은 left 우선
    }
};


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int L, N;
    std::cin >> L;

    std::vector<int> input(L);
    std::vector<std::pair<long long, int>> output;
    
    for(int i=0;i<L;i++){
        std::cin >> input[i];
    }
    std::cin >> N;

    std::sort(input.begin(), input.end());

    for(int i : input){
        output.push_back({0, i});
    }


    std::priority_queue<goodNum> pq;

    for(int i=1;i<input.size();i++){
        if(input[i] - input[i-1] == 1){
            continue;
        }

        pq.push({0, input[i-1]+1, input[i]-1});
    }
    if(input[0] != 1){
        if(input[0] == 2)   output.push_back({0,1});
        else                pq.push({0, 1, input[0]-1});
    }   


    while(!pq.empty() && output.size() < N){
        goodNum cur = pq.top();
        pq.pop();

        int v_left, v_right;
        v_left = cur.left + cur.offset;
        v_right = cur.right - cur.offset;

        long long score = cur.score();

        if(v_left == v_right){
            output.push_back({score, v_left});
        }else if(v_right - v_left == 1){
            output.push_back({score, v_left});
            output.push_back({score, v_right});
        }else{
            output.push_back({score, v_left});
            output.push_back({score, v_right});
            pq.push({cur.offset + 1, cur.left, cur.right});
        }

        
    }

    int last = input[input.size()-1]+1;
    while(output.size() < N){
        output.push_back({__LONG_LONG_MAX__, last});
        last ++;
    }


    std::sort(output.begin(), output.end());

    for(int i=0;i<N;i++){
        //std::cout << output[i].second << ": " << output[i].first << "\n";
        std::cout << output[i].second << " ";
    }

    
    return 0;
}