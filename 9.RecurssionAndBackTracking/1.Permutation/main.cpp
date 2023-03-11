#include <iostream>
#include <vector>

using namespace std;
class Solution
{
    /*
    Time Complexity:  N! x N

    Space Complexity:  O(N)
    */
    void recurPermute(vector<int>& ds, vector<vector<int> >& ans,
                    vector<int>& num, int freq[])
    {
        if (ds.size() == num.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i =0; i < num.size(); ++i) {
            if (!freq[i]) {
                freq[i] = 1;
                ds.push_back(num[i]);
                recurPermute(ds, ans, num, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        
    }
    public:
    vector < vector < int > >  permute(vector <int> nums) {
        vector<int> ds;
        vector<vector<int> > ans;

        int freq[nums.size()];
        for (int i = 0; i < nums.size(); ++i) {
            freq[i] = 0;
        }
        recurPermute(ds, ans, nums, freq);
        return ans;
    }

};

int main() {
  Solution obj;
  vector<int> v{1,2,3};
  vector < vector < int >> sum = obj.permute(v);
  cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}