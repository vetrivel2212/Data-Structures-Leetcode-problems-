/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Problem Statement: Write a function to delete a node in a singly-linked list. 
//   You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly.
//   It is guaranteed that the node to be deleted is not a tail node in the list.
class Solution {
public:
    void deleteNode(ListNode* node) {
        node ->val = node ->next->val;
        node ->next = node ->next->next;
        
    }
};
