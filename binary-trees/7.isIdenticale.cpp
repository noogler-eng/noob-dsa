// Is Identicle Tree

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
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;

        return root1->val == root2->val && (helper(root1->left, root2->left)) && (helper(root1->right, root2->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};