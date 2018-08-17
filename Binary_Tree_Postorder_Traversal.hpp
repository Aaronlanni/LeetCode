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
            //һֱ����������һֱ�ߵ����ڵ�
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            //ȡ��ջ��Ԫ��
            Top=s.top();
            //�����ʱ��ȡ��ջ��Ԫ��������������������ڣ����ʱ�Ϳ��Զ�����з���
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