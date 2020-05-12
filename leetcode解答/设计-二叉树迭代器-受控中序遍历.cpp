//
//  设计-二叉树迭代器-受控中序遍历.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/5/12.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

class BSTIterator {
public:
    stack<TreeNode *> InorderProc;
    
    BSTIterator(TreeNode * root) {
        InorderProc.push(root);
        while(InorderProc.size()!=0 and InorderProc.top()!=nullptr){
            TreeNode * tnode=InorderProc.top();
            InorderProc.pop();
            if(tnode->right!=nullptr){
                InorderProc.push(tnode->right);
            }
            InorderProc.push(tnode);
            InorderProc.push(nullptr);
            if(tnode->left!=nullptr){
                InorderProc.push(tnode->left);
            }
        }
        if(InorderProc.size()!=0) InorderProc.pop();
    }

    /*@return the next smallest number */
    int next() {
        int ans = InorderProc.top()->val;
        InorderProc.pop();
        while(InorderProc.size()!=0 and InorderProc.top()!=nullptr){
            TreeNode * tnode=InorderProc.top();
            InorderProc.pop();
            if(tnode->right!=nullptr){
                InorderProc.push(tnode->right);
            }
            InorderProc.push(tnode);
            InorderProc.push(nullptr);
            if(tnode->left!=nullptr){
                InorderProc.push(tnode->left);
            }
        }
        if(InorderProc.size()!=0) InorderProc.pop();
        
        return ans;
    }
    /*@return whether we have a next smallest number */
    bool hasNext() {
        return !(InorderProc.size()==0);
    }
};
