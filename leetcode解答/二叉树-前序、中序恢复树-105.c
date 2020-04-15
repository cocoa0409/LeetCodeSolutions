//
//  二叉树-前序、中序恢复树-105.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
/*
从前序第一个元素提取关键节点，这个节点是子树的root节点
根据root节点在中序中划分元素个数，然后递归（分治）
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * buildTreeProc(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
    if(preorder.size()==0 and inorder.size()==0) return nullptr;
    
    TreeNode * thisnode=new TreeNode(preorder[pl]);
    int i;
    for(i=il;i<=ir;i++){
        if(inorder[i]==preorder[pl]) break;
    }
    int rightcount=ir-i;
    int leftcount=i-il;
    if(i==il) thisnode->left=nullptr;
    else{
        thisnode->left=buildTreeProc(preorder,inorder,pl+1,pl+leftcount,il,il+leftcount-1);
    }
    if(i==ir) thisnode->right=nullptr;
    else{
        thisnode->right=buildTreeProc(preorder,inorder,pl+leftcount+1,pr,il+leftcount+1,ir);
    }
    return thisnode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0 and inorder.size()==0) return nullptr;
    return buildTreeProc(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

}
