#include <iostream>
#include <vector>

using namespace std;

void printAns(vector < vector < int > > & ans) {
   cout<<"The unique subsets are "<<endl;
   cout << "[\n";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
      cout << "]\n";
   }
   cout << " ]";
}
class Solution
{
    public:

    void findUniqueSubSet(vector <int> & nums, int idx,
                        vector<int>& ds, 
                        vector <vector<int> >& ans) {

        ans.push_back(ds);

        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i-1]) {
                continue;
            }
            ds.push_back(nums[i]);
            findUniqueSubSet(nums, i + 1, ds, ans);
            ds.pop_back();
        }
    }
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {

        int size = nums.size();
        vector <int> ds;
        vector <vector <int> > ans;

        sort(nums.begin(), nums.end());

        findUniqueSubSet(nums, 0, ds, ans);
        return ans;
    }

};




int main() {
   Solution obj;
   vector < int > nums = {1,2,2 };
   vector < vector < int > > ans = obj.subsetsWithDup(nums);
   printAns(ans);
   return 0;
}