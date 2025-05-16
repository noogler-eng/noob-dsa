// Rotate a Linked List
// Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

// Example 1:
// Input:
// 	head = [1,2,3,4,5] 
// 	k = 2
// Output:
//  head = [4,5,1,2,3]

// 1 -> 2 -> 3 -> 4 -> 5
// now we connect 5 to the 1 
// now we move head and then disconnect

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return nullptr;
        
        ListNode* start = head;
        ListNode* end = head;
        
        int count = 1;
        while(end->next){
            count++;
            end = end->next;
        }

        end->next = start;
        k = k % count;
        ListNode* prev = start;

        k = count - k;
        while(k > 0){
            prev = start;
            start = start->next;
            k--;
        }

        prev->next = nullptr;
        head = start;
        return head;
    }
};