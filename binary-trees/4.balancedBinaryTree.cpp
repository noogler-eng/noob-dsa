// Balanced Binary Tree
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
// space complexity o(H)
class Solution {
public:
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        
        int heightOfLeft = helper(root->left);
        if(heightOfLeft == -1) return -1;
        
        int heightOfRight = helper(root->right);
        if(heightOfRight == -1) return -1;
        
        if(abs(heightOfLeft - heightOfRight) <= 1) return 1 + max(heightOfLeft, heightOfRight);
        else return -1;
    }

    bool isBalanced(TreeNode* root) {
        // when any tree can be balance only when left = right <= 1
        int val = helper(root);
        return val == -1 ? false: true;
    }
};