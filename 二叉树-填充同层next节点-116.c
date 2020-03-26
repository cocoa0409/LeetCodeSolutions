//
//  二叉树-填充同层next节点-116.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/26.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

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
//拉拉链方法
Node* connect(Node* root) {
    if(root==nullptr) return root;
    connect(root->left);
    connect(root->right);
    Node * left=root->left;
    Node * right=root->right;
    while(left!=nullptr){
        left->next=right;
        left=left->right;
        right=right->left;
    }
    return root;
}
//层次遍历方法
Node* connect2(Node* root){
    if(root==nullptr) return root;
    queue<Node*> Q;
    Q.push(root);
    int roundnum=Q.size();
    Node * r;
    Node * l=nullptr;
    while(roundnum!=0){
        l=nullptr;
        r=nullptr;
        for(int i=roundnum;i>0;i--){
            l=Q.front();
            Q.pop();
            
            if(l->left!=nullptr){
                Q.push(l->right);
                Q.push(l->left);
            }
            if(r!=nullptr){
                l->next=r;
            }
            r=l;
        }
        roundnum=Q.size();
    }
    return root;
}
