// Boundary Traversal Of Binary Tree

#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// time complexity o(N)
// space complexity o(2N)
class Solution {
  public:
    void leftTraversal(Node* root, vector<int> &left){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;

        left.push_back(root->data);
        if(root->left) leftTraversal(root->left, left);
        else leftTraversal(root->right, left);
    }

    // here we are not getting the rightmost node
    void rightTraversal(Node* root, vector<int> &right){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        right.push_back(root->data);
        if(root->right) rightTraversal(root->right, right);
        else rightTraversal(root->left, right);
    }

    void bottomTraversal(Node* root, vector<int> &bottom){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) bottom.push_back(root->data);
        bottomTraversal(root->left, bottom);
        bottomTraversal(root->right, bottom);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> left, right;
        if(root == NULL) return left;
        
        if(root->left != NULL || root->right != NULL) left.push_back(root->data);
        
        // here we have to traverse the left
        leftTraversal(root->left, left);
        
        // bottom one
        bottomTraversal(root, left);

        // here we have to traverse the right
        rightTraversal(root->right, right);  
        reverse(right.begin(), right.end());
        for(auto i: right) left.push_back(i);
        return left;
    }
};