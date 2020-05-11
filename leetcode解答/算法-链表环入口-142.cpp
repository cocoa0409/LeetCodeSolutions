//
//  算法-链表环入口.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

/*
双指针法 or hash表法 判断链表中是否有环

Floyd算法判断环的入口:
 从head到入口走F次跳跃，从入口到第一次相遇走a次跳跃，从第一次相遇到环的入口走b次跳跃
 设环共C次跳跃
 
 F+a (mod C)= 2(F+a) (mod C)
 0 = F+a (mod C)
 0 = F+a-C (mod C)
 0 = F-b (mod C)
 F= xC + b
 
 所以在确定第一次的相遇点后，将slow归head，fast与slow同步取next直到相遇即可
 
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

bool hasCycle(ListNode *head) {
    if(head==nullptr||head->next==nullptr) return false;
    ListNode *fast=head->next;
    ListNode *slow=head;
    while(1){
        if(fast==slow) return true;
        
        if(fast==nullptr || fast->next==nullptr) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
}
ListNode *detectCycle(ListNode *head) {
    if(head==nullptr) return nullptr;
    unordered_map<ListNode*, bool> fp;
    ListNode* pt=head;
    while(1){
        if(fp.count(pt)!=0) return pt;
        fp[pt]=true;
        if(pt->next==nullptr) return nullptr;
        pt=pt->next;
    }
}
ListNode *detectCycleFloyd(ListNode *head) {
    if(head==nullptr||head->next==nullptr) return nullptr;
    ListNode *fast=head;
    ListNode *slow=head;
    while(1){
        if(fast==nullptr || fast->next==nullptr) return nullptr;
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            break;//第一次相遇后 break
        }
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
