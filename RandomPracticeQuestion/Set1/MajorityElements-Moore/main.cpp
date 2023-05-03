#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& arr) {

    int n = arr.size();
    int count = 0;
    int el = -1;

    for (auto ar : arr) {
        if (count == 0) {
            el = ar;
            count++;
        } else if (el == ar) {
            count++;
        } else {
            count--;
        }
    }

    return el;
}

int TwoMajorityElement(vector<int>& arr) {


    int n = arr.size();
    int count1 = 0;
    int count2 = 0;
    int e1 = 0;
    int e2 = 0;

    for (auto ar : arr) {
        if (count1 == 0) {
            e1 = ar;
            count1++;
        } else if (count2 == 0) {
            e2 = ar;
            count2++;
        } else if(ar == e1) {
            count1++;
        } else if (ar == e2) {
            count2++;
        }else {
            count1--;
            count2--;
        }
    }

    std::cout << e1 << "-" << e2;
    return 1;
}

int main() {
    vector<int> arr = {2, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3,3};
    int ans = TwoMajorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;

}