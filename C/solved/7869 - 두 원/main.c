/*
https://www.acmicpc.net/problem/7869 - 두 원
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265


inline double min(double a, double b){
    return a>b?b:a;
}


double getAngle(double r1, double r2, double d){
    double ret;
    ret = r1*r1 + d*d - r2*r2;
    ret = ret / (2*r1*d);
    ret = 2 * acos(ret);

    return ret;
}


int main(void){
    double x1, y1, r1, x2, y2, r2, S;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

    double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    d = sqrt(d);

    if(d+r1 <= r2 || d+r2 <= r1){
        S = PI * min(r1,r2) * min(r1,r2);
    }else if(d > r1 + r2){
        S = 0;
    }else{
        double angle1, angle2;
        angle1 = getAngle(r1, r2, d);
        angle2 = getAngle(r2, r1, d);

        S =   (angle1 * r1 * r1)/2
            + (angle2 * r2 * r2)/2
            - (sin(angle1) * r1 * r1)/2
            - (sin(angle2) * r2 * r2)/2;
    }

    printf("%.3lf", S);

    return 0;
}