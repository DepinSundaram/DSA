#include <iostream>
#include <bitset>
using namespace std;

void PrintNibble(int n) {

    std::cout << n << "-" << bitset<8>(n) << endl;

    auto leftMost  = (n & 0xF0)/16;
    std::cout << bitset<4>(leftMost) << endl;

    auto rightMost  = n & 0x0F;
    std::cout << bitset<4>(rightMost) << endl;

}

int main() {
    int n = 0xAB;

    PrintNibble(n);
}