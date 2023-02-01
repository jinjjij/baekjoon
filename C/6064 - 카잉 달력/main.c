/*
https://www.acmicpc.net/problem/6064
*/

#include <stdio.h>


// N>M
// return gcd
int exEuclid(int N, int M, int* s, int* t){
    //printf("exEuclid(%d, %d)\n", N, M);
    int si,si1,si2,ti,ti1,ti2,ri,ri1,ri2,qi;
    si1=0;si2=1;ti1=1;ti2=0;ri2=N;ri1=M;
    qi = ri2/ri1;

    while(1){
        
        ri = ri2 - ri1*qi;
        si = si2 - si1*qi;
        ti = ti2 - ti1*qi;
        if(ri==0)   break;
        qi = ri1/ri;
        //printf("%d\t%d\t%d\t%d\n", si, ti, ri, qi);

        ri2 = ri1;
        ri1 = ri;
        si2 = si1;
        si1 = si;
        ti2 = ti1;
        ti1 = ti;
        
    }

    *s = si1;
    *t = ti1;
    //printf(" => gcd(%d), s(%d), t(%d)\n", ri1, si1, ti1);
    return ri1;
}


int main(void){
    int T;
    scanf("%d", &T);

    int N,M,x,y,gcd,s,t;
    long ret;
    for(int i=0;i<T;i++){
        scanf("%d %d %d %d", &N, &M, &x, &y);

        
        if(M>N){
            int temp = N;
            N = M;
            M = temp;
            temp = x;
            x = y;
            y = temp;
        }
        gcd = exEuclid(N,M,&s,&t);

        if((y-x)%gcd != 0){
            ret = -1;
        }else{
            ret = N;
            ret = ret*s*((y-x)/gcd) + x;
            while(ret <= 0){
                ret += (N*M)/gcd;
            }
        }

        printf("%ld\n", ret);
    }
    return 0;
}