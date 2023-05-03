#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

/*
Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.

Space Complexity: O(1).
*/
int trafBF(vector<int>& arr) {
    int res = 0;

    int n = arr.size();

    for (int i =0; i < n; i++) {
        int j =i;
        int leftMax = 0, rightMax = 0;
        while(j >=0) {
            leftMax = max(leftMax, arr[j]);
            j--;
        }

        j = i;

        while (j < n) {
            rightMax = max(rightMax, arr[j]);
            j++;
        }

        res += min(leftMax, rightMax) - arr[i];
    }

    return res;
}
/*
Output: The water that can be trapped is 6

Time Complexity: O(N) because we are using 2 pointer approach.

Space Complexity: O(1) because we are not using anything extra.
*/
int trap(vector<int> arr) {
    int l = 0;
    int r = arr.size() - 1;

    int leftMax = 0;
    int rightMax = 0;
    int res = 0;

    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= leftMax) {
                leftMax = arr[l];
            } else {
                res += leftMax - arr[l];
            }
            l++;
        } else {
            if (arr[r] >= rightMax) {
                rightMax = arr[r];
            } else {
                res += rightMax = arr[r];
            }
            r--;
        }
    }
    return res;
}



int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trafBF(arr) << endl;
}
