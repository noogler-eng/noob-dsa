// Remove nth Node From End of List

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;  
        }

        int from_front = count - n;
        if(from_front == 0){
            return head->next;
        
        ListNode* prev = head;
        ListNode* temp = head;
        while(temp != NULL){
            
        }



    }
};
