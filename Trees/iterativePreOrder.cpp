#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
           
            vector<int> ans;
             if (!root) return ans;
            stack<TreeNode*> s1;
            s1.push(root);
    
            while (!s1.empty()){
                TreeNode* temp = s1.top();
                s1.pop();
                ans.push_back(temp->val);
    
                if(temp->right) s1.push(temp->right);
                if(temp->left) s1.push(temp->left);
            }
            return ans;
        }
    };