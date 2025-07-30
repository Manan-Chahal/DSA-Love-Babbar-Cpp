/*
Problem Statement:
-----------------
Given a queue, reverse the order of its elements.

Example:
Input: Queue = [1, 2, 3, 4] (front -> rear)
Output: Queue = [4, 3, 2, 1] (front -> rear)

We'll implement two approaches:
1. Iterative approach using a stack
2. Recursive approach using function call stack
*/

#include <iostream>
#include<queue>
#include<stack>
using namespace std;

// Approach 1: Using stack (iterative)
// Time Complexity: O(n) - We process each element twice
// Space Complexity: O(n) - We use a stack to store all elements
void reverseQueue(queue<int> &q) {
  stack<int> st;
  while(!q.empty()) {
    int element = q.front();
    q.pop();

    st.push(element);
  }
  //ab tak saare queue k element stack k andar push hogye honge

  //ab stack se element jab bahar nilakenge, toh vo reverse hogye honge
  //unn reversed elemnt ko queue me insert krdenge 
  while(!st.empty()) {
    int element = st.top();
    st.pop();

    q.push(element);
  }
}

// Approach 2: Using recursion
// Time Complexity: O(n) - We make n recursive calls
// Space Complexity: O(n) - Recursion stack stores n function calls
void reverseQueueRec(queue<int> &q) {
  //base case
  if(q.empty()) {
    return ;
  }
  //1 case main solve krunga 
  int frontElement = q.front();
  q.pop();
  //baaki recursion ki h 
  reverseQueueRec(q);
  ///backtracking 
  q.push(frontElement);
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  reverseQueueRec(q);

  //print all element inside queue
  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}

/*
Key Insights:
------------
1. Iterative approach uses a stack to naturally reverse the order:
   - First-in-First-out (queue) + Last-in-First-out (stack) = Reversed order

2. Recursive approach uses backtracking:
   - First removes all elements (reaching empty queue)
   - Then adds them back during the recursive call unwinding
   - This effectively reverses the order since the first element gets