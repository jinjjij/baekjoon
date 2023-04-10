void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort3(int* a, int* b, int* c){
    if(*b<*c)     swap(b, c);
    if(*a<*b)     swap(a, b);
    if(*b<*c)     swap(b, c);
}
