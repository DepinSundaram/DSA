#include <iostream>
#include <vector>
using namespace std;

// https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
/*
SC : O(N)
TC: O(2^n * n)
*/

void Subsequence(int n, int idx, vector<int>& ds, int arr[])
{
    if (idx >= n) {
        for (auto it : ds) {
            printf("%d ", it);
        }
        std::cout << std::endl;
        return;
    }
    // Picking
    ds.push_back(arr[idx]);
    Subsequence(n, idx + 1, ds, arr);
    // Not pick
    ds.pop_back();
    Subsequence(n, idx + 1, ds, arr);
}
int main()
{
    int n = 3;
    int arr[] = {3, 1, 2};

    vector<int> ds;

    Subsequence(n, 0, ds, arr);

}