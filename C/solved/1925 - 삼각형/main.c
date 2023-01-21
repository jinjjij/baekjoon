#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERR 0.000000001

typedef struct vec2{
    int x;
    int y;
    double size2;
} VEC2;


double calcSize(VEC2 v){
    return sqrt(v.x*v.x+v.y*v.y);
}


VEC2 subvec2(VEC2 v1, VEC2 v2){
    VEC2 ret;
    ret.x = v1.x - v2.x;
    ret.y = v1.y - v2.y;

    return ret;
}


int dotProd(VEC2 v1, VEC2 v2){
    return v1.x*v2.x + v1.y*v2.y;
}


int isZero(double d){
    if(d < ERR && d > -ERR) return 1;
    else                    return 0;
}


int main(void){
    VEC2 dot[3];
    VEC2 vec[6];

    for(int i=0;i<3;i++){
        scanf("%d %d", &dot[i].x, &dot[i].y);
    }
    vec[0] = subvec2(dot[1], dot[0]);       //01
    vec[0].size2 = calcSize(vec[0]);
    vec[1] = subvec2(dot[2], dot[1]);       //12
    vec[1].size2 = calcSize(vec[1]);
    vec[2] = subvec2(dot[0], dot[2]);       //20
    vec[2].size2 = calcSize(vec[2]);

    vec[3] = subvec2(dot[0], dot[1]);       //10
    vec[4] = subvec2(dot[1], dot[2]);       //21
    vec[5] = subvec2(dot[2], dot[0]);       //02

    double dp[3];
    dp[0] = (double)dotProd(vec[0], vec[5]) / (vec[0].size2 * vec[2].size2);
    dp[1] = (double)dotProd(vec[1], vec[3]) / (vec[1].size2 * vec[0].size2);
    dp[2] = (double)dotProd(vec[2], vec[4]) / (vec[2].size2 * vec[1].size2);

    double mindp = dp[0];
    if(dp[1] < mindp)   mindp = dp[1];
    if(dp[2] < mindp)   mindp = dp[2];

    // 일직선 위
    if( isZero(dp[0]+1) || isZero(dp[1]+1) || isZero(dp[2]+1) ){
        printf("X");
        return 0;
    }
    int same01 = isZero(vec[0].size2 - vec[1].size2);
    int same12 = isZero(vec[1].size2 - vec[2].size2);
    int same20 = isZero(vec[2].size2 - vec[0].size2);

    // 세변길이 같음
    if( same01 && same12 && same20){
        printf("JungTriangle");
        return 0;
    }

    // 두변길이 같음
    if(same01 || same12 || same20){
        if(isZero(mindp)){      // 직각
            printf("Jikkak2Triangle");
        }else if(mindp < 0){    // 둔각
            printf("Dunkak2Triangle");
        }else{                  // 예각
            printf("Yeahkak2Triangle");
        }
        return 0;
    }

    // 세변길이 모두다름
    if(!same01 && !same12 && !same20){
        if(isZero(mindp)){      // 직각
            printf("JikkakTriangle");
        }else if(mindp < 0){    // 둔각
            printf("DunkakTriangle");
        }else{                  // 예각
            printf("YeahkakTriangle");
        }
        return 0;
    }


    return 0;
}