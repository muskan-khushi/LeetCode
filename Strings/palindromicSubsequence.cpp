//LeetCode 1930. Unique Length-3 Palindromic Subsequences

// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
 

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")
 

// Constraints:

// 3 <= s.length <= 105
// s consists of only lowercase English letters.



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();

        // Unique characters in the string
        unordered_set<char> letters(s.begin(), s.end());
        int result = 0;

        // Iterate over each unique character
        for (char letter : letters)
        {
            int leftIndex = -1, rightIndex = -1;

            // Find the first and last occurrences of the character
            for (int i = 0; i < n; i++)
            {
                if (s[i] == letter)
                {
                    if (leftIndex == -1)
                        leftIndex = i;
                    rightIndex = i;
                }
            }

            // If the character appears at least twice
            if (leftIndex != -1 && rightIndex != -1 && rightIndex > leftIndex)
            {
                // Count unique characters between leftIndex and rightIndex
                unordered_set<char> st;
                for (int middle = leftIndex + 1; middle < rightIndex; middle++)
                {
                    st.insert(s[middle]);
                }

                // Add the number of unique characters to the result
                result += st.size();
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "aabca";
    cout << sol.countPalindromicSubsequence(s) << endl; // Output: 3 ("aba", "aca", "bcb")
    return 0;
}
