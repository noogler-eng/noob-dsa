// Two Sum BST

#include<iostream>
using namespace std;

// brute force approach
// traversal of the whole tree
// apply two sum on it on vector
// time complexity o(N) + o(N)
// space complexity o(N) + o(H)


// optimized version
// by making the class of the next
// next always gives us sorted elements ...
// we can aslo do before same as ...
// time complexity o(N)
// space complexity o(H) * 2

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ReverseInorderBST{
    public:
    stack<TreeNode*> st;
    ReverseInorderBST(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* top = st.top();
        st.pop();
        pushAll(top->left);
        return top->val;
    }   

    void pushAll(TreeNode* root){
        if(root == NULL) return;
        TreeNode* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->right;
        }
    }
};

class InorderBST{
    public:
    stack<TreeNode*> st;
    InorderBST(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* top = st.top();
        st.pop();
        pushAll(top->right);
        return top->val;
    }   

    void pushAll(TreeNode* root){
        if(root == NULL) return;
        TreeNode* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        if(root == NULL) return false;
        InorderBST left(root);
        ReverseInorderBST right(root);

        int i = left.next();
        int j = right.next();
        while(i < j){
            if(i + j == target) return true;
            else if(i + j < target) i = left.next();
            else j = right.next();
        }

        return false;
    }
};

// we can also merge both the classes into single one by
// mentioning the reverse (true, false)
// if reverse = true (then this class is reverseOrder...)
// if reverse = false (then this class is simpleOrder...)