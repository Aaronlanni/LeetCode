Given n, generate all structurally unique BST's (binary search trees) 
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is 
serialized on OJ.


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
    vector<TreeNode *> generateTrees(int n) {
        return createTree(1,n);
    }
    
    vector<TreeNode *> createTree(int left,int right)
    {
         vector<TreeNode *> vt;
        //如果左边的区间大于右边的区间，此时已经将这棵树排列完成
        if(left>right)
        {
            vt.push_back(NULL);
            return vt;
        }
        for(int i=left;i<=right;++i)
        {
            vector<TreeNode* > start=createTree(left,i-1);//左子树的结点
            vector<TreeNode* > end=createTree(i+1,right);//右子树的结点
            for(int l=0;l<start.size();++l)
            {
                for(int r=0;r<end.size();++r)
                {
                    TreeNode *root=new TreeNode(i);
                    root->left=start[l];
                    root->right=end[r];
                    vt.push_back(root);
                }
            }
        }
        return vt;
    }
};