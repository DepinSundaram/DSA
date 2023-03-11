#include <iostream>
#include <vector>

using namespace std;
class Solution
{
    void findCombinationSum(int idx, vector<int>& nums, int target, vector<int> ds,  vector < vector < int > >& ans) {
        if (idx == nums.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (nums[idx] <= target) {
            ds.push_back(nums[idx]);
            findCombinationSum(idx, nums, target - nums[idx], ds, ans);
            ds.pop_back();
        }

        findCombinationSum(idx + 1, nums, target, ds, ans);
    }

    void findCombinationUnique(int idx, vector<int>& nums, int target,vector < int >& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i< nums.size(); i++) {
            if (i !=idx && nums[i] == nums[i-1]) {
                //continue;
            }
            if (nums[i] > target) {
                break;
            }
            ds.push_back(nums[i]);
            findCombinationUnique(idx + 1, nums, target - nums[i], ds, ans);
            ds.pop_back();
        }
    }
    public:
    vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (const auto& num : candidates) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        vector < vector < int >> ans;
        vector < int > ds;
        findCombinationUnique(0, candidates, target, ds, ans);
        return ans;
    } 
    vector < vector < int > > combinationSum(vector<int>& v, int target) {

        vector < vector < int > > ans;
        vector<int> ds;

        findCombinationSum(0, v, target, ds, ans);
        return ans;
    }
};
int main() {
  Solution obj;
  vector < int > v {2,3,6,7};
  int target = 7;
/*
  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
*/


    vector<int> v2{10,1,2,7,6,1,5};
    vector < vector < int >> comb = obj.combinationSum2(v2, 8);
    cout << "[ \n";
    for (int i = 0; i < comb.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++) {
        cout << comb[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << " ]";
}