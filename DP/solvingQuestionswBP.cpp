/**
 * //LeetCode 2140: Solving questions with BrainPower
 * You are given a 0-indexed 2D integer array `questions` where
 * questions[i] = [points_i, brainpower_i].
 *
 * The array describes the questions of an exam, where you have to process
 * the questions in order (i.e., starting from question 0) and make a decision
 * whether to solve or skip each question. Solving question i will earn you
 * points_i points but you will be forced to skip the next brainpower_i questions.
 * 
 * - For example, if you solve question i and brainpower_i = 2, then you will
 *   skip questions i + 1 and i + 2 and start solving from question i + 3.
 *
 * Return the maximum points you can earn for the exam.
 *
 * Constraints:
 * - 1 <= questions.length <= 10^5
 * - 0 <= points_i, brainpower_i < 10^5
 */
#include <bits/stdc++.h>
using namespace std;


 class Solution {
    public:
        int n; 
        long long solve(int i, vector<vector<int>>& q, vector<long long>& t) {
            if (i >= n) return 0;
    
            if (t[i] != -1) return t[i];
    
            long long taken = q[i][0] + solve(i + q[i][1] + 1, q, t);  // Fixed q[i][i] -> q[i][1]
            long long notTaken = solve(i + 1, q, t);
            
            return t[i] = max(taken, notTaken);
        }
    
        long long mostPoints(vector<vector<int>>& q) {
            n = q.size();  // Assign n correctly
            vector<long long> t(n, -1);  // Fixed vector type
            return solve(0, q, t);
        }
    };
