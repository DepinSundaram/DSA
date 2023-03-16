#include <iostream>
#include <vector>
using namespace std;

/*

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is possible.



Time Complexity: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
*/
class Solution
{
    FindSumSequence(int idx, vector<int>& v, int target, vector<int>& ds, vector<vector<int>>& result ) {
        if (idx == v.size()) {
            if (target == 0) {
                result.push_back(ds);
            }
        }

        if (v[idx] <= target) {
            ds.push_back(v[idx]);
            FindSumSequence(idx, v, target - v[idx], ds, result);
            ds.pop_back();
        }

    FindSumSequence(idx + 1, v, target, ds, result);

    }
public:
    vector <vector<int> > combinationSum(vector<int>& v, int target)
    {
        vector<int> ds;
        vector< vector<int> > result;
        FindSumSequence(idx, v, target, ds, result);
    }
};


int main() {
  Solution obj;
  vector < int > v {2,3,6,7};
  int target = 7;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}