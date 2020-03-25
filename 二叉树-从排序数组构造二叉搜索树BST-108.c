//
//  二叉树-从排序数组构造二叉搜索树BST-108.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/25.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
TreeNode* sortedArrayToBSTProc(vector<int>& nums,int begin,int end) {
    if(begin>end) return nullptr;
    else if(begin==end) return new TreeNode(nums[begin]);
    
    int mid=(begin+end)/2;
    TreeNode * midNode= new TreeNode(nums[mid]);
    midNode->left=sortedArrayToBSTProc(nums, begin, mid-1);
    midNode->right=sortedArrayToBSTProc(nums, mid+1, end);
    return midNode;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size()==0) return nullptr;
    return sortedArrayToBSTProc(nums, 0, nums.size()-1);
}
