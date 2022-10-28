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
class Solution {
    
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int op1=maxDepth(root->left);
        int op2=maxDepth(root->right);
        int op3=max(op1,op2)+1;
        return op3;
        
    }
};