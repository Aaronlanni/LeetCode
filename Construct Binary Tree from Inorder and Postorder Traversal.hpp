Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty()||postorder.empty())
            return NULL;
        vector<int> inorder_left;
        vector<int> inorder_right;
        vector<int> postorder_left;
        vector<int> postorder_right;
        int length=postorder.size()-1;
        TreeNode *root=new TreeNode(postorder[length]);
        int i=0;
        for(;i<length;++i)
        {
            if(inorder[i]==postorder[length])
            {
                break;
            }
                inorder_left.push_back(inorder[i]);
                postorder_left.push_back(postorder[i]);
        }
        for(int j=i+1;j<=length;++j)
        {
            inorder_right.push_back(inorder[j]);
            postorder_right.push_back(postorder[j-1]);
        }
        root->left=buildTree(inorder_left,postorder_left);
        root->right=buildTree(inorder_right,postorder_right);
        return root;
    }
};