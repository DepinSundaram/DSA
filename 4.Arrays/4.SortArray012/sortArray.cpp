#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Input: nums = [0]

Time Complexity: O(N)

Space Complexity: O(1)


*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l =0;
        int mid = 0;
        int h = nums.size() - 1;

        while (mid <= h) {
            switch(nums[mid]) {
                case 0:
                    swap(nums[l++], nums[mid++]); 
                    break; 
                case 1:
                    mid++;
                    break; 
                case 2:
                    swap(nums[mid], nums[h--]); 
                    break; 
            }
        }
    }
};

int main()
{
    vector<int> num {2,0,2,1,1,0};
    Solution a;
    a.sortColors(nums);
}