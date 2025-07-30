#include <iostream>
#include<queue>
using namespace std;

int main() {

  // ==================== DEQUE (Double-Ended Queue) ====================
  // A deque allows insertion and deletion from both ends (front and back)
  deque<int> dq;
  
  // INSERTION OPERATIONS
  cout << "=== DEQUE INSERTION OPERATIONS ===" << endl;
  
  dq.push_front(10);
  cout << "After push_front(10): Front to Back -> ";
  // Current deque: [10]
  
  dq.push_front(30);
  cout << "After push_front(30): Front to Back -> ";
  // Current deque: [30, 10] (30 is now at front)
  
  dq.push_front(50);
  cout << "After push_front(50): Front to Back -> ";
  // Current deque: [50, 30, 10] (50 is now at front)
  
  dq.push_back(70);
  cout << "After push_back(70): Front to Back -> ";
  // Current deque: [50, 30, 10, 70] (70 added at back)
  
  dq.push_back(100);
  cout << "After push_back(100): Front to Back -> ";
  // Current deque: [50, 30, 10, 70, 100] (100 added at back)
  
  // DEQUE PROPERTIES
  cout << "\n=== DEQUE PROPERTIES ===" << endl;
  cout << "Size: " << dq.size() << endl;           // Output: 5
  cout << "Empty: " << dq.empty() << endl;         // Output: 0 (false)
  cout << "Front element: " << dq.front() << endl; // Output: 50 (first element)
  cout << "Back element: " << dq.back() << endl;   // Output: 100 (last element)

  // REMOVAL OPERATIONS
  cout << "\n=== DEQUE REMOVAL OPERATIONS ===" << endl;
  dq.pop_front(); // Removes 50 from front
  // Current deque: [30, 10, 70, 100]
  cout << "After pop_front(), new front: " << dq.front() << endl; // Output: 30
  
  dq.pop_back(); // Removes 100 from back
  // Current deque: [30, 10, 70]
  cout << "After pop_back(), new back: " << dq.back() << endl; // Output: 70

  cout << "\n" << endl;

  // ==================== REGULAR QUEUE (FIFO - First In First Out) ====================
  // Uncommented queue example for comparison
  queue<int> q;
  
  cout << "=== QUEUE OPERATIONS ===" << endl;
  
  // INSERTION (only at back)
  q.push(10); // Queue: [10]
  q.push(20); // Queue: [10, 20]
  q.push(30); // Queue: [10, 20, 30]
  q.push(40); // Queue: [10, 20, 30, 40]
  
  // ACCESS FRONT ELEMENT
  cout << "Front element: " << q.front() << endl; // Output: 10 (first element added)
  
  // REMOVAL (only from front)
  q.pop(); // Removes 10
  // Queue: [20, 30, 40]
  cout << "After pop(), new front: " << q.front() << endl; // Output: 20
  
  // QUEUE PROPERTIES
  cout << "Size: " << q.size() << endl;     // Output: 3
  cout << "Empty: " << q.empty() << endl;   // Output: 0 (false)
  cout << "Back element: " << q.back() << endl; // Output: 40 (last element added)

  // PRINTING ALL ELEMENTS (empties the queue)
  cout << "All queue elements: ";
  while(!q.empty()) {  // Fixed typo: was q.emtpy()
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  // After this loop, queue becomes empty

  return 0;
}

/*
Key Differences:
================

DEQUE:
- Can insert/remove from both front and back
- Operations: push_front(), push_back(), pop_front(), pop_back()
- More flexible than regular queue

QUEUE:
- Can only insert at back and remove from front (FIFO)
- Operations: push() (at back), pop() (from front)
- Follows strict First-In-First-Out principle

Common Operations for Both:
- front(): Access front element
- back(): Access back element (if supported)
- size(): Get number of elements
- empty(): Check if container is empty
*/