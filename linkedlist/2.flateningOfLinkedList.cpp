// Flatening Of LinkedList
// Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:
// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head

// Each of these child linked lists is in sorted order and connected by a 'child' pointer. 
// Your task is to flatten this linked list such that all nodes appear in a single layer or 
// level in a 'sorted order'.


#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution {
  public:
    Node *flatten(Node *root) {
        Node* ans = new Node(-1);
        Node* dummy = ans;

        Node* temp = root;
        while(temp != NULL){
            Node* line = temp;
            while(line != NULL){
                ans -> next = line;
                line = line->bottom;
            }
        }
        
    }
};