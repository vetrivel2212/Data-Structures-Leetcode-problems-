// Definition for linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode* bottom;
    ListNode(int x) : val(x), next(nullptr), bottom(nullptr) {}
};

class Solution {
public:
    ListNode* flatten(ListNode* root) {
        if (root == nullptr || root->next == nullptr) return root;

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge current list with the flattened list
        return merge(root, root->next);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* res = new ListNode(0); // Dummy node
        ListNode* temp = res;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                temp->bottom = a;
                a = a->bottom;
            } else {
                temp->bottom = b;
                b = b->bottom;
            }
            temp = temp->bottom;
        }

        // Attach the remaining nodes
        if (a != nullptr) temp->bottom = a;
        else temp->bottom = b;

        return res->bottom;
    }
};
