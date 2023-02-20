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

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}