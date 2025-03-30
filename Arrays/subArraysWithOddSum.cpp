/**
 * LeetCode Question 1524: Number of Sub-arrays With Odd Sum
 *
 * Given an array of integers arr, return the number of sub-arrays with an odd sum.
 * Since the answer can be very large, return it modulo 10^9 + 7.
 *
 * Example 1:
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All sub-arrays are [1], [1,3], [3], [3,5], [5] with sums 1, 4, 3, 8, 5 respectively.
 * All sub-arrays with odd sum are [1], [1,3], [3], [5] so the answer is 4.
 *
 * Example 2:
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All sub-arrays are [2], [2,4], [4], [4,6], [6] with sums 2, 6, 4, 10, 6 respectively.
 * All sub-arrays with odd sum are [] so the answer is 0.
 *
 * Example 3:
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
 *
 * Constraints:
 * - 1 <= arr.length <= 10^5
 * - 1 <= arr[i] <= 100
 */

 #include <bits/stdc++.h>
 using namespace std;

 class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            //even - odd = odd
            //odd - even = odd
            long ans = 0;
    
            int even = 0;
            int odd = 0;
            int sum = 0;
    
            for (int val : arr){
                sum += val;
    
                if (sum % 2 ==0){
                    ans += odd;
                    even++;
                }
    
                else {
                    ans += 1;
                    ans += even;
                    odd++;
                }
            }
        return ans%(1000000007);
        }
    };