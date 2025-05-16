// Reverse A Linked List
#include <iostream> 
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* futr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = futr;
        }
        return prev;
    }
};