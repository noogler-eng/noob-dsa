// Segregate Odd, Even Node In Linkedlist

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity o(N)
// space complexity o(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *temp = head;
        ListNode *even = new ListNode(-1);
        ListNode *evenHead = even;
        ListNode * odd = new ListNode(-1);
        ListNode *oddHead = odd;
        
        int count = 1;
        while(temp != NULL){
            if(count % 2 == 1){
                odd->next = temp;
                odd = odd->next;
            }else{
                even->next = temp;
                even = even->next;
            }
            count++;
            temp = temp->next;
        }

        even->next = NULL;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};