#include <iostream>
#include <queue>
using namespace std;

/*
  Binary Search Tree (BST) Implementation
  
  Properties:
  - Left subtree contains only nodes with values less than the node's value
  - Right subtree contains only nodes with values greater than the node's value
  - Both left and right subtrees are also BSTs
  - No duplicate values (in this implementation)
*/

// Node class represents a single node in the Binary Search Tree
class Node {
public:
  int data;       // Value stored in the node
  Node *left;     // Pointer to left child
  Node *right;    // Pointer to right child

  // Constructor to initialize a new node with a given value
  Node(int val) {
    this->data = val;
    left = NULL;  // Initially, both left and right children are NULL
    right = NULL;
  }
};

// Function to insert a new value into the BST
// Time Complexity: O(log n) in average case, O(n) in worst case (skewed tree)
// Space Complexity: O(h) where h is the height of the tree (for recursion stack)
Node* buildBST(int val, Node *root) {
  // Base case: If tree is empty, create a new node
  if (root == NULL) {
    root = new Node(val);
    return root;
  } else {
    // Recursive case: Insert into left or right subtree based on BST property
    if (val < root->data) {
      // If value is less than current node, go to left subtree
      root->left = buildBST(val, root->left);
    } else {
      // If value is greater than current node, go to right subtree
      root->right = buildBST(val, root->right);
    }
  }
  return root;  // Return the modified root
}

// Preorder Traversal: Root → Left → Right
// Time Complexity: O(n) where n is number of nodes
// Space Complexity: O(h) for recursion stack
void preorderTraversal(Node* root) {
  if(root == NULL)  // Base case
    return;
  
  cout << root->data << " ";  // Visit root first
  preorderTraversal(root->left);  // Visit left subtree
  preorderTraversal(root->right); // Visit right subtree
}

// Inorder Traversal: Left → Root → Right
// For BST, this produces values in sorted (ascending) order
// Time Complexity: O(n)
// Space Complexity: O(h)
void inorderTraversal(Node* root) {
  if(root == NULL)  // Base case
    return;
  
  inorderTraversal(root->left);   // Visit left subtree
  cout << root->data << " ";      // Visit root
  inorderTraversal(root->right);  // Visit right subtree
}

// Postorder Traversal: Left → Right → Root
// Time Complexity: O(n)
// Space Complexity: O(h)
void postorderTraversal(Node* root) {
  if(root == NULL)  // Base case
    return;
  
  postorderTraversal(root->left);   // Visit left subtree
  postorderTraversal(root->right);  // Visit right subtree
  cout << root->data << " ";        // Visit root last
}

// Function to create a BST by taking input from user
// Stops when user enters -1
void createTree(Node* &root) {
  cout << "Enter the value for Node: " << endl;
  int val;
  cin >> val;

  // Continue until user enters -1 (sentinel value)
  while (val != -1) {
    root = buildBST(val, root);  // Insert value into BST
    cout << "Enter the value for Node: " << endl;
    cin >> val;
  }
}

// Level Order Traversal (Breadth-First Search)
// Prints tree level by level
// Time Complexity: O(n)
// Space Complexity: O(w) where w is the maximum width of the tree
void levelOrderTraversal(Node *root) {
  if (root == NULL) return;  // Handle empty tree
  
  queue<Node *> q;  // Queue to store nodes
  q.push(root);     // Start with root
  q.push(NULL);     // NULL marks end of current level

  while (!q.empty()) {
    Node *front = q.front();  // Get front node
    q.pop();
    
    if (front == NULL) {
      // End of current level
      cout << endl;
      if (!q.empty()) {
        // If queue is not empty, add NULL marker for next level
        q.push(NULL);
      }
    } 
    else {
      // Print current node value
      cout << front->data << " ";
      
      // Add children to queue for next level processing
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
  }
}

// Function to find minimum value in BST
// In a BST, the leftmost node contains the minimum value
// Time Complexity: O(h) where h is height of tree
// Space Complexity: O(1)
int getMin(Node* root) {
  if(root == NULL) {
    return -1;  // Return -1 for empty tree
  }
  
  // Keep moving to left child until reaching the leftmost node
  while(root->left != NULL) {
    root = root->left;
  }
  // At this point, root is at the extreme left (minimum value)
  return root->data;
}

// Function to find maximum value in BST
// In a BST, the rightmost node contains the maximum value
// Time Complexity: O(h)
// Space Complexity: O(1)
int getMax(Node* root) {
  if(root == NULL) {
    return -1;  // Return -1 for empty tree
  }
  
  // Keep moving to right child until reaching the rightmost node
  while(root->right != NULL) {
    root = root->right;
  }
  // At this point, root is at the extreme right (maximum value)
  return root->data;
}

// Function to search for a value in BST
// Time Complexity: O(log n) average, O(n) worst case
// Space Complexity: O(h) due to recursion
bool searchBST(Node* root, int target) {
  // Base cases
  if(root == NULL) {
    return false;  // Target not found (empty tree or reached a leaf)
  }
  
  if(root->data == target) {
    return true;   // Target found
  }
  else {
    // Decide which subtree to search based on BST property
    if(target < root->data) {
      // If target is less than current node, search left subtree
      bool leftAns = searchBST(root->left, target);
      if(leftAns == true)
        return true;
    }
    else {
      // If target is greater than current node, search right subtree
      bool rightAns = searchBST(root->right, target);
      if(rightAns == true)
        return true;
    }
  }
  // Target not found in either subtree
  return false;
}

// Function to delete a node from BST
// Not implemented yet
Node* deleteFromBST(Node* root, int target) {
  // Implementation would handle three cases:
  // 1. Node with no children (leaf node)
  // 2. Node with one child
  // 3. Node with two children (requires finding inorder successor)
  return NULL;
}

int main() {
  Node *root = NULL;  // Start with an empty tree
  
  // Create BST from user input
  createTree(root);
  
  // Display tree using different traversal methods
  cout << "Printing Level Order:" << endl;
  levelOrderTraversal(root);
  
  cout << endl << "inorder: ";
  inorderTraversal(root);
  // NOTE: inorder of BST is always sorted (ascending order)
  
  cout << endl << "preorder: ";
  preorderTraversal(root);
  
  cout << endl << "postorder: ";
  postorderTraversal(root);
  cout << endl;
  
  // Find and display min/max values
  cout << "Min Element: "<< getMin(root) << endl;
  cout << "Max Element: "<< getMax(root) << endl;
  
  // Search for a specific value
  bool searchAns = searchBST(root, 251);
  if(searchAns) 
    cout << "Node Found" << endl;
  else
    cout << "Node not found" << endl;
  
  return 0;
}