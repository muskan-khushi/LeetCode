/**
 * LeetCode 1400 - Construct K Palindrome Strings
 *
 * Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
 *
 * Example:
 * Input: s = "annabelle", k = 2
 * Output: true
 * Explanation: You can construct two palindromes using all characters in s.
 * One is "anna" and the other is "elble".
 *
 * Constraints:
 * 1. 1 <= s.length <= 10^5
 * 2. s consists of lowercase English letters.
 * 3. 1 <= k <= 10^5
 *
 * Logic:
 * 1. Count the frequency of each character in the string.
 * 2. Calculate the number of characters with odd frequencies.
 * 3. If the number of characters with odd frequencies is less than or equal to k, return true (since each odd frequency character can be the center of a palindrome).
 * 4. Otherwise, return false.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        vector<int> freq(26, 0);
        int countOdd = 0;
        for (int i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
        }
        for (int i=0; i<26; i++){
            if (freq[i]%2 != 0){
                countOdd++;
            }
        }
        if (countOdd <= k) return true;
        else return false;
    }
};