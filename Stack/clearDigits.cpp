//LeetCode 3174 - Remove Digits

// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (char c : s){
            if (isdigit(c)){
                if (!result.empty()){
                    result.pop_back();
                }
            }
            else {
                result.push_back(c);
            }
        }
        return result;
    }
};