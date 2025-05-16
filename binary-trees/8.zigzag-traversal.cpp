// ZigZag Traversal

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
// space complexity o(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> row;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                row.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(count % 2 == 1) reverse(row.begin(), row.end());
            ans.push_back(row);
            count++;
        }
        return ans;        
    }
};