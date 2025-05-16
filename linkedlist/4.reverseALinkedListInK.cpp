// Reverse A LinkedList IN Order Of K

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// it includes reversing of the linkedlist
// it includes how to cnt k nodes then merge it with prev one and then reverse it
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // check if k nodes exists 
        int cnt = 0;
        while(cnt < k){
            if(temp == NULL) return head;
            temp = temp->next;
            cnt++;
        }

        // recuvrisely call
        // here the temp variable is already out of the kth rage so we have to do that for it
        ListNode* prevNode = reverseKGroup(temp, k);
        
        // reverse current group
        // this is reversing the k goups of the nodes
        temp = head;
        cnt = 0;
        while(cnt < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};