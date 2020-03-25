//
//  二叉树-递归求总和相同路径-113.c
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
bool hasPathSum(TreeNode* root, int sum) {
    if(root==nullptr) return false;
    if(sum-root->val==0 and root->left==nullptr and root->right==nullptr) return true;
    return hasPathSum(root->left, sum-root->val) or hasPathSum(root->right, sum-root->val);
}
void pathSumProc(vector<vector<int>> &ans, vector<int> &subans,TreeNode* root,int sum){
    if(sum-root->val==0 and root->left==nullptr and root->right==nullptr){
        subans.push_back(root->val);
        ans.push_back(subans);
        subans.pop_back();
        return;
    }
    if(root->right!=nullptr){
        subans.push_back(root->val);
        pathSumProc(ans, subans, root->right, sum-root->val);
        subans.pop_back();
    }
    if(root->left!=nullptr){
        subans.push_back(root->val);
        pathSumProc(ans, subans, root->left, sum-root->val);
        subans.pop_back();
    }
    return;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>>  ans;
    if(root==nullptr) return ans;
    vector<int> subans;
    pathSumProc(ans, subans, root, sum);
}
