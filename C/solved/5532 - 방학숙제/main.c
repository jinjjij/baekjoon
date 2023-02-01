#include <stdio.h>


int max(int a,int b){
    return a>b?a:b;
}

int main(void){
    int a,b,c,d,e;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    printf("%d",a-max(b/d+(b%d?1:0),c/e+(c%e?1:0)));
    return 0;
}
