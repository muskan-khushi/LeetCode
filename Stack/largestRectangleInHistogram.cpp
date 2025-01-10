
/**
 * LeetCode Question 84: Largest Rectangle in Histogram
 * 
 * Given an array of integers heights representing the histogram's bar height 
 * where the width of each bar is 1, return the area of the largest rectangle 
 * in the histogram.
 * 
 * Example 1:
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * 
 * Example 2:
 * Input: heights = [2,4]
 * Output: 4
 * 
 * Constraints:
 * - 1 <= heights.length <= 10^5
 * - 0 <= heights[i] <= 10^4
 */

#include <bits/stdc++.h>
using namespace std;

//Not the most optimal approach
class Solution1 {
public:
   vector<int> nextSmallerElement(vector<int>& arr, int n){
       vector<int> ans(n, n);
       stack<int> st;

       for (int i=n-1; i>=0; i--){
        while (!st.empty() && arr[st.top()]>= arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
       }
       return ans;
   }

   vector<int> prevSmallerElement(vector<int>& arr, int n){
       vector<int> ans(n, -1);
       stack<int> st;

       for (int i=0; i<=n-1; i++){
        while(!st.empty() && arr[st.top()]>= arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
       }
       return ans;
   }

   int largestRectangleArea(vector<int>& heights){
       int n = heights.size();
       if (n==0) return 0;
       vector<int> next(n);
       next = nextSmallerElement(heights, n);

       vector<int> prev(n);
       prev = prevSmallerElement(heights, n);

       int area = 0;

       for (int i=0; i<n; i++){
        int l = heights[i];
        int b = next[i] - prev[i] - 1;

        int newArea = l*b;
        area = max(area, newArea);
        
     }
     return area;
   }
};


//Optimsed Approach

// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/

