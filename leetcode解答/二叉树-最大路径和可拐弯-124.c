//
//  二叉树-最大路径和可拐弯-124.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/28.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> maxPathSumProc(TreeNode* root,int & curMax){
    if(root==nullptr) return pair<int, int>(INT_MIN, INT_MIN);
    pair<int, int> left=maxPathSumProc(root->left, curMax);
    pair<int, int> right=maxPathSumProc(root->right, curMax);
    pair<int, int> rootans;
    if(root->left==nullptr) rootans.first=root->val;
    else{
        if(max(left.first,left.second)<=0) rootans.first=root->val;
        else if(left.first>left.second) rootans.first=root->val+left.first;
        else rootans.first=root->val+left.second;
    }
    if(root->right==nullptr) rootans.second=root->val;
    else{
        if(max(right.first,right.second)<=0) rootans.second=root->val;
        else if(right.first>right.second) rootans.second=root->val+right.first;
        else rootans.second=root->val+right.second;
    }
    int rootMax=rootans.first+rootans.second-root->val;
    if(rootMax>curMax) curMax=rootMax;
    return rootans;
}

int maxPathSum(TreeNode* root) {
    int Max=INT_MIN;
    maxPathSumProc(root, Max);
    return Max;
}

