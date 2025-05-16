// Diamaeter Of Binary Tree

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    int helper(TreeNode* root, int &diamaeter) {
        if(root == NULL) return 0;
        int leftHeight = helper(root->left, diamaeter);
        int rightHeight = helper(root->right, diamaeter);
        diamaeter = max(diamaeter, leftHeight + rightHeight);
        return 1 + max(rightHeight, leftHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diamaeter = 0;
        helper(root, diamaeter);
        return diamaeter;
    }
};
