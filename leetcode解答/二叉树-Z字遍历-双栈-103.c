//
//  二叉树-Z字遍历-双栈-103.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    stack<TreeNode*> S1,S2;
    TreeNode * tmp;
    S1.push(root);
    while(1){
        vector<int> subans;
        while(S1.size()!=0){
            tmp=S1.top();
            S1.pop();
            if(tmp->left!=nullptr) S2.push(tmp->left);
            if(tmp->right!=nullptr) S2.push(tmp->right);
            subans.push_back(tmp->val);
        }
        ans.push_back(subans);
        if(S1.size()==0 and S2.size()==0) return ans;
        
        subans.clear();
        while(S2.size()!=0){
            tmp=S2.top();
            S2.pop();
            if(tmp->right!=nullptr) S1.push(tmp->right);
            if(tmp->left!=nullptr) S1.push(tmp->left);
            subans.push_back(tmp->val);
        }
        ans.push_back(subans);
        if(S1.size()==0 and S2.size()==0) return ans;
    }
}
