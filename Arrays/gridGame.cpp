/**
 * LeetCode Question 2017: Grid Game
 *
 * You are given a 2D array `grid` of size 2 x n representing a grid. 
 * You have to play a game with this grid. In each move, you can move to the right or down.
 * Initially, you are at the top-left corner (0, 0) and you want to reach the bottom-right corner (1, n-1).
 * 
 * The second player will always try to minimize your score by blocking your path.
 * Your goal is to maximize your score by collecting the maximum number of points.
 *
 * @param grid A 2D array of integers representing the grid.
 * @return The maximum score you can achieve.
 */

#include <bits/stdc++.h>
using namespace std;
#define long long

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);

        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];

        for (int i = 1; i < n; i++) {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }

        long long minSecondRobotScore = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long topRemaining = prefixTop[n - 1] - prefixTop[i];
            long long bottomRemaining = (i > 0) ? prefixBottom[i - 1] : 0;

            long long secondRobotScore = max(topRemaining, bottomRemaining);

            minSecondRobotScore = min(secondRobotScore, minSecondRobotScore);
        }
        return minSecondRobotScore;
    }
};