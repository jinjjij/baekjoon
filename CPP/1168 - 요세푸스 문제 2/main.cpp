#include <iostream>
#include <vector>


int N,K,size;
std::vector<int> arr;
std::vector<int> segTree;


void build(int node, int left, int right){
    if(left == right){
        segTree[node] = arr[left];
        return;
    }

    int mid = (left + right)/2;
    build(node*2, left, mid);
    build(node*2+1, mid+1, right);
}


void update(int node, int left, int right, int index, int value){
    if(left == right){
        segTree[node] = value;
        return;
    }

    int mid = (left + right)/2;
    if(index <= mid){
        update(node*2, left, mid, index, value);
    }else{
        update(node*2+1, mid+1, right, index, value);
    }
    segTree[node] = segTree[node*2] + segTree[node*2+1];
}


int findKth(int node, int left, int right, int count){
    
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N >> K;
    segTree.assign(4*N, 1);
    build(0, 0, N-1);

    int size = N;
    int curIndex = -1;
    while(size > 0){
        int next = findKth(curIndex);
        update(0, 0, N-1, next, 0);
        curIndex = next;
        size -- ;
    }

    
    return 0;
}

/* K=3

0   1   3   7   <- 0
            8   <- 1   
        4   9   <- 2
            10  <- 3
    2   5   11  <- 4
            12  <- 5
        6   13  <- 6
            14  <- 7

*/