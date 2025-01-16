/**
 * LeetCode Question 2425: Bitwise XOR of All Pairings
 * 
 * Given two arrays nums1 and nums2 of length n and m respectively, 
 * return the bitwise XOR of all pairings of the elements in nums1 and nums2 
 * (i.e., nums1[i] XOR nums2[j] for all 0 <= i < n and 0 <= j < m).
 * 
 * Example:
 * Input: nums1 = [1,2,3], nums2 = [6,5]
 * Output: 0
 * Explanation: All pairings are (1,6), (1,5), (2,6), (2,5), (3,6), (3,5)
 * The XOR of all pairings is 0.
 * 
 * Constraints:
 * - 1 <= nums1.length, nums2.length <= 10^5
 * - 0 <= nums1[i], nums2[j] <= 10^9
 */

#include <bits/stdc++.h>
using namespace std;

//Bruteforce Approach
class Solution1 {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int ans = 0;
        int x;

        for (int i=0; i<nums1.size(); i++){
            for (int j=0; j<nums2.size(); j++){
                x = nums1[i]^nums2[j];
                nums3.push_back(x);
            }
        }

        for (int i=0; i<nums3.size(); i++){
            ans = ans^nums3[i];
        }

        return ans;
    }
};

//Optimal Solution

/* 
 * Logic:
 * - Calculate the XOR of all elements in nums1 and store it in xor1.
 * - Calculate the XOR of all elements in nums2 and store it in xor2.
 * - Initialize the result variable ans to 0.
 * - If the size of nums2 is odd, XOR the result with xor1.
 * - If the size of nums1 is odd, XOR the result with xor2.
 * - Return the result.
 * 
 * Explanation:
 * - If the size of nums2 is odd, each element in nums1 will be XORed an odd number of times,
 *   which means the XOR of all elements in nums1 will affect the final result.
 * - Similarly, if the size of nums1 is odd, each element in nums2 will be XORed an odd number of times,
 *   which means the XOR of all elements in nums2 will affect the final result.
 * - If both sizes are even, each element will be XORed an even number of times, resulting in 0.
 */


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int xor2 = 0;
        int ans = 0;

        for (int i=0; i<nums1.size(); i++){
            xor1 = xor1^nums1[i];
        }

        for (int i=0; i<nums2.size(); i++){
            xor2 = xor2^nums2[i];
        }

        if (nums2.size()%2!=0){
            ans = ans^xor1;
        }

        if (nums1.size()%2!=0){
            ans = ans^xor2;
        }

        return ans;
    }
};

