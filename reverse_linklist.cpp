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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp =head,*nextnode=head,*prev=nullptr;
        while(temp!=nullptr)
        {
            nextnode = nextnode->next;
            temp->next = prev;
            prev =temp;
            temp = nextnode;
        }
        head = prev;
        return head;
    }
};
