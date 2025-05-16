// Check If Linklist is Palindrome

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity o(2N)
// space complexity o(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* temp = head;
        string str = "";
        while(temp != NULL){
            str += to_string(temp->val);
            temp = temp->next;
        }

        int start = 0;
        int end = str.length() - 1;
        while(start <= end){
            if(str[start] != str[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};