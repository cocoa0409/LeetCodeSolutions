//
//  二叉树-展开为右链表-114.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/26.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void flatten(TreeNode* root) {
    if(root==nullptr) return;
    if(root->left==nullptr and root->right==nullptr) return;
    if(root->left!=nullptr and root->right!=nullptr){
        flatten(root->left);
        flatten(root->right);
        TreeNode * l=root->left;
        TreeNode * lend=root->left;
        while(lend->right !=nullptr){
            lend=lend->right;
        }
        TreeNode * r=root->right;
        root->right=l;
        root->left=nullptr;
        lend->right=r;
        return;
    }
    if(root->left==nullptr){flatten(root->right); return;}
    if(root->right==nullptr){
        flatten(root->left);
        root->right=root->left;
        root->left=nullptr;
        return;
    }
}
