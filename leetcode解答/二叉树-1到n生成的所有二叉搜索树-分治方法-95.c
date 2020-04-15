//
//  二叉树-1到n生成的所有二叉搜索树-分治方法-95.c
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
vector<TreeNode*> generateTreesProc(int begin,int end){
    if(begin>end) return vector<TreeNode*>(1,nullptr);
    if(begin==end) return vector<TreeNode*>(1,new TreeNode(begin));
    vector<TreeNode*> ans;
    vector<TreeNode*> left,right;
    for(int i=begin;i<=end;i++){
        left=generateTreesProc(begin, i-1);
        right=generateTreesProc(i+1, end);
        for(int m=0;m<left.size();m++){
            for(int n=0;n<right.size();n++){
                TreeNode* thisi=new TreeNode(i);
                thisi->left=left[m];
                thisi->right=right[n];
                ans.push_back(thisi);
            }
        }
    }
    return ans;
}


vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans = generateTreesProc(1, n);
    return ans;
}
