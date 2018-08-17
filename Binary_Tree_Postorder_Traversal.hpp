Given a binary tree, return the postorder traversal of its nodes' values.
Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?


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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vt;
        if(root==NULL)
            return vt;
        stack<TreeNode*> s;
        TreeNode *cur=root;
        TreeNode *Top=NULL;
        TreeNode *prev=NULL;
        while(cur||!s.empty())
        {
            //一直让左子树，一直走到根节点
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            //取出栈顶元素
            Top=s.top();
            //如果此时所取的栈顶元素如果他的右子树不存在，则此时就可以对其进行访问
            if(Top->right==NULL||prev==Top->right)
            {
                vt.push_back(Top->val);
                prev=Top;
                s.pop();
            }
            else
                cur=Top->right;
        }
        return vt;
    }
};