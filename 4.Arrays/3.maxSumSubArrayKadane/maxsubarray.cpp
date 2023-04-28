#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> subArray;
    int maxSubArray(vector<int>& nums) {
        int msf= INT_MIN;
        int localMax = 0;
        int size = nums.size();
        int s =0;
        if (size == 1)
            return nums[0];
        
        for (int i = 0; i < size ; ++i) {
            localMax += nums[i];
            if (localMax > msf) {
                subArray.clear();
                msf = localMax;
                subArray.push_back(s);
                subArray.push_back(i);
            }

            if (localMax < 0) {
                localMax = 0;
                s = i + 1;
            }
        }

        return msf;
    }


    long long maxSubarraySum(int arr[], int n) {
        
    }
};


int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution a;
    std::cout << a.maxSubArray(nums) << endl;
    for (auto a: a.subArray)
    {
        std::cout << a;
    }
    return 0;
}