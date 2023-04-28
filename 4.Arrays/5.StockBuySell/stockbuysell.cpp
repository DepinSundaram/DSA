#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfir(vector<int>& arr) {
    int maxProf = 0;
    int n = arr.size();
    int minPrice = INT_MAX;
    for (int i = 0; i< n; i++) {
        minPrice = min(minPrice, arr[i]);
        maxProf = max (maxProf, arr[i] - minPrice);
    }

    return maxProf;
}

void stockBuySell(int price[], int n) {
    // code here
    int buy = 0;
    int sell = 0;
    int profitMade = 0;
    for (int i = 0; i < n - 1; i++) {
        if (price[i+1] > price[i]) {
            sell++;
            profitMade++;
        } else {
            if (buy < sell) {
                std::cout << "(" << buy << " " << sell << ") ";
            }
            buy = i + 1;
            sell = i + 1;
        }
    }

    if (buy < sell) {
        std::cout << "(" << buy << " " << sell << ") ";
    }
    if (profitMade == 0) {
        std::cout << "No Profit";
    }
    
    std::cout << std::endl;
}

int main() {
    //vector<int> arr = {7,1,5,3,6,4};
    //int maxPro = maxProfit(arr);
    int arr[] = {100, 180, 260, 310, 40, 535, 695} ;
    stockBuySell(arr, 7);
}