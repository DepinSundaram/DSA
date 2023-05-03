#include <iostream>
#include <string>
#include <bitset>
std::string FindBin(int num, std::string& res) {
    if (num == 0) {
        return res;
    }

    res = res + std::to_string(num % 2 ) + FindBin(num/2, res);
    return res;
}

int main()
{
    int num = 15;

    std::string res{};
    FindBin(num, res);
    std::reverse(res.begin(), res.end());

    std::bitset<8> b(res);
    std::cout << b.to_ulong();

}