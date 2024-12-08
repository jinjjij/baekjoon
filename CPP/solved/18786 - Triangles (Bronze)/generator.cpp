#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    FILE* fptr = fopen("input.txt", "wt");
    for(int i=0;i<n;i++){
        fprintf(fptr, "%d %d\n", rand()%2000 - 1000,rand()%2000 - 1000);
    }
    
    fclose(fptr);
    return 0;
}
