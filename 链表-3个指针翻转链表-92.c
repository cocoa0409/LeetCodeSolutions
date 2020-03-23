//
//  链表-3个指针翻转链表-92.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode * sod = new ListNode(INT_MIN);
    sod->next=head;
    ListNode * lend=sod;
    ListNode * sp=sod;
    ListNode * fp=head;
    ListNode * tmp;
    for(int i=0;i<m;i++){
        sp=sp->next;
        fp=fp->next;
        if(i==0) continue;
        lend=lend->next;
    }
    for(int i=0;i<n-m;i++){
        tmp=fp->next;
        fp->next=sp;
        sp=fp;
        fp=tmp;
    }
    lend->next->next=fp;
    lend->next=sp;
    return sod->next;
}
