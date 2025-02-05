// LeetCode Question 1790: Check if One String Swap Can Make Strings Equal
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffIndices;
        for (int i = 0; i < s1.length(); ++i)
            if (s1[i] != s2[i])
                diffIndices.push_back(i);
        return diffIndices.empty() ||
               (diffIndices.size() == 2 &&
                s1[diffIndices[0]] == s2[diffIndices[1]] &&
                s1[diffIndices[1]] == s2[diffIndices[0]]);
    }
};

