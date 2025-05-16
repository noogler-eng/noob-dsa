// Copy List With Random Pointer

// The linked list is represented in the input/output as a list of n nodes. 
// Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
// or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// time complexity o(3*N)
// space complexity o(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        // first we will insert duplicates node in between each and every node
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;
        // keep checking here this is mistaken point
        while(temp != NULL){
            if (temp->random) temp->next->random = temp->random->next;
            else temp->next->random = NULL;
            temp = temp->next->next;
        }

        temp = head;
        Node* clone = new Node(-1);
        Node* ans = clone;
        while(temp != NULL){
            clone->next = temp->next;
            clone = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return ans->next;
    }
};