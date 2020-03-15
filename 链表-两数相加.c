//
//  链表-两数相加.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/8.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root= new ListNode((l1->val +l2->val)%10);
    ListNode* l1_ptr=l1->next;
    ListNode* l2_ptr=l2->next;
    ListNode* res_ptr=root;
    ListNode* new_ptr;
    int sum;
    int carrybit=(l1->val +l2->val)/10;
    while(l1_ptr!=NULL and l2_ptr!=NULL){
        sum=l1_ptr->val + l2_ptr->val + carrybit;
        carrybit = sum/10;
        sum = sum%10;
        new_ptr = new ListNode(sum);
        res_ptr->next=new_ptr;
        
        res_ptr=new_ptr;
        l1_ptr=l1_ptr->next;
        l2_ptr=l2_ptr->next;
    }
    if(l1_ptr==NULL){
        while(l2_ptr!=NULL){
            sum=l2_ptr->val + carrybit;
            carrybit = sum/10;
            sum = sum%10;
            new_ptr = new ListNode(sum);
            res_ptr->next=new_ptr;
            
            res_ptr=new_ptr;
            l2_ptr=l2_ptr->next;
        }
    }
    else{//l2_ptr==NULL
        while(l1_ptr!=NULL){
            sum=l1_ptr->val + carrybit;
            carrybit = sum/10;
            sum = sum%10;
            new_ptr = new ListNode(sum);
            res_ptr->next=new_ptr;
            
            res_ptr=new_ptr;
            l1_ptr=l1_ptr->next;
        }
    }

    if(l1_ptr==NULL and l2_ptr==NULL and carrybit ==1){
        new_ptr = new ListNode(carrybit);
        res_ptr->next=new_ptr;
        return root;
    }
    else{
        return root;
    }
}

