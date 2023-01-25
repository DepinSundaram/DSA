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

void SubsequenceSum(int n, int sum, int idx, int s, vector<int>& ds, int arr[])
{
    if (idx >= n) {
        if (s == sum) {
            for (auto it : ds) {
                printf("%d ", it);
            }
            std::cout << std::endl;
            return;
        }
        return;
    }
    // Picking
    ds.push_back(arr[idx]);
    s += arr[idx];
    SubsequenceSum(n, sum, idx + 1, s, ds, arr);
    // Not pick
    ds.pop_back();
    s -=arr[idx];
    SubsequenceSum(n, sum, idx + 1, s, ds, arr);
}

bool OneSubsequenceSum(int n, int sum, int idx, int s, vector<int>& ds, int arr[])
{
    if (idx >= n) {
        if (s == sum) {
            for (auto it : ds) {
                printf("%d ", it);
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }
    // Picking
    ds.push_back(arr[idx]);
    s += arr[idx];
    if (OneSubsequenceSum(n, sum, idx + 1, s, ds, arr) == true) return true;
    // Not pick
    ds.pop_back();
    s -=arr[idx];
    if (OneSubsequenceSum(n, sum, idx + 1, s, ds, arr) == true) return true;
    
    return false;
}

int CountSubsequenceSum(int n, int sum, int idx, int s, int arr[])
{
    if (s > sum) return 0;
    if (idx >= n) {
        if (s == sum) {
            return 1;
        }
        return 0;
    }
    // Picking
    s += arr[idx];
    int l = CountSubsequenceSum(n, sum, idx + 1, s, arr);
    // Not pick
    s -=arr[idx];
    int r = CountSubsequenceSum(n, sum, idx + 1, s, arr);
    return l + r;
}

int main()
{
    int n = 3;
    int arr[] = {2, 1, 2};

    vector<int> ds;
    int sum = 3;
    //Subsequence(n, 0, ds, arr);
    //SubsequenceSum(n, sum, 0, 0, ds, arr);
    int count = CountSubsequenceSum(n, sum, 0, 0, arr);
    std::cout << count <<std::endl;
}