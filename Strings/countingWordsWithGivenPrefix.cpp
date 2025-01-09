/**
 * LeetCode 2185: Counting Words With a Given Prefix
 *
 * You are given an array of strings words and a string pref.
 * A string is a prefix of another string if you can remove some characters from the end of the other string to make it equal to the first string.
 * Return the number of strings in words that contain pref as a prefix.
 *
 * Example 1:
 * Input: words = ["pay", "attention", "practice", "attend"], pref = "at"
 * Output: 2
 * Explanation: There are 2 strings that have "at" as a prefix: "attention" and "attend".
 *
 * Example 2:
 * Input: words = ["leetcode", "win", "loops", "success"], pref = "code"
 * Output: 0
 * Explanation: There are no strings that have "code" as a prefix.
 *
 * Constraints:
 * - 1 <= words.length <= 100
 * - 1 <= words[i].length, pref.length <= 100
 * - words[i] and pref consist of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int prefixCount(vector<string>& words, string prefix){
    int n = words.size();
    int m = prefix.size();
    int count = 0;

    for (int i=0; i<n; i++){
        if (words[i].substr(0,m) == prefix){
            count++;
        }
    }
    return count;
   }
};