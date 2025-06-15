#include <iostream>
#include <vector>


int N,K;
std::vector<int> segTree;
int leftCount;


void build(int node, int left, int right){
    if(left == right){
        segTree[node] = 1;
        return;
    }
    
    int mid = (left + right)/2;
    build(node*2, left, mid);
    build(node*2+1, mid+1, right);


    segTree[node] = segTree[node*2] + segTree[node*2+1];
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


int cumulativeSum(int node, int left, int right, int index){
    if(left == right){
        return segTree[node];
    }

    int mid = (left + right)/2;

    if(index <= mid){
        return cumulativeSum(node*2, left, mid, index);
    }else{
        return segTree[node*2] + cumulativeSum(node*2+1, mid+1, right, index);
    }
}


int _findKth(int node, int left, int right, int count){
    int mid = (left + right)/2;

    if(segTree[node*2] < count){
        return _findKth(node*2+1, mid+1, right, count-segTree[node*2]);
    }else if(segTree[node*2] == count){
        return mid;
    }else{
        return _findKth(node*2, left, mid, count);
    }
}


int findKth(int start, int Kcount){
    if(leftCount > Kcount){
        Kcount = Kcount % leftCount;
    }
    int startSum = cumulativeSum(1, 0, N-1, start);

    if(startSum + Kcount > leftCount){
        // 처음부터 startSum + Kcount - leftcount 만큼 떨어진거 구함
        return _findKth(1, 0, N-1, startSum + Kcount - leftCount);
    }else{
        // 0 부터 kcount + startSum 구함
        return _findKth(1, 0, N-1, Kcount + startSum);
    }

}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> K;
    segTree.assign(4*N+1, 1);
    build(1, 0, N-1);
    leftCount = N;

    int curIndex = N-1;
    //std::cout << "<";
    while(leftCount > 0){
        
        int next = findKth(curIndex, K);
        printf("%d : %d\n", leftCount, next+1);
        //std::cout << next+1;
        //if(leftCount != 1)  std::cout << ", ";
        update(1, 0, N-1, next, 0);
        curIndex = next;
        leftCount -- ;
    }
    //std::cout << ">";
    printf("\nend?");
    
    return 0;
}               
