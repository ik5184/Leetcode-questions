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
       int findposition(vector<int>& inorder,int element,int k){
        for(int i=0;i<k;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
        
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int inst,int inend,int n){
        if(index<0 | inst > inend){
            return NULL;
        }
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        int pos=findposition(inorder,element,n);
        root->right=solve(inorder,postorder,index,pos+1,inend,n);
        root->left=solve(inorder,postorder,index,inst,pos-1,n);
     
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int preindex=size-1;
        TreeNode* ans=solve(inorder,postorder,preindex,0,size-1,size);
        return ans;
        
        
    }
};