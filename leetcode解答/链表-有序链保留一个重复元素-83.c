//
//  链表-有序链保留一个重复元素-83.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr) return nullptr;
    ListNode * sod= new ListNode(INT_MIN);
    sod->next=head;
    ListNode * sp=sod;
    ListNode * fp=sp->next;
//    bool goround=false;
    while(fp!=nullptr){
//        goround=false;
        while(fp->next!=nullptr and fp->val==fp->next->val){
//            goround=true;
            fp=fp->next;
        }
//        if(goround==true){
//            fp=fp->next;
//            continue;
//        }
        sp->next=fp;
        fp=fp->next;
        sp=sp->next;
    }
//    if(goround==true) sp->next=nullptr;
    return sod->next;
}
