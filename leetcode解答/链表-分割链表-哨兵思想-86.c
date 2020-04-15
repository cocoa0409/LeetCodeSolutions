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
ListNode* partition(ListNode* head, int x) {
    if(head==nullptr or head->next==nullptr) return head;
    ListNode * sod= new ListNode(INT_MIN);//哨兵
    sod->next =head;
    ListNode * sp=sod;
    ListNode * fp=head;
    while(fp->val<x and fp->next!=nullptr){
        sp=fp;
        fp=fp->next;
    }
    if(fp->next==nullptr) return head; //说明不用更换了
    
    while(fp->next!=nullptr){
        if(fp->next->val>=x){fp=fp->next; continue;}
        ListNode * tmp;
        tmp=fp->next;
        fp->next=fp->next->next;
        tmp->next=sp->next;
        sp->next=tmp;
        sp=sp->next;
    }
    return sod->next;
}
};
