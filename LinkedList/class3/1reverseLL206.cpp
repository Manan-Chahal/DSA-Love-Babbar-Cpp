// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Recursive helper function to reverse the linked list
    // prev: previous node, curr: current node
    ListNode* reverseList(ListNode* &prev, ListNode* &curr) {
        // base case: if current is NULL, the list is fully reversed
        if(curr == NULL) {
            // prev now points to the new head of the reversed list
            return prev;
        }
        // Save the next node
        ListNode* forward = curr->next;
        // Reverse the current node's pointer
        curr->next = prev;
        // Move prev and curr one step forward
        prev = curr;
        curr = forward;
        // Recursively reverse the rest of the list
        return reverseList(prev, curr);
    }

    // Main function to reverse the linked list (recursive)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;      // Initially, previous node is NULL
        ListNode* curr = head;      // Start from the head node
        // Call the recursive helper
        ListNode* newHead = reverseList(prev, curr);
        return newHead;             // Return the new head of the reversed list
    }

    // Iterative method to reverse the linked list
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* forward = curr->next;
            // forward pointer set hogya, ab aage ki list lost nhi hogi
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev; // prev will be the new head
    }
};

/*
Explanation:
------------
- The recursive helper function takes two pointers: prev (previous node) and curr (current node).
- At each step, it reverses the link of the current node to point to the previous node.
- It then moves both pointers one step forward and calls itself recursively.
- When curr becomes NULL, prev points to the new head of the reversed list.
- The main function sets up the initial pointers and calls the helper.
- The iterative method uses a loop to reverse the list in-place, using prev, curr, and forward pointers.

Your approach is preserved exactly as you wrote it.
*/