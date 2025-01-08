//GFG - Next Greater Element for every given element in Array
// Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Examples
// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
// Input: arr[] = [6, 8, 0, 1, 3]
// Output: [8, -1, 1, 3, -1]
// Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

#include <bits/stdc++.h>
using namespace std;

//BruteForce Approach 
//TC -> O(n2) due to two nested loops
//SC -> O(1)
class Solution1 {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size(), -1);
        for (int i=0; i<arr.size(); i++){
            for (int j = i+1; j<arr.size(); j++){
                if (arr[i] < arr[j]){
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};


//Optimal Approach
//Using Stack
// TC -> O(n) and SC -> O(n)
class Solution2 {
  public:
  vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (!stk.empty()) {
            result[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return result;
 }
};

