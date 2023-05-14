#include <iostream>
#include <vector>
using namespace std;

void SubSeq(vector<int>& arr, vector<int>& ds, int idx, int n) {
    if (idx >= n) {
        for (auto i : ds) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[idx]);
    SubSeq(arr, ds, idx + 1, n);
    ds.pop_back();
    SubSeq(arr, ds, idx + 1, n);
}

void printSubS(vector<int>& arr) {
    vector<int> ds;
    SubSeq(arr, ds, 0, arr.size());
}

int main()
{
    vector<int> arr {1,2,3};

    printSubS(arr);
}