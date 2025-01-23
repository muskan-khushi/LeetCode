/**
 * LeetCode Question 1267: Count Servers that Communicate
 *
 * You are given a map of a server center, represented as a m * n integer matrix grid, 
 * where 1 means that on that cell there is a server and 0 means that it is no server. 
 * Two servers are said to communicate if they are on the same row or on the same column.
 * 
 * Return the number of servers that communicate with any other server.
 *
 * Example:
 * Input: grid = [[1,0],[0,1]]
 * Output: 0
 * Explanation: No servers can communicate with each other.
 *
 * Input: grid = [[1,0],[1,1]]
 * Output: 3
 * Explanation: All three servers can communicate with at least one other server.
 *
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m <= 250
 * - 1 <= n <= 250
 * - grid[i][j] == 0 or 1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    int countServers(vector<vector<int>>& grid){
        int count = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        for (int i=0; i<m; i++){
          for (int j=0; j<n; j++){
            if (grid[i][j] == 1 && (rowCount[i]>1 || colCount[j]>1)){
                count++;
            }
          }
        }

        return count;
    }
};