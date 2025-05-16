// Max Path Sum

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
    int helper(TreeNode* root, int &sum){
        if(root == NULL) return 0;
        
        int leftPathSum = helper(root->left, sum);
        int rightPathSum = helper(root->right, sum);

        // why will i include the negative side in path sum ..
        leftPathSum = leftPathSum > 0 ? leftPathSum: 0;
        rightPathSum = rightPathSum > 0 ? rightPathSum: 0;

        int path = leftPathSum + rightPathSum + root->val;
        sum = max(sum, path);
        
        return max(leftPathSum, rightPathSum) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
};