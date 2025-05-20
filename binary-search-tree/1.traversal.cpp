// Binary search tree Traversal
// when we place elememt in binary search tree always move from root

#include<ostream>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int value){
        this->val = value;
    }
};

// brute force approach
// push all the lement in array then sort
// time complexity o(NlogN) + O(N)
// space complexity o(N)

// traversal of the binary search will be sorted
// optimised way
// left, root, right ....
// it is like Left, root, right (Inroder Traversal)
void helper(Node* root, vector<int> &ans){
    if(root == NULL) return;
    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}

vector<int> traversal_of_binary_search_tree(Node* root){
    vector<int> ans;
    helper(root, ans);
    return ans;
}


// important -----------
// we want to traverse level wise order
// first we have to trave the left then move to the right
// time complexity o(1) (average)
// space complexity O(H)
void helper(Node* root, vector<int> &ans, stack<Node*> &st){
    if(root == NULL) return;
    
    st.push(root);
    helper(root->left, ans, st);
    
    Node* top = st.top();
    st.pop();
    ans.push_back(top->val);
    
    helper(top->right, ans, st);
}

vector<int> traversal_of_binary_search_tree(Node* root){
    vector<int> ans;
    stack<Node*> st;
    helper(root, ans, st);
    return ans;
}


// BST iterator
// this is important concept
// time complexity o(1)
// space complexity o(H)
class BST{
    public:
    // First In Last out
    stack<Node*> st;
    BST(Node* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        Node* top = st.top();
        st.pop();
        pushAll(top->right);
        return top->val;
    }   

    void pushAll(Node* root){
        if(root == NULL) return;
        Node* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
    }
};
