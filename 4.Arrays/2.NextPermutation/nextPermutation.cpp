/*
Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. 
So, the next permutation just after {1,3,2} is {2,1,3}.

next_permutation : find next lexicographically greater permutation

*/

#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {

        int size = nums.size();
        int j,k;
        for (j = size - 2; j > 0; --j) {
            if (nums[j] < nums[j+1]) {
                break;
            }
        }

        if (j == 0) {
            std::reverse(nums.begin(), nums.end());
        } else {
            for (k = size - 1; k > j ; k--) {
                if (nums[k] > nums[j]) {
                    break;
                }
            }
        }
        std::swap(nums[j], nums[k]);
        std::reverse(nums.begin() + j + 1, nums.end());

        for (auto num : nums) {
            std::cout << num;
        }
    }
};


int main()
{
    std::vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    Solution a;
    a.nextPermutation(num);
}