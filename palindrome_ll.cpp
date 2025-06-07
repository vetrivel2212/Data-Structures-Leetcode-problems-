ListNode* reverse(ListNode *head)
{
    ListNode *temp = head, *nextnode = head, *prev = nullptr;
    while (temp != nullptr)
    {
        nextnode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // edge case for 0 or 1 node

        ListNode *slow = head, *fast = head;

        // Fix: Safe middle finding
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        slow = reverse(slow);

        // Compare first half and reversed second half
        ListNode *first = head, *second = slow;
        while (second != nullptr)
        {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
