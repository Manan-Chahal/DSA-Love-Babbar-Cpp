#include <iostream>
using namespace std;

// Double-Ended Circular Queue Implementation using Array
class DeCircularQueue{
  public :
    int *arr;
    int n;
    int front;
    int rear;

    // Constructor: Initialize the circular deque with given size
    DeCircularQueue(int size) {
      this-> n = size;
      arr = new int[size];
      front = -1;
      rear = -1;
    }

    // Insert element at the front of the deque
    void pushFront(int val) {
      // 4 cases: Overflow, first element, circular nature, normal flow
      if((front == 0 && rear == n-1)||(rear == front-1)) {
        // OVERFLOW: Queue is full (either linear or circular full)
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        // FIRST ELEMENT: Queue is empty
        front++;
        rear++;
        arr[front] = val;
      }
      else if(front == 0 && rear != n-1) {
        // CIRCULAR CASE: front at 0, but rear not at end, so wrap front to end
        front = n-1;
        arr[front]=val;
      }
      else {
        // NORMAL CASE: just move front left
        front--;
        arr[front]= val;
      }
    }

    // Insert element at the back of the deque
    void pushBack(int val) {
      // 4 cases: Overflow, first element, circular nature, normal flow
      if((front == 0 && rear == n-1)||(rear == front-1)) {
        // OVERFLOW: Queue is full
        cout << "Overflow" << endl;
      }
      else if(front==-1 && rear == -1) {
        // FIRST ELEMENT: Queue is empty
        front++;
        rear++;
        arr[rear] = val;
      }
      else if(rear == n-1 && front != 0) {
        // CIRCULAR CASE: rear at end, but front not at 0, so wrap rear to start
        rear = 0;
        arr[rear] = val;
      }
      else {
        // NORMAL CASE: just move rear right
        rear++;
        arr[rear] = val;
      }
    }

    // Remove element from the front of the deque
    void popFront() {
      // 4 cases: Underflow, single element, circular nature, normal flow 
      if(front==-1 && rear==-1) {
        // UNDERFLOW: Queue is empty
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        // SINGLE ELEMENT: Only one element left
        arr[front] = -1;
        front=-1;
        rear= -1;
      }
      else if(front== n-1 ) {
        // CIRCULAR CASE: front at end, wrap to start
        arr[front] = -1;
        front = 0;
      }
      else {
        // NORMAL CASE: just move front right
        arr[front] = -1;
        front++;
      }
    }

    // Remove element from the back of the deque
    void popBack() {
      // 4 cases: Underflow, single element, circular nature, normal flow 
      if(front==-1 && rear==-1) {
        // UNDERFLOW: Queue is empty
        cout << "Underflow" << endl;
      }
      else if(front == rear) {
        // SINGLE ELEMENT: Only one element left
        arr[front] = -1;
        front=-1;
        rear= -1;
      }
      else if(rear == 0) {
        // CIRCULAR CASE: rear at start, wrap to end
        arr[rear] = -1;
        rear = n-1;
      }
      else {
       // NORMAL CASE: just move rear left
       arr[rear] = -1;
       rear--; 
      }
    }

    // Print all elements in the array (for debugging)
    void print() {
      for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main() {
  DeCircularQueue q(5);
  
  q.pushFront(10);
  q.print();
  q.pushFront(20);
  q.print();
  q.pushBack(30);
  q.print();
  q.pushBack(40);
  q.print();
  q.pushBack(50);
  q.print();
  q.pushFront(60);
  q.print();
  q.popFront();
  q.print();
  q.popFront();
  q.print();
  q.popFront();
  q.print();
  q.popBack();
  q.print();
  q.popFront();
  q.print();
  q.popFront();
  q.print();
  return 0;
}

/*
================================================================================
EXPLANATION: Double-Ended Circular Queue (Deque) - Step-by-Step Index Logic
================================================================================

💡 Concepts Refresher:
---------------------
- A circular queue wraps around when it reaches the end of the array.
- We use `% n` (implicitly through conditionals) to wrap indices.

⚙️ Initial Setup:
-----------------
DeCircularQueue q(5);
front = -1, rear = -1
arr = [?, ?, ?, ?, ?]

▶️ Step-by-step Execution:
--------------------------

✅ q.pushFront(10);
- Queue is empty → first element case.
- front = 0, rear = 0
- arr[0] = 10
arr:   [10, ?, ?, ?, ?]
index:  0  1  2  3  4
        ↑
      front & rear

✅ q.pushFront(20);
- front == 0 and rear != n-1 → wrap around.
- front = 4 (wrapped around)
- arr[4] = 20
arr:   [10, ?, ?, ?, 20]
index:  0  1  2  3  4
            ↑     ↑
          rear   front

✅ q.pushBack(30);
- rear = 0, rear++ → 1
- arr[1] = 30
arr:   [10, 30, ?, ?, 20]
index:  0   1  2  3  4
            ↑     ↑
          rear   front

✅ q.pushBack(40);
- rear++ → 2
- arr[2] = 40
arr:   [10, 30, 40, ?, 20]
index:  0   1   2  3  4
                ↑     ↑
              rear   front

✅ q.pushBack(50);
- rear++ → 3
- arr[3] = 50
arr:   [10, 30, 40, 50, 20]
index:  0   1   2   3   4
                    ↑   ↑
                  rear front

❌ q.pushFront(60); → Overflow
- Condition (rear == front - 1) is true → Queue is full
Output: Overflow

✅ q.popFront();
- front = 4 → arr[4] = -1
- front = 0 (wrap)
arr:   [10, 30, 40, 50, -1]
index:  0   1   2   3   4
        ↑             ↑
      front         (was)

✅ q.popFront();
- arr[0] = -1, front++ → 1
arr:   [-1, 30, 40, 50, -1]
index:   0   1   2   3   4
            ↑
          front

✅ q.popFront();
- arr[1] = -1, front++ → 2
arr:   [-1, -1, 40, 50, -1]
index:   0   1   2   3   4
                ↑
              front

✅ q.popBack();
- rear = 3, arr[3] = -1, rear-- → 2
arr:   [-1, -1, 40, -1, -1]
index:   0   1   2   3   4
                ↑
              front & rear

✅ q.popFront();
- Single element left → set front = rear = -1
arr:   [-1, -1, -1, -1, -1]
index:   0   1   2   3   4

❌ q.popFront();
- Queue is empty → Underflow
Output: Underflow

🧠 Summary of Index Logic:
--------------------------
| Operation   | Index Update                                                                            |
| ----------- | --------------------------------------------------------------------------------------- |
| pushFront   | - If first: front = rear = 0<br>- If front==0: wrap to n-1<br>- Else: front--           |
| pushBack    | - If first: front = rear = 0<br>- If rear==n-1: wrap to 0<br>- Else: rear++             |
| popFront    | - If one element: reset both to -1<br>- If front==n-1: wrap to 0<br>- Else: front++     |
| popBack     | - If one element: reset both to -1<br>- If rear==0: wrap to n-1<br>- Else: rear--       |

This structure is useful for problems requiring fast insertions and deletions from both ends, with
*/