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


/*
1) Find break
1 2 3 6 5 4
 break Indx value is at 3
2) Swap with mim other availbale
    1 2 4 6 5 3

3) sort BreakIdx + 1 till end
1 2 4 3 5 6
*/
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {

        int size = nums.size();
        int breakIndx = -1;

        // Find BreakIndx
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                breakIndx = i;
                break;
            }
        }

        if (breakIndx == -1) {
            reverse(nums.begin(), nums.end());
        }
        // Find Next min
        for (int i = size - 1; i > breakIndx; --i) {
            if (nums[i] > nums[breakIndx]) {
                std::swap(nums[i], nums[breakIndx]);
            }
        }

        // Sort rest element
        std::sort(nums.begin() + breakIndx + 1, nums.end());

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