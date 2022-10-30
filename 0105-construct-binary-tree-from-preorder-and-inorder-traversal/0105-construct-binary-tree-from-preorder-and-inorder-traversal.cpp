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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inst,int inend,int n){
        if(index>=n | inst > inend){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int pos=findposition(inorder,element,n);
        root->left=solve(preorder,inorder,index,inst,pos-1,n);
        root->right=solve(preorder,inorder,index,pos+1,inend,n);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=inorder.size();
        int preindex=0;
        TreeNode* ans=solve(preorder,inorder,preindex,0,size-1,size);
        return ans;
        
    }
};