//
//  main.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/7.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
//还可以用优先队列-- 堆！！！！！！！ 在O（nlgk）时间内解决
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ostream &operator<<(ostream &out, ListNode * head){
    out<<"start :";
    while(head!=nullptr){
        out<<head->val<<"--";
        head=head->next;
    }
    return out;
}

void mergeProc(vector<ListNode*> & ind,ListNode * cur){
    int i,tmp;
    for(i=0;i<ind.size();i++){
        if(ind[i]!=NULL){
            cur->next =ind[i];
            break;
        }
    }
    if(cur->next==NULL)
        return;
    else{
        for(i=0;i<ind.size();i++){
            if(ind[i]!=NULL and ind[i]->val <= cur->next->val){
                cur->next=ind[i];
                tmp=i;
            }
        }
        ind[tmp]=ind[tmp]->next;
        cur=cur->next;
        mergeProc(ind, cur);
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0 ){
        return NULL;
    }
    else if(lists.size()==1){
        return lists[0];
    }
    ListNode * cur= new ListNode(INT_MIN);
//    vector<ListNode*> ind=lists;
    mergeProc(lists, cur);
    return cur->next;

}

int main(){
    vector<ListNode*> test;
    ListNode * head1= new ListNode(1);
    head1->next=new ListNode(4);
    head1->next->next=new ListNode(5);
    
    ListNode * head2= new ListNode(1);
    head2->next=new ListNode(3);
    head2->next->next=new ListNode(4);
    
    ListNode * head3= new ListNode(2);
    head3->next=new ListNode(6);
    
    test.push_back(head1);
    test.push_back(head2);
    test.push_back(head3);
    
//    ListNode * cur;
//    cur->next=test[0];
    ListNode * ans = mergeKLists(test);
    cout<<ans;

}
