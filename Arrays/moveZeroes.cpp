/*
LeetCode 283: Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Constraints:
- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1
*/

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int j = 0;
        for (int i=0; i<n; i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for (int i=j; i<n; i++){
            nums[i] = 0;
        }
        
    }
};