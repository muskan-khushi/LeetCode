/**
 * @file
 * @brief Solution to LeetCode Question 2873
 *
 * LeetCode Question 2873: Maximum Value of an Ordered Triplet
 *
 * Given an integer array `nums`, find the maximum value of an ordered triplet `(nums[i], nums[j], nums[k])`
 * such that `0 <= i < j < k < nums.length` and `nums[i] < nums[j] < nums[k]`. If no such triplet exists, return 0.
 *
 * Constraints:
 * - 3 <= nums.length <= 10^5
 * - 1 <= nums[i] <= 10^6
 *
 */

 #include <bits/stdc++.h>
 using namespace std;

 class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxi = 0;
            int n = nums.size();
            for (int i =0; i<n; i++){
                for (int j=i+1; j<n; j++){
                    for (int k=j+1; k<n; k++){
                        long long res =(long long) (nums[i] - nums[j]) * nums[k];
                        if(maxi < res){
                           maxi = res;
                        }
                    }
                }
            }
            return maxi;
        }
    };