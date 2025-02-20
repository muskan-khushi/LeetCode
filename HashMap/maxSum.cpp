// LeetCode 2342: Max Sum of a Pair With Equal Sum of Digits
// Given an array of integers nums, find the maximum sum of a pair of numbers such that the sum of digits of both numbers is equal.
// If no such pair exists, return -1.


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int, int> digitSumMap;
            int maxSum = -1;
    
            for (int num : nums){
                int digitSum = 0, temp = num;
                while (temp) {  // Calculate sum of digits
                    digitSum += temp % 10;
                    temp /= 10;
                }
    
                if (digitSumMap.count(digitSum)) {
                    maxSum = max(maxSum, digitSumMap[digitSum] + num);  // Update max sum
                    digitSumMap[digitSum] = max(digitSumMap[digitSum], num);  // Keep max number
                } 
                else {
                    digitSumMap[digitSum] = num;
                }
            }
            return maxSum;
        }
    };