// Root To Leaf Path

#include<iostream>
using namespace std;

// Given a Binary Tree, you need to find all 
// the possible paths from the root node to all 
// the leaf nodes of the binary tree.

// Note: The paths should be returned such that paths 
// from the left subtree of any node are listed first, 
// followed by paths from the right subtree.

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// time complexity o(N), where N is all nodes
// space complexity o(H), height of the tree
class Solution {
  public:
    void helper(Node* root, vector<vector<int>> &ans, vector<int> &path){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            path.push_back(root->data);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->data);
        helper(root->left, ans, path);
        helper(root->right, ans, path);
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> paths_ans;
        vector<int> path;
        helper(root, paths_ans, path);
        return paths_ans;
    }
};
