//
//  链表-深拷贝-将复制的节点放到原节点旁边-138.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head)
{
    //O(1)空间的迭代
    Node* ptr=head;
    Node* medium=NULL;
    if(head == NULL)
        return NULL;
    //创建相邻结点
    while(ptr != NULL)
    {
        medium=ptr->next;
        ptr->next=new Node(ptr->val);//ptr后创建新结点
        ptr->next->next=medium;
        ptr=ptr->next->next;
    }
    //遍历新链表，修改新结点的random指针
    ptr=head;
    while(ptr != NULL)
    {
        if(ptr->random != NULL)
        {
            ptr->next->random=ptr->random->next;
        }
        else
        {
            ptr->next->random=NULL;
        }
        ptr=ptr->next->next;
    }
    //修改链表结构(这个地方没有学懂，抄的官方题解)
    Node* ptr_old_list=head;
    Node* ptr_new_list=head->next;
    Node *result=head->next;
    while(ptr_old_list != NULL)
    {
        ptr_old_list->next=ptr_old_list->next->next;
        if(ptr_new_list->next != NULL)
            ptr_new_list->next=ptr_new_list->next->next;
        else
            ptr_new_list->next=NULL;
        ptr_old_list=ptr_old_list->next;
        ptr_new_list=ptr_new_list->next;
    }
    return result;
} 
