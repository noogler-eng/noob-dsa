// Traversal

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val){
        this->val = val;
    }
};

// inorder -> left, root, right
// pre -> root,left, right
// post -> left, right, root
void inorder_traversal(Node* root, vector<int> &ans){
    if(root == NULL) return;
    inorder_traversal(root->left, ans);
    ans.push_back(root->val);
    inorder_traversal(root->right, ans);
}

// first we move root, left, right
void preorder_traversal(Node* root, vector<int> &ans){
    if(root == NULL) return;
    ans.push_back(root->val);
    preorder_traversal(root->left, ans);
    preorder_traversal(root->right, ans);
}

// first we move left, right then root
void postorder_traversal(Node* root, vector<int> &ans){
    if(root == NULL) return;
    preorder_traversal(root->left, ans);
    preorder_traversal(root->right, ans);
    ans.push_back(root->val);
}