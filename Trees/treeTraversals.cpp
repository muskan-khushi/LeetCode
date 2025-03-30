
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

void preOrder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

void postOrder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans(3);
    inOrder(root, ans[0]);
    preOrder(root, ans[1]);
    postOrder(root, ans[2]);

    return ans;
}