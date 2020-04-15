//
//  二叉树-验证镜像树-中序遍历-迭代-递归-101.c
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
//判断两棵树是否相等
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr and q==nullptr) return true;
    else if(p==nullptr or q==nullptr) return false;
    if(p->val!=q->val) return false;
    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    
}



//迭代方法
bool isSymmetric(TreeNode* root) {
    if(root==nullptr) return true;
    vector<TreeNode *> Stack;
    vector<TreeNode *> Stackmirror;
    TreeNode * cur=root;
    TreeNode * curmirror=cur;
    while(true){
        while(cur!=nullptr){
            Stack.push_back(cur);
            Stackmirror.push_back(curmirror);
            if(curmirror==nullptr) return false;
            cur=cur->left;
            curmirror=curmirror->right;
        }
        if(curmirror!=nullptr) return false;
        cur=Stack.back();
        Stack.pop_back();
        curmirror=Stackmirror.back();
        Stackmirror.pop_back();
        if(cur==curmirror) return true;
        if(cur->val!=curmirror->val) return false;
        cur=cur->right;
        curmirror=curmirror->left;
    }
    return true;
}
//递归方法
bool isSymmetric(TreeNode* root) {
    return ismirror(root,root);
}

bool ismirror(TreeNode* p,TreeNode* q){
    if(!p&&!q)//都为NULL
        return true;
    if(!p||!q)//有一个为NULL
        return false;
    if(p->val==q->val)
        return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
    return false;
}
