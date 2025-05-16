// Level Order Traversal
#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int val){
        this->val = val;
    }
};

// time complexity o(N)
// space complexity o(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while(!q.empty()){
            int size = q.size();
            height++;
            while(size > 0){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
        }

        return height;
    }
};


// we can also do this using recurssion
// time complexity o(N)
// space complexity o(H)
class Solution {
public:
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};