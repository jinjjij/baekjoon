#include <iostream>


int N = 0;
char str[100] = "";
int Q = 0;


int process(int l, int r){
    int max = 0;
    for(int i=l;i<r;i++){
        int l_index = i;
        int r_index = i+1;
        int count = 0;
        //std::cout << "  " << l_index << ", " << r_index << "\n";
        while(l_index >= l && r_index <= r){
            if(str[l_index] == str[r_index]){
                count ++;
            }
            l_index --;
            r_index ++;
        }
        if(count > max) max = count;
    }

    return max;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N;
    std::cin >> str;
    std::cin >> Q;

    int l,r;
    for(int i=0;i<Q;i++){
        std::cin >> l >> r;
        std::cout << process(l-1,r-1) << "\n";
    }
    return 0;
}