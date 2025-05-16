// Left View Of Binary Tree

#include<iostream>
using namespace std;

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

// time complexity o(N)
// space complexity o(N)*2
class Solution {
  public:
    void helper(Node* root, vector<int> &leftView, int level){
        if(root == NULL) return;
        // check here the leftview size if equals means currect level we have to push
        // for each level theremust be an single element
        // [level1, level2, level3 ..... leveln]
        if(leftView.size() == level){
            leftView.push_back(root->data);
        }
        
        helper(root->left, leftView, level+1);
        helper(root->right, leftView, level+1);
    }
    
    vector<int> leftView(Node *root) {
        vector<int> leftView;
        helper(root, leftView, 0);
        return leftView;
    }
};