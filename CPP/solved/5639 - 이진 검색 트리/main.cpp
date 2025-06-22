#include <iostream>
#include <vector>


std::vector<int> pre;


void solve(std::vector<int>& output, int l, int r){
    if(l>=r) return;

    int mid = l+1;

    while(mid < r && pre[l] > pre[mid])    mid++;

    solve(output, l+1, mid);
    solve(output, mid, r);
    output.push_back(pre[l]);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int input;
    
    while(std::cin >> input){
        pre.push_back(input);
    }

    std::vector<int> output;
    solve(output, 0, pre.size());
    
    for(int i:output){
        std::cout << i << "\n";
    }
    
    return 0;
}