//
//  二叉树-从排序链表构造二叉树BST-109.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/25.
//  Copyright © 2020 兆吉 王. All rights reserved.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* sortedListToBSTProc(ListNode* head,ListNode* end){
    if(head==end) return nullptr;
    ListNode * sp=head;
    ListNode * fp=head;
    while(fp!=end){
        fp=fp->next;
        if(fp==end) break;
        sp=sp->next;
        fp=fp->next;
    }
    TreeNode * midNode=new TreeNode(sp->val);
    midNode->left=sortedListToBSTProc(head, sp);
    midNode->right=sortedListToBSTProc(sp->next, end);
    return midNode;
}


TreeNode* sortedListToBST(ListNode* head) {
    return sortedListToBSTProc(head, nullptr);
}
