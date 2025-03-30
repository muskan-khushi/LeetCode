//GFG -> Given an integer i. Print the maximum number of nodes on level i of a binary tree.

// Example 1:
// Input: 5
// Output: 16
// Example 2:
// Input: 1
// Output: 1

#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

int maxNode(int i){
    return 1<<(i-1);
}