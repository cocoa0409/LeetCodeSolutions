//
//  二叉树-后序、中序恢复树-106.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/25.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
/*
 从后序最后一个元素提取关键节点，这个节点是子树的root节点
 根据root节点在中序中划分元素个数，然后递归（分治）
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * buildTreeProc(vector<int>& postorder, vector<int>& inorder,int pl,int pr,int il,int ir){
    if(postorder.size()==0 and inorder.size()==0) return nullptr;
    
    TreeNode * thisnode=new TreeNode(postorder[pr]);
    int i;
    for(i=il;i<=ir;i++){
        if(inorder[i]==postorder[pr]) break;
    }
    int rightcount=ir-i;
    int leftcount=i-il;
    if(i==il) thisnode->left=nullptr;
    else{
        thisnode->left=buildTreeProc(postorder,inorder,pl,pl+leftcount-1,il,il+leftcount-1);
    }
    if(i==ir) thisnode->right=nullptr;
    else{
        thisnode->right=buildTreeProc(postorder,inorder,pl+leftcount,pr-1,il+leftcount+1,ir);
    }
    return thisnode;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size()==0 and inorder.size()==0) return nullptr;
    return buildTreeProc(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);

}
int main(){
    vector<int> pos{9,15,7,20,3};
    vector<int> in{9,3,15,20,7};
    buildTree(pos, in);
    
}
