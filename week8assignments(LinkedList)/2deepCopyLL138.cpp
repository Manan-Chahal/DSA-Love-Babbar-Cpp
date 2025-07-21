/*
Problem: Deep Copy of Linked List with Random Pointer
LeetCode: https://leetcode.com/problems/copy-list-with-random-pointer/
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// ==================== Approach 1: Using Hash Map ====================
class Solution {
public:
    // Helper function to recursively clone nodes
    Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
        if (head == nullptr) return nullptr; // base case

        Node* newHead = new Node(head->val); // clone current node
        mp[head] = newHead; // map original -> copy

        newHead->next = helper(head->next, mp); // recursively copy next

        if (head->random) {
            newHead->random = mp[head->random]; // use map for random
        }

        return newHead;
    }

    // Main function
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; // old node -> new node mapping
        return helper(head, mp); // return deep copy
    }
};

/*
Time Complexity: O(N)
- Each node is visited once for cloning and once for random pointer assignment.

Space Complexity: O(N)
- Hash map stores mapping for all nodes.
*/

// ==================== Approach 2: In-place (No Extra Space) ====================
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone A -> A'
        Node* it = head; // iterator on the original list

        while (it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = clonedNode->next;
        }

        // Step 2: Assign random links for A'
        it = head;
        while (it) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = clonedNode->next;
        }

        // Step 3: Detach A' from A
        it = head;
        Node* clonedHead = head->next;
        while (it) {
            Node* clonedNode = it->next;
            it->next = clonedNode->next; // restore original list

            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next; // fix next for clone
            }

            it = it->next; // move to next original node
        }

        return clonedHead;
    }
};

/*
Time Complexity: O(N)
- Each node is visited three times (cloning, random assignment, detaching).

Space Complexity: O(1)
- No extra space except for the cloned nodes themselves.
*/

/*
Summary:
--------
- Approach 1 uses a hash map to store mapping from original to cloned nodes. Simple and clear, but uses extra space.
- Approach 2 interleaves cloned nodes with original nodes, sets random pointers in-place, and then detaches the cloned list. More space-efficient.
