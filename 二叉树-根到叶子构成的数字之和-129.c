//
//  二叉树-根到叶子构成的数字之和-129.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/13.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNumbers(TreeNode* root) {
    if(root==nullptr) return 0;
    
    int _Sum=0;
    queue<pair<TreeNode*, int>> Q;
    Q.push({root,root->val});
    while(!Q.empty()){
        pair<TreeNode*, int> _Node=Q.front();
        Q.pop();
        if(_Node.first->left==nullptr and _Node.first->right==nullptr)
            _Sum += _Node.second;
        else{
            if(_Node.first->left!=nullptr)
                Q.push({_Node.first->left,_Node.second*10+_Node.first->left->val});
            if(_Node.first->right!=nullptr)
                Q.push({_Node.first->right,_Node.second*10+_Node.first->right->val});
        }
    }
    return _Sum;
}
