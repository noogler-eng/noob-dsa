// Merge K Sorted List
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity o(N*K)
// space complexity o(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // we have to take the min heap here
        vector<int> ans;
        // mini element will be given
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while (!pq.empty()) {
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            temp->next = node;
            temp = node;
        }

        return head->next;
    }
};