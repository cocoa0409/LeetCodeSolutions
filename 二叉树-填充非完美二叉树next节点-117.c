//
//  二叉树-填充非完美二叉树next节点-117.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/27.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
/*
 本质的思想是利用已经建立的上层next节点，获取当前层节点的next节
               __     ->     __
             /   \         /    \
          __->  __  ->  __  “->”  __
         /                         \
        *                          this
 建立的时候一定要先递归右子树，否则左子树的上层next关系构造是不完整的“->”构造不出来
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/**
   * 一路向右找到有子节点的根节点
   */
Node* getNextNoNULLChild(Node * root){
    Node * tmp;
    tmp=root->next;
    while(tmp!=nullptr){
        if(tmp->left!=nullptr) return tmp->left;
        if(tmp->right!=nullptr) return tmp->right;
        tmp=tmp->next;
    }
    return nullptr;
}

Node* connect(Node* root) {
    if(root==nullptr or (root->left==nullptr and root->right==nullptr)) return root;
    if(root->left!=nullptr and root->right!=nullptr) {
        root->left->next=root->right;
        root->right->next=getNextNoNULLChild(root);
    }
    else if(root->left!=nullptr) root->left->next=getNextNoNULLChild(root);
    else root->right->next=getNextNoNULLChild(root);
    //这里要注意：先递归右子树，否则右子树根节点next关系没建立好，左子树到右子树子节点无法正确挂载
    connect(root->right);
    connect(root->left);
    return root;
}
