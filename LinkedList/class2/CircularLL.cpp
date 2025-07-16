#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// =================== DOUBLY LINKED LIST FUNCTIONS ===================

// Insert at head (doubly linked list)
void insertAtHead(int value, Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at tail (doubly linked list)
void insertAtTail(int value, Node* &head, Node* &tail ){
    if(head == NULL && tail == NULL) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Print from head to tail (doubly linked list)
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Print from tail to head (doubly linked list)
void printReverse(Node* tail) {
    Node* temp = tail;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// =================== CIRCULAR LINKED LIST FUNCTIONS ===================

// Node class can be reused for circular linked list

// Insert at tail (circular singly linked list)
void insertAtTailCircular(Node* &head, int value) {
    Node* newNode = new Node(value);
    if(head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself
    } else {
        Node* temp = head;
        // Traverse to last node (whose next is head)
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Print circular linked list (will print one full cycle)
void printCircular(Node* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)" << endl;
}

// Delete a node with a given value from circular linked list
void deleteCircular(Node* &head, int value) {
    if(head == NULL) return;

    Node* curr = head;
    Node* prev = NULL;

    // Special case: only one node
    if(head->next == head && head->data == value) {
        delete head;
        head = NULL;
        return;
    }

    // Find node to delete
    do {
        if(curr->data == value) break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    // If node not found
    if(curr->data != value) return;

    // If deleting head
    if(curr == head) {
        prev = head;
        while(prev->next != head) prev = prev->next;
        head = head->next;
        prev->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

// =================== MAIN FUNCTION ===================

int main() {
    // Doubly Linked List Demo
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(10, head, tail);
    insertAtTail(20, head, tail);
    insertAtTail(30, head, tail);
    insertAtHead(5, head, tail);

    cout << "Doubly Linked List (head to tail): ";
    print(head);

    cout << "Doubly Linked List (tail to head): ";
    printReverse(tail);

    // Circular Linked List Demo
    Node* chead = NULL;
    insertAtTailCircular(chead, 100);
    insertAtTailCircular(chead, 200);
    insertAtTailCircular(chead, 300);
    insertAtTailCircular(chead, 400);

    cout << "Circular Linked List: ";
    printCircular(chead);

    // Delete a node from circular linked list
    deleteCircular(chead, 200);
    cout << "After deleting 200: ";
    printCircular(chead);

    deleteCircular(chead, 100);
    cout << "After deleting 100 (head): ";
    printCircular(chead);

    deleteCircular(chead, 400);
    cout << "After deleting 400 (tail): ";
    printCircular(chead);

    deleteCircular(chead, 300);
    cout << "After deleting 300 (last node): ";
    printCircular(chead);

    return 0;
}

/*
==================== EXPLANATION ====================

Doubly Linked List:
-------------------
- Each node has a 'prev' and 'next' pointer.
- insertAtHead/insertAtTail: Add nodes at the beginning/end.
- print: Print from head to tail.
- printReverse: Print from tail to head.

Circular Linked List:
---------------------
- Each node has only a 'next' pointer.
- The last node's next points back to the head, forming a circle.
- insertAtTailCircular: Adds a node at the end, maintaining the circle.
- printCircular: Prints all nodes, stopping when it reaches head again.
- deleteCircular: Deletes a node by value, handling head, tail, and single-node cases.

Test Cases:
-----------
- Demonstrates insertion and printing for both doubly and circular linked lists.
- Demonstrates deletion in circular linked list for head, tail, and last node.