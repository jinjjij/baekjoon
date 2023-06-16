
typedef long long int lld;

typedef struct _BITARR{
    char* arr;
    lld size;
} BITARR;


BITARR* createBitarray(lld size){
    BITARR* bitarr = (BITARR*)malloc(sizeof(BITARR));

    bitarr->arr = (char*)calloc(size/8 + 1, sizeof(char));
    bitarr->size = size;

    return bitarr;
}


int getBit(BITARR* bitArr, lld idx){
    int charidx = idx/8;
    int charval = bitArr->arr[charidx];

    return ( (bitArr->arr[idx/8] & (1 << (idx%8) )) != 0 ) ;    
}


void putBit(BITARR* bitArr, lld idx, int value){
    if(value == 0){
        bitArr->arr[idx/8] &= ~(1 << (idx%8));
    }else{
        bitArr->arr[idx/8] |= 1 << (idx%8);
    }
}


int main(void){
    
    return 0;
}
