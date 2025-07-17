// GeeksforGeeks Problem Link:
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    // Iterative function to reverse a linked list
    Node* reverseList(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // Function to add one to the number represented by the linked list
    Node* addOne(Node *head) 
    {
        // Step 1: Reverse the list
        head = reverseList(head);
        // Step 2: Add one
        int carry = 1;
        Node* temp = head;
        
        while(temp != NULL) {
            int sum = carry + temp->data;
            int digit = sum % 10;
            carry = sum / 10;
            
            temp -> data = digit;
            // If at last node and carry remains, add new node
            if(temp -> next == NULL && carry != 0) {
                Node* newNode = new Node(carry);
                newNode->next = NULL;
                temp->next = newNode;
                temp = newNode;
            }
            temp = temp -> next;
        }
        // Step 3: Reverse the list again to restore original order
        head = reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends