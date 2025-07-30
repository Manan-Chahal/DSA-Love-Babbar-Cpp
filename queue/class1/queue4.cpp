#include <iostream>
using namespace std;

// Circular Queue Implementation using Array
// Solves the space wastage problem of linear queue
class CircularQueue{
  public:
    int *arr;    // Dynamic array to store queue elements
    int n;       // Maximum size of the circular queue
    int front;   // Index of the front element
    int rear;    // Index of the rear element

  // Constructor: Initialize circular queue with given size
  CircularQueue(int size) {
    this->n = size;        // Set maximum capacity
    arr = new int[size];   // Allocate memory for array
    front = -1;            // Initially no front element
    rear = -1;             // Initially no rear element
  }

  // Insert element at the rear of circular queue
  void push(int val) {
    // 4 cases: Overflow, first element, circular nature, normal flow
    
    if((front == 0 && rear == n-1)||(rear == front-1)) {
      // OVERFLOW CONDITION:
      // Case 1: front at start (0) and rear at end (n-1) - queue is full
      // Case 2: rear is just before front - queue is full in circular manner
      cout << "Overflow" << endl;
    }
    else if(front==-1 && rear == -1) {
      // FIRST ELEMENT:
      // Queue is empty, inserting the very first element
      front++;             // Set front to 0
      rear++;              // Set rear to 0
      arr[rear] = val;     // Insert element at index 0
    }
    else if(rear == n-1 && front != 0) {
      // CIRCULAR NATURE:
      // Rear reached end but front is not at start
      // Wrap around: move rear to beginning (index 0)
      rear = 0;            // Wrap rear to start of array
      arr[rear] = val;     // Insert element at wrapped position
    }
    else {
      // NORMAL FLOW:
      // Regular insertion - just move rear forward
      rear++;              // Move rear to next position
      arr[rear] = val;     // Insert element at new rear position
    }
  }
  
  // Remove element from the front of circular queue
  void pop() {
    // 4 cases: Underflow, single element, circular nature, normal flow 
    
    if(front==-1 && rear==-1) {
      // UNDERFLOW CONDITION:
      // Queue is empty, nothing to remove
      cout << "Underflow" << endl;
    }
    else if(front == rear) {
      // SINGLE ELEMENT:
      // Only one element in queue, after removal queue becomes empty
      arr[front] = -1;     // Optional: clear the element
      front=-1;            // Reset front to empty state
      rear= -1;            // Reset rear to empty state
    }
    else if(front== n-1 ) {
      // CIRCULAR NATURE:
      // Front reached end of array, wrap around to beginning
      arr[front] = -1;     // Optional: clear the element
      front = 0;           // Wrap front to start of array
    }
    else {
      // NORMAL FLOW:
      // Regular removal - just move front forward
      arr[front] = -1;     // Optional: clear the element
      front++;             // Move front to next position
    }
  }
  
  // Get the front element without removing it
  int getFront() {
    if(front == -1) {
      // Queue is empty, no front element exists
      cout << "Queue is empty";
      return -1;           // Return default value
    }
    else {
      return arr[front];   // Return front element
    }
  }
  
  // Calculate current number of elements in circular queue
  int getSize() {
    if(front==-1 && rear == -1) {
      // Queue is empty
      return 0;
    }
    else if(rear >= front) {
      // Normal case: rear is ahead of or equal to front
      // Size = rear - front + 1
      return rear-front+1;
    }
    else{
      // Circular case: rear has wrapped around and is behind front
      // Size = elements from front to end + elements from start to rear + 1
      return n-front+rear+1;
    }
  }
  
  // Check if circular queue is empty
  bool isEmpty() {
    if(front == -1 && rear == -1) {
      return true;         // Queue is empty
    }
    else {
      return false;        // Queue has elements
    }
  }

  // Print all elements in the array (for debugging)
  void print() {
    for(int i=0; i<n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  // Destructor to free allocated memory
  ~CircularQueue() {
    delete[] arr;
  }
};

int main() {
  // Create a circular queue with capacity of 5
  CircularQueue q(5);

  cout << "=== CIRCULAR QUEUE OPERATIONS ===" << endl;
  
  // Fill the queue
  cout << "1. Filling the queue:" << endl;
  q.push(10);  // Queue: [10, -1, -1, -1, -1], front=0, rear=0
  q.print();
  q.push(20);  // Queue: [10, 20, -1, -1, -1], front=0, rear=1
  q.print();
  q.push(30);  // Queue: [10, 20, 30, -1, -1], front=0, rear=2
  q.print();
  q.push(40);  // Queue: [10, 20, 30, 40, -1], front=0, rear=3
  q.print();
  q.push(50);  // Queue: [10, 20, 30, 40, 50], front=0, rear=4 (FULL)
  q.print();
  
  cout << "\n2. Trying to add when full:" << endl;
  q.push(60);  // Overflow - queue is full
  q.print();
  
  cout << "\n3. Removing elements:" << endl;
  q.pop();     // Remove 10, Queue: [-1, 20, 30, 40, 50], front=1, rear=4
  q.print();
  q.pop();     // Remove 20, Queue: [-1, -1, 30, 40, 50], front=2, rear=4
  q.print();
  
  cout << "\n4. Adding in circular manner:" << endl;
  q.push(100); // Queue: [100, -1, 30, 40, 50], front=2, rear=0 (CIRCULAR!)
  q.print();
  q.push(101); // Queue: [100, 101, 30, 40, 50], front=2, rear=1 (CIRCULAR!)
  q.print();
  
  cout << "\n5. Queue properties:" << endl;
  cout << "Size: " << q.getSize() << endl;     // Output: 5 (queue is full again)
  cout << "Is Empty: " << q.isEmpty() << endl; // Output: 0 (false)
  cout << "Front Element: " << q.getFront() << endl; // Output: 30

  return 0;
}

/*
Key Concepts Explained:
======================

1. CIRCULAR QUEUE ADVANTAGES:
   - Solves space wastage problem of linear queue
   - Reuses memory locations after elements are popped
   - More efficient memory utilization
   - All array positions can be used multiple times

2. CIRCULAR NATURE:
   - When rear reaches end (n-1), it wraps to beginning (0)
   - When front reaches end (n-1), it wraps to beginning (0)
   - Think of array as a circle - last index connects to first index

3. OVERFLOW CONDITIONS:
   - Case 1: front=0, rear=n-1 (linear full condition)
   - Case 2: rear=front-1 (circular full condition)
   - Both indicate queue is completely full

4. SIZE CALCULATION:
   - If rear >= front: size = rear - front + 1 (normal case)
   - If rear < front: size = n - front + rear + 1 (circular case)
   - Example: n=5, front=3, rear=1 → size = 5-3+1+1 = 4

5. CIRCULAR MOVEMENT:
   - Push: rear = (rear + 1) % n (can be simplified as shown)
   - Pop: front = (front + 1) % n (can be simplified as shown)
   - The modulo operation handles wrapping automatically

6. VISUALIZATION EXAMPLE:
   Array indices: [0] [1] [2] [3] [4]
   After operations: [100] [101] [30] [40] [50]
   front=2 (pointing to 30), rear=1 (pointing to 101)
   This shows how circular queue can have rear "behind" front

7. MEMORY EFFICIENCY:
   - Linear queue wastes space after pop operations
   - Circular queue reuses all positions
   - Much better for applications with continuous