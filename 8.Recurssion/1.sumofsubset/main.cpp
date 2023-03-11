#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    /*
    Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
    */
    void subsetSumHelper(int idx, vector<int>& arr, vector<int>& res, int sum, int n) {
        if (idx == n) {
            res.push_back(sum);
            return;
        }

        subsetSumHelper(idx + 1, arr, res, sum + arr[idx], n);
        subsetSumHelper(idx + 1 , arr, res, sum, n);

    }
    vector < int > subsetSums(vector<int> arr, int n)
    {
        vector<int> res;
        subsetSumHelper(0, arr, res, 0, n);
        return res;
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
