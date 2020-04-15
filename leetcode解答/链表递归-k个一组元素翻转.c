//
//  main.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/7.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

ostream &operator<<(ostream &out, ListNode * head){
    out<<"start :";
    while(head!=nullptr){
        out<<head->val<<"--";
        head=head->next;}
    return out;
}

ListNode * swapPairs(ListNode  *head) {
    //终止条件：链表只剩一个节点或者没节点了，没得交换了。返回的是已经处理好的链表
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    //一共三个节点:head, next, swapPairs(next.next)
    //下面的任务便是交换这3个节点中的前两个节点
    ListNode *next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    //根据第二步：返回给上一级的是当前已经完成交换后，即处理好了的链表部分
    return next;
}
ListNode* reverseKGroup(ListNode* head, int ind) {
    int k=ind;
    ListNode * tail=head;
    ListNode * thisend=head;
    while(ind>0){
        if(tail==nullptr) return head;
        ind--;
        tail=tail->next;
    }//tail记录翻转最后一个节点的next节点
//    ListNode * nextStart=tail->next;
    ListNode * pl;
    ListNode * pm;
    ListNode * pr;
    
    pl=head; //p1记录翻转链表的起始点  tail记录翻转链表的终止点的next节点
    pm=pr=pl->next;
//中间部分的翻转
    while(pm!=tail){
        pr=pm->next;
        pm->next=pl;
        pl=pm;
        pm=pr;
    }
    head=pl;//head应该为tail
    thisend->next=reverseKGroup(tail, k);
    return head;
}


int main(){
    ListNode * head1= new ListNode(1);
    head1->next=new ListNode(2);
    head1->next->next=new ListNode(3);
    head1->next->next->next=new ListNode(4);
    head1->next->next->next->next=new ListNode(5);
    cout<<head1<<endl;
    cout<<reverseKGroup(head1, 1);
}
