// LeetCode 448: Find All Numbers Disappeared in an Array
// Given an array nums of n integers where nums[i] is in the range [1, n], 
// return an array of all the integers in the range [1, n] that do not appear in nums.
//
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
//
// Example 2:
// Input: nums = [1,1]
// Output: [2]
//
// Constraints:
// - n == nums.length
// - 1 <= n <= 10^5
// - 1 <= nums[i] <= n
//
// Follow up: Could you do it without extra space and in O(n) runtime? 
// You may assume the returned list does not count as extra space.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> freq(n, 0);
        for (int i=0; i<n; i++){
            freq[nums[i]-1]++;
        }
        for(int i=0; i<n; i++){
            if (freq[i]==0) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};