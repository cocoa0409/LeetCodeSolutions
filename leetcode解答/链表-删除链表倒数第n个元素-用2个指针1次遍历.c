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
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
//维持2个指针,p1,pn,
    ListNode* p1;
    ListNode* pn;
    p1=pn=head;
    while(n-1!=0){
        pn=pn->next;
        n--;
    }
    
    ListNode *p1_pre=NULL;
    while(pn->next!=NULL){
        p1_pre=p1;
        p1=p1->next;
        pn=pn->next;
    }
    //删除p1 第一种情况 p1为head
    if(p1_pre==NULL){
        assert(p1==head);
        head=head->next;
    }
    else{
        p1_pre->next=p1->next;
    }
    return head;
    
    
}



int main(){
    vector<int> a={-1,0,-5,-2,-2,-4,0,1,-2};
    fourSum(a, -9);
}
