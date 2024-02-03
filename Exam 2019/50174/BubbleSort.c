#include <stdint.h>
void BubbleSort(uint64_t input, uint64_t output[63]) {
    for(uint64_t i=63; i>0; --i) {
        for(uint64_t j=63; j>0; --j) {
            if(((input>>j)&1)==1 && ((input>>(j-1))&1)==0) {
                input ^= ((1LL)<<j);
                input ^= ((1LL)<<(j-1));
            }
        }
        output[64-i-1] = input;
    }
}