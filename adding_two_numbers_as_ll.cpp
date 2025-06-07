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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        ListNode *p1 = l1,*p2=l2;
        int carry =0;
        while(p1!=nullptr || p2!=nullptr || carry==1)
        {
            int sum=0;
            if(p1!=nullptr)
            {
                sum+=p1->val;
                p1=p1->next;
            }
            if(p2!=nullptr)
            {
                sum+=p2->val;
                p2=p2->next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};
