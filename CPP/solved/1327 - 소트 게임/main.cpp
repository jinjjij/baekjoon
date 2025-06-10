#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>


int vector2Int(std::vector<int> vec){
    int ret = 0;
    for(int i=0;i<vec.size();i++){
        ret = ret*10 + vec[i];
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int K, N;
    std::cin >> N >> K;

    std::unordered_set<int> vis;
    std::vector<int> origin(N);
    for(int i=0;i<N;i++){
        std::cin >> origin[i];
    }


    std::queue<std::pair<std::vector<int>, int>> q;
    q.push({origin, 0});
    vis.insert(vector2Int(origin));
    int ret = -1;

    while(!q.empty()){
        std::pair<std::vector<int>, int> cur = q.front();
        q.pop();
        /*
        for(int i=0;i<N;i++){
            std::cout << cur.first[i] << " ";
        }
        std::cout << cur.second << "\n";
        */

        bool flg = true;
        for(int i=1;i<cur.first.size();i++){
            if(cur.first[i-1] > cur.first[i])   flg = false;
        }

        if(flg){
            ret = cur.second;
            break;
        }


        for(int i=0;i<N-K+1;i++){
            std::vector<int> newVec = cur.first;
            std::reverse(newVec.begin() + i, newVec.begin() + i + K);
            if(vis.count(vector2Int(newVec)) == 0){
                vis.insert(vector2Int(newVec));
                q.push({newVec, cur.second+1});
            }
        }
    }


    std::cout << ret;
    
    return 0;
}