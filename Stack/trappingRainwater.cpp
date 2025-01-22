/**
 * LeetCode Question 42 - Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it can trap after raining.
 * 
 * Example:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped.
 * 
 * Constraints:
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
 */

#include <bits/stdc++.h>
using namespace std;

//Method 1 TC -> O(N) SC-> O(N)
class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> leftMax(n, 0);
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], heights[i-1]);
        }
        vector<int> rightMax(n, 0);
        for (int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], heights[i+1]);
        }
        int water = 0;
        for(int i=0; i<n; i++){
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight > heights[i]){
                water += minHeight - heights[i];
            }
        }
    return water;
    }
};

//Method 2 TC->O(N) SC->O(1)
int trap2(vector<int> height){
    
    int water = 0;
    int n = height.size();
    int leftMax = 0, rightMax = 0, maxHeight = height[0], index = 0;

    //Max height building
    for (int i=1; i<n; i++){
        if(maxHeight < height[i]){
            maxHeight = height[i];
            index = i;
        }
    }

    //Left Part
    for (int i=0; i<index; i++){
        if(leftMax>height[i]){
        water += leftMax-height[i];
        }
        else leftMax = height[i];
    }

    //Right Part
    for (int i=n-1; i>index; i--){
        if(rightMax>height[i]){
        water += rightMax-height[i];
        }
        else rightMax = height[i];
    }

    return water;
}