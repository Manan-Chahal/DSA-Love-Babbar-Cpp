#include <iostream>
using namespace std;

// Custom Deque (Double-Ended Queue) Implementation using Array
class Deque{
  private:
    int *arr;    // Dynamic array to store deque elements
    int n;       // Maximum size of the deque
    int front;   // Index of the front element
    int rear;    // Index of the rear element
  
  public:
    // Constructor: Initialize deque with given size
    Deque(int size) {
      this->n = size;        // Set maximum capacity
      arr = new int[size];   // Allocate memory for array
      front = -1;            // Initially no front element
      rear = -1;             // Initially no rear element
    }
    
    // Insert element at the front of deque
    void pushFront(int val) {
      if(front == 0) {
        // No space left on the left side for insertion
        // Front is already at index 0, can't go further left
        cout << "Overflow" << endl;
      }
      else if(front == -1 && rear == -1) {
        // Deque is empty, inserting first element
        front++;             // Move front to index 0
        rear++;              // Move rear to index 0
        arr[front] = val;    // Insert element at front
      }
      else {
        // Normal flow: deque has elements, add at front
        front--;             // Move front one position left
        arr[front] = val;    // Insert element at new front position
      }
    }
    
    // Remove element from the back of deque
    void popBack() {
      if(front == -1 && rear == -1) {
        // Deque is empty, no element to remove (underflow)
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        // Only one element in deque
        // After removing it, deque will become empty
        arr[rear] = -1;      // Optional: clear the element
        front = -1;          // Reset front to empty state
        rear = -1;           // Reset rear to empty state
      }
      else {
        // Normal flow: multiple elements in deque
        arr[rear] = -1;      // Optional: clear the rear element
        rear--;              // Move rear one position left
      }
    }
    
    // Insert element at the back of deque
    void pushBack(int val) {
      if(rear == n-1) {
        // No space left on the right side for insertion
        // Rear is already at last index, can't go further right
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        // Deque is empty, inserting first element
        rear++;              // Move rear to index 0
        front++;             // Move front to index 0
        arr[rear]= val;      // Insert element at rear
      }
      else {
        // Normal flow: deque has elements, add at back
        rear++;              // Move rear one position right
        arr[rear] = val;     // Insert element at new rear position
      }
    }
    
    // Remove element from the front of deque
    void popFront() {
      if(front==-1 && rear==-1) {
        // Deque is empty, no element to remove (underflow)
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        // Only one element in deque
        // After removing it, deque will become empty
        arr[front] = -1;     // Optional: clear the element
        front = -1;          // Reset front to empty state
        rear = -1;           // Reset rear to empty state
      }
      else {
        // Normal flow: multiple elements in deque
        arr[front] = -1;     // Optional: clear the front element
        front++;             // Move front one position right
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
    ~Deque() {
      delete[] arr;
    }
};

int main() {
  // Create a deque with capacity of 5
  Deque dq(5);

  cout << "=== DEQUE OPERATIONS DEMONSTRATION ===" << endl;
  
  // Push operations
  cout << "1. pushFront(10):" << endl;
  dq.pushFront(10);    // Deque: [10] (at index 0)
  dq.print();          // Output: 10 -1 -1 -1 -1
  
  cout << "2. pushFront(20):" << endl;
  dq.pushFront(20);    // Deque: [20, 10] (20 at front)
  dq.print();          // Output: -1 20 10 -1 -1 (20 inserted at left of 10)
  
  cout << "3. pushBack(15):" << endl;
  dq.pushBack(15);     // Deque: [20, 10, 15]
  dq.print();          // Output: -1 20 10 15 -1
  
  cout << "4. pushBack(35):" << endl;
  dq.pushBack(35);     // Deque: [20, 10, 15, 35]
  dq.print();          // Output: -1 20 10 15 35
  
  cout << "5. pushFront(100):" << endl;
  dq.pushFront(100);   // Deque: [100, 20, 10, 15, 35]
  dq.print();          // Output: 100 20 10 15 35
  
  // Pop operations
  cout << "\n=== POP OPERATIONS ===" << endl;
  
  cout << "6. popFront():" << endl;
  dq.popFront();       // Remove 100, Deque: [20, 10, 15, 35]
  dq.print();          // Output: -1 20 10 15 35
  
  cout << "7. popFront():" << endl;
  dq.popFront();       // Remove 20, Deque: [10, 15, 35]
  dq.print();          // Output: -1 -1 10 15 35
  
  cout << "8. popFront():" << endl;
  dq.popFront();       // Remove 10, Deque: [15, 35]
  dq.print();          // Output: -1 -1 -1 15 35
  
  cout << "9. popFront():" << endl;
  dq.popFront();       // Remove 15, Deque: [35]
  dq.print();          // Output: -1 -1 -1 -1 35

  return 0;
}

/*
Key Concepts Explained:
======================

1. DEQUE (DOUBLE-ENDED QUEUE):
   - Allows insertion and deletion from both ends (front and rear)
   - More flexible than regular queue or stack
   - Supports 4 main operations: pushFront, pushBack, popFront, popBack

2. ARRAY IMPLEMENTATION:
   - Uses front and rear pointers to track deque boundaries
   - Elements can be added/removed from either end
   - front and rear can move in both directions

3. INDEX MANAGEMENT:
   - front: points to the first element
   - rear: points to the last element
   - Both start at -1 (indicating empty deque)
   - front can decrease (move left) when pushFront is called
   - rear can increase (move right) when pushBack is called

4. OPERATIONS EXPLAINED:
   - pushFront(val): Insert at front, decrease front index
   - pushBack(val): Insert at rear, increase rear index
   - popFront(): Remove from front, increase front index
   - popBack(): Remove from rear, decrease rear index

5. EDGE CASES:
   - Empty deque: front == -1 && rear == -1
   - Single element: front == rear
   - Front overflow: front == 0 (can't insert more at front)
   - Rear overflow: rear == n-1 (can't insert more at rear)
   - Underflow: pop from empty deque

6. LIMITATIONS:
   - Fixed size array implementation
   - Space may be wasted as elements are not reused
   - Circular deque would be more space-efficient

7. VISUALIZATION EXAMPLE:
   Initial: [-1, -1, -1, -1, -1] (empty)
   pushFront(10): [10, -1, -1, -1, -1] (front=0, rear=0)
   pushFront(20): [-1, 20, 10, -1, -1] (front moves left to accommodate new front element)
   pushBack(15): [-1, 20, 10, 15, -1] (rear moves right to add new rear element)
   popFront(): [-1, -1, 10, 15, -1] (front moves right, 20 is removed)
   popBack(): [-1, -1, 10, -1, -1] (rear moves left, 15 is removed)
   
   Note: Visualization shows logical state, not physical memory layout.
*/