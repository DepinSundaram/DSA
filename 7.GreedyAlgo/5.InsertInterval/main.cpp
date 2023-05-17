#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > Insert(vector<vector<int>>& arr, vector<int>& newI)
{
    int n = arr.size();
    vector<vector<int> > ans;
    int i = 0;
    while (i < n && arr[i][1] < newI[0]) {
        ans.push_back(arr[i++]);
    }
    vector<int> mI = newI;

    while (i < n && arr[i][0] <= newI[1]) {
        mI[0] = min(arr[i][0], mI[0]);
        mI[1] = max(arr[i][1], mI[1]);
        i++;
    }
    ans.push_back(mI);

    while (i < n) {
        ans.push_back(arr[i++]);
    }

    return ans;
}


int main()
{
    vector<vector<int>>intervals;
    intervals.push_back({1,3});
    intervals.push_back({6,9});
    vector<int>newInterval;
    newInterval.push_back(2);
    newInterval.push_back(5);
    intervals = Insert(intervals,newInterval);

    for(int i=0;i<intervals.size();i++){
        cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<" ";
    }
}
