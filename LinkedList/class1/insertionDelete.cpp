#include <iostream> // For input/output operations
using namespace std;

// Node class for singly linked list
class Node{
  public:
    int data;      // Stores the value of the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int value) {
      this->data = value;   // Set data
      this->next = NULL;    // Set next pointer to NULL
    }
};

// Insert a node at the head of the linked list
Node* insertAtHead(int value, Node* &head, Node* &tail) {
  // If list is empty (both head and tail are NULL)
  if(head == NULL && tail == NULL ) {
    Node* newNode = new Node(value); // Create new node
    head = newNode;                  // Set head to new node
    tail = newNode;                  // Set tail to new node
  }
  else {
    // List is not empty
    Node* newNode = new Node(value); // Create new node
    newNode->next = head;            // Link new node to current head
    head = newNode;                  // Update head to new node
  }
  return head; // Return updated head
}

// Insert a node at the tail of the linked list
void insertAtTail(int value, Node* &head, Node* &tail) {
  if(head == NULL && tail == NULL) {
    Node* newNode = new Node(value); // Create new node
    head = newNode;                  // Set head to new node
    tail = newNode;                  // Set tail to new node
  }
  else {
    Node* newNode = new Node(value); // Create new node
    tail->next  = newNode;           // Link current tail to new node
    tail = newNode;                  // Update tail to new node
  }
}

// Print the linked list
void print(Node* head) {
  Node* temp = head; // Start from head
  while(temp != NULL) { // Traverse until end
    cout << temp -> data << "->"; // Print node data
    temp = temp-> next;           // Move to next node
  }
  cout<<"NULL" << endl; // End of list
}

// Get the length of the linked list
int getLength(Node* head) {
  int len = 0;           // Initialize length
  Node* temp = head;     // Start from head
  while(temp != NULL) {  // Traverse until end
    temp = temp->next;   // Move to next node
    len++;               // Increment length
  }
  return len;            // Return length
}

// Insert a node at a specific position in the linked list
void insertAtPosition(int position,int value, Node* &head, Node* &tail ){
  int length = getLength(head); // Get current length
  if(position == 1) {
    // Insert at head
    head = insertAtHead(value, head, tail);
  }
  else if(position == length + 1) {
    // Insert at tail
    insertAtTail(value, head, tail);
  }
  else {
    // Insert in between
    Node* temp = head; // Start from head
    for(int i=0; i<position-2; i++) {
      temp = temp -> next; // Move to node before desired position
    }
    Node* newNode = new Node(value); // Create new node
    newNode->next = temp->next;      // Link new node to next node
    temp->next = newNode;            // Link previous node to new node
  }
}

// HW: Return exact position where target is found, else return -1
bool searchLL(int target, Node* head) {
  Node* temp = head; // Start from head
  while(temp != NULL) { // Traverse until end
    if(temp ->data == target) { // If data matches target
      return true;              // Return true
    }
    temp = temp->next;          // Move to next node
  }
  // If not found, return false
  return false;
}

// Delete a node from a specific position in the linked list
void deleteNodeFromLL(int position, Node* &head, Node* &tail) {
  // If list is empty
  if(head == NULL && tail == NULL) {
    cout << "No node to delete" << endl;
    return;
  }
  // Single node in list
  if(head == tail) {
    Node* temp = head; // Store node to delete
    head = NULL;       // Set head to NULL
    tail = NULL;       // Set tail to NULL
    delete temp;       // Delete node
  }
  else {
    // Multiple nodes in list
    // Case 1: Delete first node
    if(position == 1) {
      Node* temp = head;      // Store node to delete
      head = temp->next;      // Update head to next node
      temp->next = NULL;      // Disconnect node
      delete temp;            // Delete node
    }
    else {
      // Case 2: Delete node at other positions
      // We want to delete the node at 'position'
      // To do this, we need to reach the node just before the one to delete.
      // For example, to delete node at position 3, we need to reach position 2.
      // So, we start from head and move forward (position-2) times.
      // This is why we use: for(int i=0; i<position-2; i++)
      // After the loop, 'prev' points to the node just before the one to delete.
      Node* prev = head;
      for(int i=0; i<position-2; i++) {
        prev = prev -> next;
      }
      // 'curr' is the node to be deleted (prev->next)
      Node* curr = prev ->next;
      // 'forward' is the node after the one to delete (curr->next)
      Node* forward = curr ->next;
      // Link 'prev' to 'forward', skipping 'curr'
      prev->next = forward;
      // Disconnect 'curr' from the list
      curr->next = NULL;
      // Delete the node
      delete curr;
      // This ensures the node at 'position' is deleted and the list remains connected.
    }
  }
}

int main() {

  Node* head = NULL; // Initialize head pointer to NULL
  Node* tail = NULL; // Initialize tail pointer to NULL

  // Insert nodes at tail
  insertAtTail(101,head,tail); // List: 101->NULL
  insertAtTail(102,head,tail); // List: 101->102->NULL

  // Delete node at position 3 (should do nothing, as only 2 nodes)
  deleteNodeFromLL(3,head,tail);
  print(head);

  // Delete node at position 4 (should do nothing, as only 2 nodes)
  deleteNodeFromLL(4,head,tail);
  print(head);

  // Insert node at position 1 (head)
  insertAtPosition(1, 42, head, tail);
  // Insert node at position 5 (tail)
  insertAtPosition(5,57,head,tail);
  // Insert node at position 3 (middle)
  insertAtPosition(3,420,head,tail);
  print(head);

  // Uncomment below to test insertAtHead
  /*
  head = insertAtHead(10, head, tail);
  print(head); // 10->NULL
  head  = insertAtHead(20,head,tail);
  print(head); // 20->10->NULL
  head = insertAtHead(30,head,tail);
  print(head); // 30->20->10->NULL
  */

  // Uncomment below to test stack and dynamic memory allocation
  /*
  Node first; // Stack allocation
  Node* first = new Node(10); // Dynamic allocation
  */

  return 0; // End of program
}

/*
Explanation:
------------
- Each function is explained above with comments.
- The main function demonstrates insertion at tail, head, and any position, as well as deletion and printing.
- The linked list is built and modified step by step, showing how nodes are added and removed.

Test Cases:
-----------
- Insert at tail, head, and middle positions.
- Delete from head, middle, and tail.
- Print after each operation
*/