
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:

// https://www.youtube.com/watch?v=EsgaVYo9McI

    // Use std::lowert bound
    // 1 2 3 7 5 4 8 9
    // store elements if lower_bound is end() 1 2 3 7 (element bigger or equal)
    // now in find lower bound of 5 which is itr 7 - replce itr with i (5)
    // 1 2 3 5
    // then same 1 2 3 4
    // finally 1 2 3 4 8 9
    // this approach wont quarantees subsq but the lenght of it.

    /*
    T : nlogn
    S : len(maxsub)
    
    */
    int optimizedLongestSub(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> res;

        for (const auto i : nums) {
            auto itr = std::lower_bound(res.begin(), res.end(), i);
            if (itr == res.end()) {
                res.push_back(i);
            } else {
                *itr = i;
            }
        }

        return res.size();
    }
    /*
    create array assign 1 considering maximum subseq len will be 1;

    now if num[j] < num[i], them update the subseq len by maxSubLen[j] + 1
    and take max store the max subsq leng

    Time : O(n*n)
    Spance : O(n);
    
    */

    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();

        vector<int> maxSubLen(size, 1);
        int res = 1;
        for (int i = 1; i < size; i++) {
            for (int j = i - 1; j >=0; --j) {
                if (nums[j] < nums[i]) {
                    maxSubLen[i] = max(maxSubLen[i], maxSubLen[j] + 1);
                    res = max(res, maxSubLen[i]);
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution a;
    cout << a.optimizedLongestSub(nums);

}