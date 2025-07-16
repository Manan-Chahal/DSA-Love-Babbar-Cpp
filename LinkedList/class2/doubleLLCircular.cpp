#include <iostream> // For input/output operations
using namespace std;

// Node class for Doubly Linked List
class Node{
  public: 
  int data;      // Stores the value of the node
  Node* prev;    // Pointer to the previous node
  Node* next;    // Pointer to the next node

  // Constructor to initialize node with a value
  Node(int value) {
    data = value;
    prev = NULL;
    next = NULL;
  }
};

// Insert a node at the head of the doubly linked list
void insertAtHead(int value, Node* &head, Node* &tail) {
  // 2 cases -> LL is empty / non-empty

  // Case 1: List is empty
  if(head == NULL && tail == NULL) {
    // Creating the first node
    Node* newNode = new Node(value);
    head = newNode;
    tail= newNode;
  }
  else {
    // Case 2: List is not empty
    Node* newNode = new Node(value);
    newNode->next = head;    // New node's next points to current head
    head -> prev = newNode;  // Current head's prev points to new node
    head = newNode;          // Update head to new node
  }
}

// Print the linked list from head to tail
void print(Node* head) {
  Node* temp = head;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp ->next;
  }
  cout << "NULL"<<endl;
}

// Print the linked list from tail to head (reverse)
void printReverse(Node* tail) {
  Node* temp = tail;
  while(temp != NULL) {
    cout << temp->data <<"->";
    temp = temp->prev;
  }
  cout << "NULL" << endl;
}

// Insert a node at the tail of the doubly linked list
void insertAtTail(int value, Node* &head, Node* &tail ){
  // 2 cases -> LL is empty or non-empty

  // Case 1: List is empty
  if(head == NULL && tail == NULL) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
  }
  else {
    // Case 2: List is not empty
    Node* newNode = new Node(value);
    newNode->prev = tail;    // New node's prev points to current tail
    tail->next = newNode;    // Current tail's next points to new node
    tail = newNode;          // Update tail to new node
  }
}

// Get the length of the doubly linked list
int getLength(Node* &head) {
  Node* temp = head;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp ->next;
  }
  return count;
}

// Insert a node at a specific position in the doubly linked list
void insertAtPosition(int position,int value, Node* &head, Node* &tail) {
  // 3 cases -> leftmost end, rightmost end, middle
  int len = getLength(head);
  if(position == 1) {
    // Insert at the leftmost (head)
    insertAtHead(value, head,tail);
  }
  else if(position == len+1) {
    // Insert at the rightmost (tail)
    insertAtTail(value, head, tail);
  }
  else {
    // Insert in the middle
    Node* temp = head;
    // Move temp to the node just before the desired position
    for(int i=0; i<position-2; i++) {
      temp = temp ->next;
    }
    // Create new node
    Node* newNode = new Node(value);
    // Set pointers for new node and surrounding nodes
    Node* forward = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    forward->prev = newNode;
    newNode->next = forward;
  }
}

// Search for an element in the doubly linked list
bool searchElement(Node* head, int target) {
  Node* temp = head;
  while(temp != NULL) {
    if(temp ->data == target) {
      return true; // Found the target
    }
    temp = temp -> next;
  }
  // If reached here, target not found
  return false;
}

// Delete a node from a specific position in the doubly linked list
void deleteFromPosition(int position, Node* &head, Node* &tail) {
  int length = getLength(head);

  // Case 1: List is empty
  if(head == NULL && tail == NULL) {
    cout << "no nodes to delete" << endl;
    return;
  }
  // Case 2: Only one node in the list
  else if(head == tail) {
    Node* temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
  }
  // Case 3: Delete head node
  else if(position == 1) {
    Node* temp = head;
    head = head->next;      // Move head to next node
    head->prev = NULL;      // Set new head's prev to NULL
    temp->next = NULL;      // Disconnect temp
    delete temp;            // Delete old head
  }
  // Case 4: Delete tail node
  else if(length == position) {
    Node* temp = tail;
    tail = temp->prev;      // Move tail to previous node
    tail->next = NULL;      // Set new tail's next to NULL
    temp->prev = NULL;      // Disconnect temp
    delete temp;            // Delete old tail
  }
  // Case 5: Delete a node from the middle
  else {
    Node* backward = head;
    // Move backward to the node just before the one to delete
    for(int i=0; i<position-2; i++) {
      backward = backward -> next;
    }
    Node* curr = backward->next;    // Node to delete
    Node* forward = curr->next;     // Node after the one to delete

    // Update pointers to bypass curr
    backward->next = forward;
    forward->prev = backward;
    // Isolate curr
    curr->prev = NULL;
    curr->next = NULL;
    delete curr; // Delete the node
  }
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // Insert at tail
  insertAtTail(10,head,tail);   // 10->NULL
  insertAtTail(20,head,tail);   // 10->20->NULL
  insertAtTail(30,head,tail);   // 10->20->30->NULL

  // Insert at position 4 (tail)
  insertAtPosition(4, 420, head, tail); // 10->20->30->420->NULL

  print(head); // Print list from head

  // Delete node at position 4 (tail)
  deleteFromPosition(4, head, tail); // 10->20->30->NULL

  print(head); // Print list from head

  // Uncomment below to test insertAtHead and printReverse
  /*
  insertAtHead(10,head,tail);   // 10->NULL
  insertAtHead(20,head,tail);   // 20->10->NULL
  insertAtHead(30,head,tail);   // 30->20->10->NULL
  print(head);                  // Print from head
  printReverse(tail);           // Print from tail
  */
  return 0;
}

/*
Explanation:
------------
- Node class defines a doubly linked list node with data, prev, and next pointers.
- insertAtHead/insertAtTail: Insert nodes at the beginning/end of the list.
- print/printReverse: Print the list from head or tail.
- insertAtPosition: Insert at any position (head, tail, or middle).
- searchElement: Search for a value in the list.
- deleteFromPosition: Delete node from any position (head, tail, or middle).
- main: Demonstrates insertion, deletion, and printing.

Test Cases:
-----------
- Insert at tail, head, and any position.
- Delete from head, tail, and middle.
- Print after each operation to verify correctness.
*/