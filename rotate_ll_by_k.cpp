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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode *temp = head;
        int len = 1;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
            len+=1;
        }
        temp->next = head;
        k=k%len;
        k=len-k;
        int i =0;
        temp=head;
        while(i<k-1)
        {
            temp=temp->next;
            i++;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
