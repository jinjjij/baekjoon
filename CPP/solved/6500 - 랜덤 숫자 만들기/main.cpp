#include <iostream>
#include <unordered_set>


int pseudoRandom(int origin){
    origin *= origin;
    return (origin%1000000 - origin%100)/100;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int testCase = 0;
    while(true){
        std::cin >> testCase;
        if(testCase == 0)   break;
        
        std::unordered_set<int> vis;
        int count = 0;

        while(vis.find(testCase) == vis.end()){
            vis.insert(testCase);
            testCase = pseudoRandom(testCase);
            count ++;
        }

        std::cout << count << "\n";
    }
    
    return 0;
}