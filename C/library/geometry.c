#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define A 0.000000001

typedef struct dot{
    double x;
    double y;
} DOT;


DOT* createDot(double x, double y){
    DOT* dot = (DOT*)malloc(sizeof(DOT));
    dot->x = x;
    dot->y = y;
    return dot;
}


DOT* destroyDot(DOT* dot){
    if(dot!=NULL)   free(dot);
}


typedef struct line{
    DOT* dot1;
    DOT* dot2;
    double length;
} LINE;


double getLength(DOT* dot1, DOT* dot2){
    int x1 = dot1->x;
    int x2 = dot2->x;
    int y1 = dot1->y;
    int y2 = dot2->y;
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}


LINE* createLine(DOT* dot1, DOT* dot2){
    LINE* line = (LINE*)malloc(sizeof(LINE));
    line->dot1 = dot1;
    line->dot2 = dot2;
    line->length = getLength(dot1, dot2);

    return line;
}


void destroyLine(LINE* line){
    if(line==NULL)  return;
    destroyDot(line->dot1);
    destroyDot(line->dot2);
    free(line);
}


int isOnSameLine(DOT* dot1, DOT* dot2, DOT* dot3){
    double checksum = (dot1->x - dot2->x)*(dot2->y - dot3->y) - (dot1->y - dot2->y)*(dot2->x - dot3->x);
    if(checksum < A && checksum > -A){
        return 1;
    }else{
        return 0;
    }
}