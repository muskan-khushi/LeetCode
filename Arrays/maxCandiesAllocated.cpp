/**
 * LeetCode 2226 - Maximum Candies Allocated to K Children
 * 
 * You are given a 0-indexed integer array candies. Each element in the array represents a pile of candies.
 * You can divide each pile into any number of sub-piles, but you cannot merge two piles together.
 * You are also given an integer k, representing the number of children.
 * 
 * Return the maximum number of candies each child can get.
 * 
 * Example:
 * Input: candies = [5, 8, 6], k = 3
 * Output: 5
 * Explanation: We can divide the candies as follows:
 * - 5 -> 5
 * - 8 -> 5 + 3
 * - 6 -> 5 + 1
 * Each child gets 5 candies.
 */


 
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool canDistribute(vector<int>&candies, int k, int mid){
        int n = candies.size();

        long long count = 0;
        for (int i=0; i<n; i++){
            count += candies[i]/mid;
            
            if (count >= k) return true;
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k){
        int n = candies.size();

        int maxC = 0;
        int total = 0;
        for (int i=0; i<n; i++){
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if (total < k) return 0;

        int l = 1;
        int r = maxC;
        int result = 0;

        while (l <= r){
            int mid = l + (r-1)/2;

            if (canDistribute(candies, mid, k)){
                result = mid;
                l=mid+1;
            }
            else {
                r = mid - 1;
            }
        }



        // //bruteforce try for max till 1
        // for (int c = maxC; c>=1; c--){
        //     long long count = 0;

        //     for (int i=0; i<candies.size(); i++){
        //         count += candies[i]/c;
        //     }

        //     if (count >= k){
        //         return c;
        //     }
        // }
        // return 0;
    }
};