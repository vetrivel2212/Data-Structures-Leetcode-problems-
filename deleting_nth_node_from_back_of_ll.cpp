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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int count = 0;
        while(temp!=nullptr)
        {
            count+=1;
            temp=temp->next;
        }
        int pos = count-n+1;
        if(pos==1){
            ListNode *newhead = head->next;
            delete(head);
            return newhead;

        } //deleting the head;
        
        int i=1;
        temp=head;
        ListNode* prev;
        while(i<pos)
        {
            prev = temp;
            i=i+1;
            temp=temp->next;
        }
        prev ->next = temp->next;
        delete(temp);
        return head;
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* dummy = new ListNode();
//         dummy->next=head;
//         ListNode *fast=dummy,*slow=dummy;
//         for(int i=0;i<n;i++)
//         {
//             fast = fast->next;
//         }
//         while(fast->next!=nullptr){
//             slow=slow->next;
//             fast = fast->next;
//         }
//         slow->next=slow->next->next;
//         return dummy->next;
        
//     }
// };
