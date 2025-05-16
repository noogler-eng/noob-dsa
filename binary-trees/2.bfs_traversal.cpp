// BFS traversal

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

// time complexity o(N)
// space complexity o(N)
vector<int> bfs_traversal(Node* root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* node = q.front();
        ans.push_back(node->val);
        q.pop();
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }

    return ans;
}