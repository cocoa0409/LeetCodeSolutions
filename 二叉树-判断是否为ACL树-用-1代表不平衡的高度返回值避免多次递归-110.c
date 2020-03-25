//
//  二叉树-判断是否为ACL树-用-1代表不平衡的高度返回值避免多次递归-110.c
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

int heightProc(TreeNode * root){
    if(root==nullptr) return 0;
    int left=heightProc(root->left);
    int right=heightProc(root->right);
    if(left==-1 or right==-1) return -1;
    if(abs(left-right)<=1) return max(left,right)+1;
    else return -1;
}
bool isBalanced(TreeNode* root) {
    return heightProc(root)!=-1;
}
