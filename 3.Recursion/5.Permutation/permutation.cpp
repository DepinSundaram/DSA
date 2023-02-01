#include <iostream>
#include <vector>
using namespace std;


/*
Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.


Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

Explanation: Given an array, return all the possible permutations.

Example 2:

Input: arr = [0, 1]

Output:
[
  [0, 1],
  [1, 0]
]

Explanation: Given an array, return all the possible permutations.

*/
class Solution
{
  //Time Complexity:  N! x N

  //Space Complexity:  O(N)
    void Permulations(vector<int>& arr, int size, vector<vector<int> >& ans, vector<int>& visited, vector<int>& ds) {

        if (ds.size() == size) {
            ans.push_back(ds);
            return ;
        }

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                ds.push_back(arr[i]);
                visited[i] = 1;
                Permulations(arr, size, ans, visited, ds);
                visited[i] = 0;
                ds.pop_back();
            }
        }

    }
    public:
    vector < vector < int > > permute(vector<int>& candidates) {
        int size =  candidates.size();
        vector<vector<int> > ans;
        vector<int> arr(size, 0);
        vector<int> ds;
        Permulations(candidates, size, ans, arr, ds);

        return ans;
    }
};

int main() {
  Solution obj;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  vector < vector < int > > sum = obj.permute(v);
  cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}