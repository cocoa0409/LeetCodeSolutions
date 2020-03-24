//
//  二叉树-按层遍历-队列-102.c
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<TreeNode*> q1;
    TreeNode * tmp;
    q1.push(root);
    while(1){
        int num=q1.size();
        if(num==0) return ans;
        vector<int> subans;
        for(int i=0;i<num;i++){
            tmp=q1.front();
            q1.pop();
            if(tmp->left!=nullptr) q1.push(tmp->left);
            if(tmp->right!=nullptr) q1.push(tmp->right);
            subans.push_back(tmp->val);
        }
        ans.push_back(subans);
    }
}

