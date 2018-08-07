Given a linked list and a value x, partition it such that all nodes 
less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes 
in each of the two partitions.

For example,
Given1->4->3->2->5->2and x = 3,
return1->2->2->4->3->5.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
            return NULL;
        ListNode *tmp=new ListNode(-1);
        
        ListNode *tmp1=new ListNode(-1);
        tmp->next=head;
        ListNode *cur=tmp;
        ListNode *newhead=tmp1;
        while(cur->next)
        {
            if((cur->next->val) < x)
            {
                newhead->next=cur->next;
                newhead=newhead->next;
                
                cur->next=cur->next->next;
                newhead->next=NULL;
            }
            else{
                
                cur=cur->next;
            }
        }
        newhead->next=tmp->next;
        return tmp1->next;
    }
};