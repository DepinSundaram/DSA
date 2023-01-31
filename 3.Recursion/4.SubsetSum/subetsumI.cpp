#include <iostream>
#include <vector>
using namespace std;

/*
Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.
in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.
in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

BF approadh : Use power set TC : 2^n * N

Recursion:
Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it.
 So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/

class Solution
{
    void FindSubsetSum(int idx, int size, int sum, vector<int>& arr, vector<int>& ans) {

        if (idx == size) {
            ans.push_back(sum);
            return;
        }

        // pick index
        FindSubsetSum(idx + 1, size, sum + arr[idx], arr, ans);

        // not pick idx element

        FindSubsetSum(idx + 1, size, sum, arr, ans);

    }
    public:
    vector<int> subsetSums(vector<int>& arr, int size) {
        vector<int> ans;
        FindSubsetSum(0, size, 0, arr, ans);
    }
};

int main() {
  vector < int > arr{3,1,2};
  Solution ob;
  vector < int > ans = ob.subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end());
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}