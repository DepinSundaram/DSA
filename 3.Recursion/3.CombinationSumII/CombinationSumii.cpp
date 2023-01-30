#include <iostream>
#include <vector>
using namespace std;

/*

Check BF approach https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target. 
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.
 
Example 2:

Input: candidates = [2,5,2,1,2], target = 5

Output: [[1,2,2],[5]]

Explanation: These are the unique combinations whose sum is equal to target.


Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n).
we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
*/

void FindUniqueCombination(int idx, vector<int>& arr, int target, vector<vector<int> >& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds);
    }
    for (int i = idx; i < arr.size(); i++) {
        if (i > idx && arr[i] == arr[i - 1]) continue;
        if (arr[i] > target) break;
        ds.push_back(arr[i]);
        FindUniqueCombination(idx+1, arr, target - arr[i], ans, ds);
        ds.pop_back();
    }
}
vector<vector<int> > combinationSum2(vector<int>& v, int target) {

    sort(v.begin(), v.end());
    vector<vector<int> > ans;
    vector<int> ds;

    FindUniqueCombination(0, v, target, ans, ds);

    return ans;
}


int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int > > comb = combinationSum2(v, 8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}
