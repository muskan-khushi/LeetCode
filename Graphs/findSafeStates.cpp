/**
 * LeetCode Question 802: Find Eventual Safe States
 *
 * In a directed graph, we start at some node and every turn, walk along a directed edge of the graph. 
 * If we reach a node that is terminal (i.e., it has no outgoing edges), we stop.
 * 
 * We say that a node is a "safe" node if starting from that node, we must eventually walk to a terminal node. 
 * More specifically, there is a natural number k so that for any choice of where to walk, we must have stopped at a terminal node in less than k steps.
 * 
 * Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
 * 
 * The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. 
 * The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
 * 
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * 
 * Constraints:
 * - n == graph.length
 * - 1 <= n <= 10^4
 * - 0 <= graph[i].length <= n
 * - graph[i] is sorted in a strictly increasing order.
 * - The graph may contain self-loops.
 * - The number of edges in the graph will be in the range [1, 4 * 10^4].
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversedGraph(n);
        vector<int> inDegree(n, 0);

        // Step 1: Reverse the graph
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reversedGraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }

        // Step 2: Initialize queue with terminal nodes (in-degree 0 in reversed graph)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Perform Kahn's Algorithm to find all safe nodes
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reversedGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Sort the safe nodes and return
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
