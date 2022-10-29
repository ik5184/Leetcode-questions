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
    private:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int m1=height(root->left);
        int m2=height(root->right);
        int m3=max(m1,m2)+1;
        return m3;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);
        
        bool ans=abs(height(root->left)-height(root->right))<=1;
        
        if(leftans && rightans && ans){
            return ans;
        }
        else{
            return false;
        }
        
    }
};