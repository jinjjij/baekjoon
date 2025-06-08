#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<bool> isPrime;
std::vector<int> inputA, inputB;
std::vector<std::vector<int>> adj;
std::vector<int> matchB;
std::vector<bool> vis;
int N;
int fixedB = 0;


void initPrime(int size){
    isPrime.resize(size+1, true);
    isPrime[1] = false;

    for(int i=2;i<=sqrt(size);i++){
        if(isPrime[i] == false) continue;

        for(int j=2*i;j<=size;j+=i){
            isPrime[j] = false;
        }
    }
}


void initDfs(){
    vis.assign(N,false);
    matchB.assign(N, -1);
}


bool dfs(int a){
    for(int b : adj[a]){
        if(vis[b])  continue;
        if(b== fixedB)  continue;
        vis[b] = true;

        if((matchB[b] == -1 || dfs(matchB[b]))){
            matchB[b] = a;
            return true;
        }
    }
    return false;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    adj.resize(N);
    
    int input;
    bool firstElementGroupisA = true;
    for(int i=0;i<N;i++){
        std::cin >> input;

        if(i==0){
            if(input%2) firstElementGroupisA = false;
            else        firstElementGroupisA = true;
        }

        if(input%2){
            if(firstElementGroupisA){
                inputB.push_back(input);
            }else{
                inputA.push_back(input);
            }
        }else{
            if(firstElementGroupisA){
                inputA.push_back(input);
            }else{
                inputB.push_back(input);
            }
        }
    }

    if(inputA.size() != inputB.size()){
        std::cout << "-1";
        return 0;
    }

    initPrime(2020);

    for(int i=0;i<N/2;i++){
        for(int j=0;j<N/2;j++){
            if(isPrime[inputA[i] + inputB[j]])
                adj[i].push_back(j);
        }
    }

    std::vector<int> output;
    
    for (int b : adj[0]) {
        initDfs();
        matchB[b] = 0; // inputA[0]과 inputB[b]를 고정
        fixedB = b;

        int matched = 1;
        for (int a = 1; a < N/2; a++) {
            vis.assign(N/2, false);
            if (dfs(a)) matched++;
        }

        if (matched == N/2) output.push_back(inputB[b]);
    }
    
    std::sort(output.begin(), output.end());
    if(output.size() > 0){
        for(int i=0;i<output.size();i++){
            std::cout << output[i] << " "; 
        }
    }else{
        std::cout << -1;
    }
    
    return 0;
}