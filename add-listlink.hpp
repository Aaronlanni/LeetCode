方法一：不在哪条链表先结束的后面添加结点
You are given two linked lists representing two non-negative numbers.
 The digits are stored in reverse order and each of their nodes 
contain a single digit. Add the two numbers and return it as 
a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL&&l2==NULL)
            return NULL;
        int flag=0;//表示进位
        ListNode *tmp=new ListNode(-1);
        ListNode *newhead=tmp;
        int sum=0;
        while(l1&&l2)
        {
            sum=flag+l1->val+l2->val;
            ListNode *node=new ListNode(sum%10);
            flag=sum/10;
            newhead->next=node;
            newhead=newhead->next;
            l1=l1->next;
            l2=l2->next;
        }
        //当两条链表中有一条为空，则退出上面的循环，但是假定l1不为空，刚才的flag有进位，而l1
        //后面的数字也全为9，因此在这里还是需要进位
        while(l1!=NULL)
        {
            sum=flag+l1->val;
            flag=sum/10;
            
            ListNode *node=new ListNode(sum%10);
            newhead->next=node;
            newhead=newhead->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            sum=flag+l2->val;
            flag=sum/10;
            
            ListNode *node=new ListNode(sum%10);
            newhead->next=node;
            newhead=newhead->next;
            l2=l2->next;
        }
        //当将两条链表的所有结点相加完成之后，有可能最后还有一个进位
        if(flag!=0)
        {
            ListNode *node=new ListNode(flag);
            newhead->next=node;
            newhead=newhead->next;
        }
        newhead->next=NULL;
        return tmp->next;
    }
};
方法二：当哪条链表为空之时，即在其后面添加新的结点
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL&&l2==NULL)
            return NULL;
        int flag=0;//表示进位
        ListNode *tmp=new ListNode(-1);
        ListNode *newhead=tmp;
        while(l1&&l2)
        {
            int sum=flag+l1->val+l2->val;
            flag=sum/10;
            ListNode *node=new ListNode(sum%10);
            newhead->next=node;
            newhead=newhead->next;
            l1=l1->next;
            l2=l2->next;
            //当两条链表都为空之时，即走到链表的末尾，因此此时应该跳出循环
            if(l1==NULL&&l2==NULL)
                break;
            //如果之时单条链表为空，则在此链表的后面构造新结点，等待两条链表都为空
            if(l1==NULL)
                l1=new ListNode(0);
            
            if(l2==NULL)
                l2=new ListNode(0);
        }
        //当将两条链表的所有结点相加完成之后，有可能最后还有一个进位
        if(flag!=0)
        {
            ListNode *node=new ListNode(flag);
            newhead->next=node;
            newhead=newhead->next;
        }
        newhead->next=NULL;
        return tmp->next;
    }
};