//LeetCode 1408: String Matching in an Array

// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

 

// Example 1:

// Input: words = ["mass","as","hero","superhero"]
// Output: ["as","hero"]
// Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.
// Example 2:

// Input: words = ["leetcode","et","code"]
// Output: ["et","code"]
// Explanation: "et", "code" are substring of "leetcode".
// Example 3:

// Input: words = ["blue","green","bu"]
// Output: []
// Explanation: No string of words is substring of another string.
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 30
// words[i] contains only lowercase English letters.
// All the strings of words are unique.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // Step 1: Sort the words by their lengths in ascending order.
        // Sorting ensures that shorter strings are checked first as potential substrings,
        // reducing unnecessary comparisons.
        // Sorting takes O(n * log(n)), where n is the number of words.
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // Result vector to store strings that are substrings of other strings
        vector<string> result;

        // Step 2: Use nested loops to compare each string with all longer strings.
        // Outer loop runs O(n) times.
        for (int i = 0; i < words.size(); ++i) { 
            // Inner loop runs O(n - i) times on average for each word.
            for (int j = i + 1; j < words.size(); ++j) { 
                // Checking if words[i] is a substring of words[j] using find().
                // The find() function takes O(k), where k is the length of words[j].
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]); // Add it to the result vector
                    break; // No need to check further for this word, as it is already a substring
                }
            }
        }

        // Step 3: Return the result vector containing all substrings.
        // The vector can contain the substrings in any order, as per the problem's requirements.
        return result;
    }
};

/*
 * Time Complexity (TC):
 * 1. Sorting: O(n * log(n)), where n is the number of words.
 * 2. Nested loops:
 *    - Outer loop runs O(n) times.
 *    - Inner loop runs O(n - i) times for each i.
 *    - Substring check (find) takes O(k) time, where k is the average string length.
 *    - Total for nested loops: O(n^2 * k), where k is the average length of the strings.
 * 3. Overall Time Complexity: O(n * log(n) + n^2 * k).

 * Space Complexity (SC):
 * 1. Sorting is in-place, so it requires O(1) extra space.
 * 2. Result vector stores at most O(n) strings, requiring O(n * k) space in the worst case,
 *    where k is the average string length.
 * 3. Overall Space Complexity: O(n * k).
 */
