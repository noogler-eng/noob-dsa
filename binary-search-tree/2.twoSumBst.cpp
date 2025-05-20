// Two Sum BST

#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val){
        this->val = val;
    }
};

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
class binary_search_tree{
    binary_search_tree(){

    }
};

bool twoSum(Node* root, int target){



    return false;
} 