/**
 * LeetCode Question 2683: Neighboring Bitwise XOR
 * 
 * Given an integer array nums, find the maximum value of the bitwise XOR of any two neighboring elements in the array.
 * 
 * Example:
 * Input: nums = [1, 2, 3, 4]
 * Output: 7
 * Explanation: The maximum value of the bitwise XOR of any two neighboring elements is 7, which is the result of 3 XOR 4.
 * 
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * - 0 <= nums[i] <= 10^9
 */

/**
 * LOGIC
 * The logic behind solving this problem is to use the properties of XOR operation.
 * XOR of two same numbers is 0 and XOR of a number with 0 is the number itself.
 * 
 * To determine if a valid array exists, we need to check if the XOR of all elements in the derived array is 0.
 * If the XOR of all elements is 0, it means that the original array can be reconstructed such that the XOR of any two neighboring elements in the derived array is valid.
 * 
 * The function doesValidArrayExist takes a vector of integers (derived) as input and returns a boolean value.
 * It initializes a variable ans to 0 and iterates through the derived array, performing XOR operation on each element with ans.
 * If the final value of ans is 0, it returns true indicating that a valid array exists.
 * Otherwise, it returns false.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool doesValidArrayExist(vector<int>& derived){
        int ans = 0;
        for (int i=0; i<derived.size(); i++){
            ans = ans ^ derived[i];
        }
        if (ans == 0){
            return true;
        }
        else return false;
    }

};