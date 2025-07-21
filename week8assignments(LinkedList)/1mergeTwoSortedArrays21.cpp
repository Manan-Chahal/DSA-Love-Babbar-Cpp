// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        // Handle edge cases
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        // Dummy node to simplify list construction
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        // Traverse both lists
        while (left && right) {
            if (left->val <= right->val) {
                mptr->next = left;         // Link smaller node
                mptr = left;               // Move mptr forward
                left = left->next;         // Move left pointer
            } else {
                mptr->next = right;        // Link smaller node
                mptr = right;              // Move mptr forward
                right = right->next;       // Move right pointer
            }
        }

        // Attach remaining nodes
        if (left) {
            mptr->next = left;
            // Optional:
            // mptr = left;
            // left = left->next;
        }

        if (right) {
            mptr->next = right;
            // Optional:
            // mptr = right;
            // right = right->next;
        }

        return ans->next; // Return merged list (skip dummy node)
    }
};
