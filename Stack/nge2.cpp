//LeetCode 503: Next Greater Element 2
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
 

// Constraints:

// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109

//-------------------------------------------------------------------------------------

// naive approach
// i = 0 to n-1
// j = i+1 to n-1
// if not found, j = 0 to i-1

// hypothetical doubling of array approach
// arr = 2 10 12 1 11
// 2 10 12 1 11 2 10 12 1 11
// n=5

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= i + n - 1; j++)
            {
                int index = j % n;
                if (nums[index] > nums[i])
                {
                    ans[i] = nums[index];
                    break;
                }
            }
        }
        return ans;
    }
};

// optimal solution
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        //hypothetically double the array
        for (int i=2*n-1; i>=0; i--){
           while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();
           }
           if (i<n){
            if (!st.empty()){
                ans[i] = st.top();
            }
           }
           st.push(nums[i%n]);
        }
        return ans;
    }
};
