class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy, *curr, *nex;

        // Count total number of nodes
        int count = 0;
        curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        // Reverse in groups of k
        while (count >= k) {
            curr = prev->next;
            nex = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }

            prev = curr;
            count -= k;
        }

        return dummy->next;
    }
};
