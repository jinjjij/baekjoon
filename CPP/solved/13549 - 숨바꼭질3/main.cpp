#include <iostream>
#include <queue>
#include <vector>


typedef struct node{
    int pos;
    int level;
} node;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n , k;
    bool visited[200001] = {false};
    //int parent[200001] = {-1};
    std::cin >> n >> k;

    std::deque<node> dq;
    dq.push_front({n, 0});
    visited[n] = true;

    node curNode;
    int output = 0;
    while(!dq.empty()){    
        curNode = dq.front();
        dq.pop_front();

        int p = curNode.pos;
        if(curNode.pos == k){
            output = curNode.level;
            break;
        }

        if(p<k && !visited[p*2]){
            dq.push_front({p*2, curNode.level});
            visited[p*2] = true;
            //parent[p*2] = p;
        }
        if(0<p && !visited[p-1]){
            dq.push_back({p-1, curNode.level+1});
            visited[p-1] = true;
            //parent[p-1] = p;
        }
        if(p<k && !visited[p+1]){
            dq.push_back({p+1, curNode.level+1});
            visited[p+1] = true;
            //parent[p+1] = p;
        }
    }

    /*
    int cur = k;
    while(cur != n){
        std::cout << cur << " ";
        cur = parent[cur];
    }
    std::cout << n << "\n";
*/
    std::cout << output;
    
    return 0;
}


