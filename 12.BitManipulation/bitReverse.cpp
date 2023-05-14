#include <iostream>
#include <bitset>
#include <cmath>


bool isBitSet(int k, unsigned int A) {
    // checks bit
    if ( ((1 << k) & A) != 0) {
        return true;
    }
    return false;
}


unsigned int FlipEachBit(unsigned int A) {
     
     int x = log2(A) + 1;

     for (int i = 0; i < x; i++) {
        A  = A ^ (1 << i);
     }
     return A;
}

int main()
{
    unsigned int A = 2, res = 0;

    for (int i = 0; i < 32; i++) {
        if (isBitSet(i, A)) {
            // set bits
            res = 1 << (31 - i) | res;
        }
    }
    A = 2;
    std::cout << FlipEachBit(A);
}