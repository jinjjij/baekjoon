#include <stdio.h>


// N>M
// return gcd
int exEuclid(int N, int M, int* s, int* t){
    int si,si1,si2,ti,ti1,ti2,ri,ri1,ri2,qi;
    si1=0;si2=1;ti1=1;ti2=0;ri2=N;ri1=M;

    int i=0;
    while(1){
        qi = ri2/ri1;
        ri = ri2 - ri1*qi;
        si = si2 - si1*qi;
        ti = ti2 - ti1*qi;

        if(ri==0)   break;

        ri1 = ri;
        ri2 = ri1;
        si1 = si;
        si2 = si1;
        ti1 = ti;
        ti2 = ti1;

        i++;
    }

    *s = si1;
    *t = ti1;
    return ri1;
}


typedef long long int lld;

// return gcd
lld Euclid(lld N, lld M){
    if(N<1 || M<1){
        return -1;
    }

    if(N==1 || M == 1){
        return 1;
    }

    if(N<M){
        int tmp = M;
        M = N;
        N = tmp;
    }

    if(N%M == 0){
        return M;
    }else{
        return Euclid(M, N%M);
    }
}


// needs Euclid()
lld lcm(lld N, lld M){
    lld gcd = Euclid(N,M);

    lld tmp = N/gcd;
    return tmp*M;
}