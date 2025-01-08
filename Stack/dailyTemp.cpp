//LeetCode 739: Daily Temperatures
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> ans(n, 0);  // Initialize result with 0 (default for no warmer day)
      stack<int> st;          // Monotonic decreasing stack to store indices

      for (int i = n - 1; i >= 0; i--) {
          // Remove all indices with temperatures <= current temperature
          while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
              st.pop();
          }
          
          // If stack is not empty, calculate the number of days to wait
          if (!st.empty()) {
              ans[i] = st.top() - i;
          }
          
          // Push the current index onto the stack
          st.push(i);
      }
      return ans;
  }
};

