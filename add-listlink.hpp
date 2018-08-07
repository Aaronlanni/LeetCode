����һ���������������Ƚ����ĺ�����ӽ��
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
        int flag=0;//��ʾ��λ
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
        //��������������һ��Ϊ�գ����˳������ѭ�������Ǽٶ�l1��Ϊ�գ��ղŵ�flag�н�λ����l1
        //���������ҲȫΪ9����������ﻹ����Ҫ��λ
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
        //����������������н��������֮���п��������һ����λ
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
������������������Ϊ��֮ʱ���������������µĽ��
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
        int flag=0;//��ʾ��λ
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
            //����������Ϊ��֮ʱ�����ߵ������ĩβ����˴�ʱӦ������ѭ��
            if(l1==NULL&&l2==NULL)
                break;
            //���֮ʱ��������Ϊ�գ����ڴ�����ĺ��湹���½�㣬�ȴ���������Ϊ��
            if(l1==NULL)
                l1=new ListNode(0);
            
            if(l2==NULL)
                l2=new ListNode(0);
        }
        //����������������н��������֮���п��������һ����λ
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