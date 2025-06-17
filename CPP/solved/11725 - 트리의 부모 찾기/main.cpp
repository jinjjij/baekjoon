#include <iostream>
#include <vector>
#include <stack>



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    std::vector<int> input(N+1);

    std::vector<std::vector<int>> adj(N+1);

    int a, b;
    for(int i=0;i<N;i++){
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    std::vector<int> parent(N+1);
    std::vector<bool> vis(N+1, false);

    std::stack<int> st;

    st.push(1);

    while(!st.empty()){
        int cur = st.top(); st.pop();
        if(vis[cur])    continue;

        vis[cur] = true;

        for(int i : adj[cur]){
            if(vis[i])  continue;
            parent[i] = cur;
            st.push(i);
        }
    }

    for(int i=2;i<=N;i++){
        std::cout << parent[i] << "\n";
    }
    
    return 0;
}
