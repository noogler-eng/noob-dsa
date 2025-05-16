// Vertical Order Traversal

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

// here order also matter so that why we need 2d matrix in map
// map<int, map<int, multiset<int>>>
// multiset makes them in sorted order and unique values

// if not in sorted order then this wil work
// otherwise we have to use map<int, map<int, multiset<int>>>
// time complexity o(N)
// space complexity o(2N)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;

        if(root == NULL) return ans;
        q.push({root, 0});

        int mini = INT_MAX;
        int maxi = INT_MIN;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int vi = q.front().second;
            q.pop();
            m[vi].push_back(node->val);
            mini = min(mini, vi);
            maxi = max(maxi, vi);

            if(node->left) q.push({node->left, vi-1});
            if(node->right) q.push({node->right, vi+1});
        }

        for(int i=mini; i<=maxi; i++){
            if(m.find(i) != m.end()){
                ans.push_back(m[i]);
            }
        }

        return ans;
    }
};