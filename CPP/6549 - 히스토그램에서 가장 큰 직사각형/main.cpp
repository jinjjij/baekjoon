#include <iostream>
#include <vector>


void build(int node, int left, int right){
    int size = right - left + 1;
    if(size == 1){
        tree[node] = {h[left], h[left], h[left], h[left], h[left]};
        return;
    }

    int mid = (left + right)/2;
    build(node*2, left, mid);
    build(node*2+1, mid+1, right);


}


struct Seg{
    int left;
    int left_h;
    int max;
    int right;
    int right_h;
};

std::vector<int> h;
std::vector<Seg> tree;
int N;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while(true){
        std::cin >> N;
        if(N==0)    break;

        h.assign(N,0);
        tree.assign(N*2,{0,0,0,0,0});

        for(int i=0;i<N;i++){
            std::cin >> h[i];
        }


        build(0,0,N-1);

        std::cout << tree[0].max << "\n";
    }
    

    return 0;
}

/*
    비교대상
    왼쪽 반 결과, 오른쪽 반 결과
    가운데 라인을 포함했을때의 최댓값값
*/