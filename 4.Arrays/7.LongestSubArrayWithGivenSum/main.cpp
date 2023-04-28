#include <iostream>
#include <vector>
#include <map>
using namespace std;


// BF

/*
Generate all possible sum array and check sum

Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/
int getLongestSubarrayBF(vector<int> arr, long long sum) {
    int size = arr.size();
    int len = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i ; j < size; j++) {
            long long s = 0;
            for (int z = i; z <= j; z++) {
                s += arr[z];
            }

            if (s == sum) {
                len = max(len , j - i + 1);
            }
        }
    }
    return len;
}


/*
Better Approach (Using Hashing): (Optimal solu for + - 0)
Store sum and idx at eacjh itr
then K - currenSum
check in map
if exists calculate len
else
update map

Time Complexity: O(N) or O(N*logN) depending on which map data structure
we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++
the time complexity will be O(N)(though in the worst case,
unordered_map takes O(N) to find an element and the 
time complexity becomes O(N2)) but if we are using a map data structure,
the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity: O(N) as we are using a map data structure.
*/

int getLongestSubarrayHash(vector<int> arr, long long K) {
    int size = arr.size();
    int len = 0;
    std::map<long long, int> mpp;
    long long sum = 0;
    for (int i = 0; i < size ; i++) {
        sum += arr[i];

        // If exist update len
        if (sum == K) {
            len = max(len, i + 1);
        }

        // cal remain
        long long rem = sum - K;

        // cal the len and update the len

        if (mpp.find(rem) != mpp.end()) {
            int clen = i - mpp[rem];
            len = max(len, clen);
        }

      //  mpp[sum] = i; works only for + non 0 number
      // Hence update only if sum doesn't exits

      if (mpp.find(sum) == mpp.end()) {
        mpp[sum] = i;
      }
    }
    return len;
}


/*
Optimal solution positive and 0
Two Pointer

Time Complexity: O(2*N), where N = size of the given array.
Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total.
 So, the time complexity will be O(2*N) instead of O(N2).
 https://www.youtube.com/watch?v=frf7qxiN2qU&t=2431s
*/


int getLongestSubarrayTwoPointer(vector<int>& arr, int k) {

    int n = arr.size();
    long long sum = arr[0];
    int maxLen = 0;
    int left = 0, right = 0;
    while (right < n) {

        while (left <=right && sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n) {
            sum += arr[right];
        }
    }

    return maxLen;
}
int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarrayTwoPointer(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}