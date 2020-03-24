//
//  二叉树-验证二叉搜索树-98.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 递归验证，需要注意必须限制每棵树的上下界，否则
            5
           / \
          3   9
             / \
            2   10
也可通过
 */
bool isValidBSTProc(TreeNode* root,long lth,long rth){
    if(root==nullptr) return true;
    if(root->val <= lth or root->val >= rth) return false;
    return isValidBSTProc(root->left,lth,root->val) and isValidBSTProc(root->right,root->val,rth);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTProc(root,LONG_MIN,LONG_MAX);
}

/*
 二叉搜索树的特点：中序遍历为升序
 */
void inorderTraversalProc(vector<int> &ans, TreeNode* root){
    if(root==nullptr) return;
    inorderTraversalProc(ans,root->left);
    ans.push_back(root->val);
    inorderTraversalProc(ans, root->right);
}
bool isValidBST(TreeNode* root) {
    vector<int> ans;
    inorderTraversalProc(ans, root);
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>=ans[i+1]) return false;
    }
    return true;
}
