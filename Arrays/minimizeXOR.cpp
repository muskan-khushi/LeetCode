/**
 * LeetCode Question 2429: Minimize XOR
 * 
 * Given two positive integers num1 and num2, find the minimum XOR value 
 * that can be obtained by changing at most one bit in num1.
 * 
 * Example:
 * Input: num1 = 3, num2 = 5
 * Output: 1
 * Explanation: Changing the least significant bit of num1 from 1 to 0 
 * gives the minimum XOR value of 1.
 * 
 * Constraints:
 * - 1 <= num1, num2 <= 10^9
 * 
 * The function should return the minimum XOR value.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Step 1: Count the number of set bits in num2
        int setBits_num2 = __builtin_popcount(num2);
        
        // Step 2: Fill bits2 by prioritizing set bits of num1
        vector<int> bits1(32, 0);
        int pos = 0;
        while (num1) {
            if (num1 & 1) {
                bits1[pos]++;
            }
            pos++;
            num1 >>= 1;
        }
        
        int ans = 0;
        
        // Step 3: Use the most significant set bits of num1 first
        for (int i = 31; i >= 0 && setBits_num2 > 0; i--) {
            if (bits1[i]) {
                ans |= (1 << i);
                setBits_num2--;
            }
        }
        
        // Step 4: Fill remaining bits in the least significant positions
        for (int i = 0; i < 32 && setBits_num2 > 0; i++) {
            if (!(ans & (1 << i))) { // If the bit is not already set in ans
                ans |= (1 << i);
                setBits_num2--;
            }
        }
        
        return ans;
    }
};
