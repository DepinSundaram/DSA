#include <iostream>
#include <bitset>

int count_bits(int n) {
    int total = 0;
    while (n) {
        n = n & (n-1);
        ++total;
    }

    return total;
}
int main(){
    
    // Given integer
    int N = 15;


    // Calling the function.
    cout << "Count of set bits in " << N<<" = "<<count_bits(N);
    return 0;
}