#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.

Space Complexity: O(N) to return the answer of the merged intervals.
*/
vector < vector < int > > merge(vector < vector < int > > & intervals)
{
    vector< vector<int> > res;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++) {
        if (res.empty() || intervals[i][0] > res.back()[1]) {
            vector<int> v = {
                intervals[i][0],
                 intervals[i][1]
            };
            res.push_back(v);
        } else {
            res.back()[1] = max(intervals[i][1], res.back()[1]);
            std::cout << res.back()[1] << std::endl;
        }
    }
      return res;

}
int main() {
  vector < vector < int > > arr;
  arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
  vector < vector < int > > ans = merge(arr);

  cout << "Merged Overlapping Intervals are " << endl;

  for (auto it: ans) {
    cout << it[0] << " " << it[1] << "\n";
    }
}