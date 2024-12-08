#include <iostream>


typedef struct {
    int x;
    int y;
} duo;


int MaxTriangle2Times(duo* points, size_t size){
    int max = 0;
    for(int i=0;i<size;i++){for(int j=0;j<size;j++){for(int k=0;k<size;k++){
        int x1 = points[i].x;   int y1 = points[i].y;
        int x2 = points[j].x;   int y2 = points[j].y;
        int x3 = points[k].x;   int y3 = points[k].y;
        if((x1==x2 || x2 == x3 || x1 == x3) && (y1==y2||y2==y3||y3==y1)){
            int tmp = x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3;
            tmp = tmp>0?tmp:-tmp;
            if(tmp>max) max = tmp;
        }
    }}}

    return max;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    duo* posts = (duo*)malloc(sizeof(duo) * n);
    for(int i=0;i<n;i++){
        std::cin >> posts[i].x >> posts[i].y;
    }
    std::cout << MaxTriangle2Times(posts, n);

    free(posts);
    return 0;
}