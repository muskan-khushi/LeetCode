/**
 * LeetCode Question 1765 - Map of Highest Peak
 *
 * You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
 * - If isWater[i][j] == 0, cell (i, j) is a land cell.
 * - If isWater[i][j] == 1, cell (i, j) is a water cell.
 *
 * You must assign each cell a height in a way that follows these rules:
 * - The height of each cell must be non-negative.
 * - If the cell is a water cell, its height must be 0.
 * - Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
 *
 * Find an assignment of heights such that the maximum height in the matrix is maximized.
 *
 * Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Add all water cells to the queue and set their height to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for BFS traversal
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS traversal
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            int x = cell.first;
            int y = cell.second;
            q.pop();

            for (pair<int, int> direction : directions) {
                int dx = direction.first;
                int dy = direction.second;

                int nx = x + dx;
                int ny = y + dy;

                // Check if the cell is valid and unvisited
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1; // Update height
                    q.push({nx, ny});                 // Add to queue
                }
            }
        }

        return height;
    }
};
