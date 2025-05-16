// Length Of The Loop LinkedList

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// time complexity: O(n)
// space complexity: O(1)
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        int count = 0;
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        if(fast == NULL || fast->next == NULL) return 0;
        Node* mark = slow;
        slow = slow->next;
        count++;

        while(slow != mark){
            count++;
            slow = slow->next;
        }
        return count;
    }
};