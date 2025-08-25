//good question (nice recursion concept)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//imp note here=
// Why Pass preorderStart by Reference (int &preorderStart)?

// If you pass it by value:

// Each recursive call gets its own copy of preorderStart.

// When you increment preorderStart inside a call, the change is not reflected in the parent call.

// That means every subtree would incorrectly think it’s still at the same root index.

// If you pass it by reference:

// All recursive calls share the same variable.

// When one call increments it (preorderStart++), that updated value is available to the next recursive call.

// This ensures preorder traversal is consumed sequentially across the whole recursion.
class Solution {
public:
    int getIndexInorder(vector<int>& inorder,int &target){
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==target){
                    return i;
                }
            }
            return -1;
    }
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int &preorderStart,int inorderStart,int inorderEnd,int &size)
    {
        if(preorderStart>=size){
            return NULL;
        }
        if(inorderStart>inorderEnd){
            return NULL;
        }
        int element = preorder[preorderStart];
        preorderStart++;
        TreeNode* root=new TreeNode(element);
        int elementIndexInsideInoder=getIndexInorder(inorder,element);
        root->left=constructTree(preorder,inorder,preorderStart,inorderStart,elementIndexInsideInoder-1, size);
        root->right=constructTree(preorder,inorder,preorderStart,elementIndexInsideInoder+1,inorderEnd, size);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderStart=0;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        int n=inorder.size();
        TreeNode* root=constructTree(preorder,inorder,preorderStart,inorderStart,inorderEnd,n);
        return root;
    }
};