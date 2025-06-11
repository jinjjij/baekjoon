#include <iostream>
#include <vector>


int N,K,size;
std::vector<int> segTree;


void _processNodeDown(int index){
    
}


void InitSegTree(){

}


void update(int index){

}


int findKth(int index){
    int curCount = 0;
    while(true){

    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N >> K;
    segTree.assign(4*N, 1);
    size = 1;
    while(size < N) size *= 2;

    int size = N;
    int curIndex = -1;
    while(size > 0){
        int next = findKth(curIndex);
        update(next);
        curIndex = next;
        size -- ;
    }

    
    return 0;
}

/* K=3
1 2 3 4 5 6 7
1 1 1 1 1 1 1
2   2   2   1
4       3
7

1 2 X 4 5 6 7
1 1 0 1 1 1 1
2   1   2   1
3       3
6

1 2 X 4 5 6 7
1 1 0 1 1 1 1
2   1   2   1
3       3
6


1 2 3 4 5 6 7
1 1 1 1 1 1 1
2   2   2   1
4       3
7

1 2 3 4 5 6 7
1 1 1 1 1 1 1
2   2   2   1
4       3
7

1 2 3 4 5 6 7
1 1 1 1 1 1 1
2   2   2   1
4       3
7

1 2 3 4 5 6 7
1 1 1 1 1 1 1
2   2   2   1
4       3
7

*/