#include <iostream>
using namespace std;

// Custom Queue Implementation using Array
class Queue{
  private:
    int *arr;    // Dynamic array to store queue elements
    int n;       // Maximum size of the queue
    int front;   // Index of the front element
    int rear;    // Index of the rear element
  
  public:
    // Constructor: Initialize queue with given size
    Queue(int size) {
      arr = new int[size];  // Allocate memory for array
      n = size;             // Set maximum capacity
      front = -1;           // Initially no front element
      rear = -1;            // Initially no rear element
    }
    
    // Insert element at the rear of queue
    void push(int val) {
      if(rear == n-1) {
        // Queue is full (overflow condition)
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        // Inserting first element into empty queue
        rear++;             // Move rear to index 0
        front++;            // Move front to index 0
        arr[rear]= val;     // Insert element
      }
      else {
        // Normal flow: queue has elements, add at rear
        rear++;             // Move rear to next position
        arr[rear] = val;    // Insert element at new rear position
      }
    }
    
    // Remove element from the front of queue
    void pop() {
      if(front==-1 && rear==-1) {
        // Queue is empty (underflow condition)
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        // Single element in queue
        arr[rear] = -1;     // Optional: clear the element
        front = -1;         // Reset front to empty state
        rear = -1;          // Reset rear to empty state
      }
      else {
        // Normal flow: multiple elements in queue
        arr[front] = -1;    // Optional: clear the front element
        front++;            // Move front to next element
      }
    }
    
    // Get the front element without removing it
    int getFront() {
      if(front == -1) {
        // Queue is empty, no front element exists
        cout << "Queue is empty" << endl;
        return -1;  // Return some default value
      }
      else {
        return arr[front];  // Return front element
      }
    }
    
    // Get the rear element without removing it
    int getRear() {
      if(rear == -1) {
        // Queue is empty, no rear element exists
        cout << "Queue is empty" << endl;
        return -1;  // Return some default value
      }
      else {
        return arr[rear];   // Return rear element
      }
    }
    
    // Get current number of elements in queue
    int getSize() {
      if(front == -1 && rear == -1) {
        // Queue is empty
        return 0;
      }
      else {
        // Size = rear index - front index + 1
        return rear - front + 1;
      }
    }
    
    // Check if queue is empty
    bool isEmpty() {
      if(front == -1 && rear == -1) {
        return true;   // Queue is empty
      }
      else {
        return false;  // Queue has elements
      }
    }
    
    // Destructor to free allocated memory
    ~Queue() {
      delete[] arr;
    }
};

int main() {
  // Create a queue with capacity of 5
  Queue q(5);

  // Test push operations
  cout << "=== PUSH OPERATIONS ===" << endl;
  q.push(10);  // Queue: [10]
  q.push(20);  // Queue: [10, 20]
  q.push(30);  // Queue: [10, 20, 30]
  q.push(40);  // Queue: [10, 20, 30, 40]
  cout << "Size after 4 pushes: " << q.getSize() << endl;  // Output: 4
  
  q.push(50);  // Queue: [10, 20, 30, 40, 50] (now full)
  cout << "Front element: " << q.getFront() << endl;       // Output: 10
  
  q.push(100); // Overflow - queue is full
  cout << "Is empty: " << q.isEmpty() << endl;             // Output: 0 (false)

  // Test pop operations
  cout << "\n=== POP OPERATIONS ===" << endl;
  q.pop();     // Remove 10, Queue: [20, 30, 40, 50]
  cout << "Size after 1 pop: " << q.getSize() << endl;    // Output: 4
  
  q.pop();     // Remove 20, Queue: [30, 40, 50]
  q.pop();     // Remove 30, Queue: [40, 50]
  q.pop();     // Remove 40, Queue: [50]
  q.pop();     // Remove 50, Queue: [] (empty)
  cout << "Size after 5 pops: " << q.getSize() << endl;   // Output: 0
  
  q.pop();     // Underflow - queue is empty

  return 0;
}

/*
Key Concepts Explained:
======================

1. QUEUE DATA STRUCTURE:
   - Follows FIFO (First In First Out) principle
   - Elements are added at rear and removed from front
   - Like a line of people waiting - first person in line is served first

2. ARRAY IMPLEMENTATION:
   - Uses front and rear pointers to track queue boundaries
   - front: points to the first element
   - rear: points to the last element
   - Both start at -1 (indicating empty queue)

3. OPERATIONS:
   - push(): Add element at rear
   - pop(): Remove element from front
   - getFront(): Access front element without removing
   - getRear(): Access rear element without removing
   - getSize(): Count current elements
   - isEmpty(): Check if queue is empty

4. EDGE CASES:
   - Empty queue: front == -1 && rear == -1
   - Single element: front == rear
   - Full queue: rear == n-1
   - Underflow: pop from empty queue
   - Overflow: push to full queue

5. LIMITATIONS:
   - This implementation wastes space (elements aren't reused after pop)
   - Circular queue would be more efficient in using space
*/