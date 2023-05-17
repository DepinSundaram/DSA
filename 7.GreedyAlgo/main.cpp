#include <iostream>
#include <vector>
using namespace std;

/*
BF :

Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. 
Now, after that, we are using 2 loops i and j. But while using loop i, 
we skip all the intervals that are merged with loop j. 
So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.

Space Complexity: O(N), as we are using an answer list to store the merged intervals. 
Except for the answer array, we are not using any extra space.

1) sort
2) take start and end
3) read after 4; skip if end already within last calculated end interval
4) iterate i + 1 -> n 
compare  current start[i][0] with end (calculated at 2)
if so max of end or current ele end arr[j][1]
*/
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr)
{
    std::sort(arr.begin(), arr.end());
    int start = 0, end = 0;
    vector<vector<int> > ans;
    for (int i = 0; i < arr.size(); i++) {
        start = arr[i][0];
        end = arr[i][1];
        if (!ans.empty() && ans.back()[1] >= end) {
            continue;
        }
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]); 
            } else 
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

/*
Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. 
Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).

Space Complexity: O(N), as we are using an answer list to store the merged intervals. 
Except for the answer array, we are not using any extra space.


*/
vector<vector<int>> mergeOverlappingIntervalsOptimized(vector<vector<int>>& arr)
{
    std::sort(arr.begin(), arr.end());
    vector<vector<int> > ans;
    for (int i = 0; i < arr.size(); i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervalsOptimized(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}