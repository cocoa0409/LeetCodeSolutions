//
//  二叉树-中序遍历-递归-迭代-94.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//


#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归算法
void inorderTraversalPrc(vector<int> &ans, TreeNode* root){
    if(root==nullptr) return;
    inorderTraversalPrc(ans,root->left);
    ans.push_back(root->val);
    inorderTraversalPrc(ans, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorderTraversalPrc(ans, root);
    return ans;
}

//迭代算法
vector<int> inorderTraversal2(TreeNode* root) {
    vector<int> ans;
    vector<TreeNode *> stack;
    TreeNode * tmp=root;
    while(1){
        while(tmp!=nullptr){
            stack.emplace_back(tmp);
            tmp=tmp->left;
        }
        if(stack.size()==0) return ans;
        tmp=stack.back();
        stack.pop_back();
        tmp=tmp->right;
    }
}


int main(){

}
