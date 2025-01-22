/**
 * LeetCode Question 1368 - Minimum Cost to Make at Least One Valid Path in a Grid
 *
 * You are given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. 
 * The sign of grid[i][j] can be:
 * - 1 which means go to the cell to the right (i, j + 1)
 * - 2 which means go to the cell to the left (i, j - 1)
 * - 3 which means go to the lower cell (i + 1, j)
 * - 4 which means go to the upper cell (i - 1, j)
 *
 * You start at the upper-left cell (0, 0) and you want to reach the bottom-right cell (m - 1, n - 1) with the minimum cost. 
 * You can change the direction of the sign at a cost of 1. 
 * Return the minimum cost to make at least one valid path in the grid.
 *
 * Example:
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]]
 * Output: 0
 * Explanation: You don't need to change any direction. 
 * 
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 100
 * - 1 <= grid[i][j] <= 4
 */

#include <vector>
#include <deque>
#include <utility>
#include <climits>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: right (1), left (2), down (3), up (4)
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Cost matrix to track the minimum cost to reach each cell
        std::vector<std::vector<int>> cost(m, std::vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        // Deque for 0-1 BFS
        std::deque<std::pair<int, int>> dq;
        dq.push_back({0, 0}); // Start at the top-left corner

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
    
            dq.pop_front();

            // Explore all four directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + directions[i].first;
                int newY = y + directions[i].second;

                // Check if the new cell is within bounds
                if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
                    // Determine the cost to move to the new cell
                    int direction = grid[x][y];
                    int newCost = cost[x][y] + (direction == i + 1 ? 0 : 1);

                    // Update cost and add the cell to the deque if needed
                    if (newCost < cost[newX][newY]) {
                        cost[newX][newY] = newCost;

                        // Push to the front if no direction change is needed (0 cost)
                        if (direction == i + 1) {
                            dq.push_front({newX, newY});
                        } else {
                            dq.push_back({newX, newY}); // Push to the back if cost is 1
                        }
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return cost[m - 1][n - 1];
    }
};

