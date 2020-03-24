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
void inorderTraversalProc(vector<int> &ans, TreeNode* root){
    if(root==nullptr) return;
    inorderTraversalProc(ans,root->left);
    ans.push_back(root->val);
    inorderTraversalProc(ans, root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorderTraversalProc(ans, root);
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
        ans.push_back(tmp->val);
        tmp=tmp->right;
    }
}

//Morrise中序遍历
/*
 我们知道，左子树最后遍历的节点一定是一个叶子节点，它的左右孩子都是 null，我们把它右孩子指向当前根节点存起来，这样的话我们就不需要额外空间了。这样做，遍历完当前左子树，就可以回到根节点了。

 当然如果当前根节点左子树为空，那么我们只需要保存根节点的值，然后考虑右子树即可。

 所以总体思想就是：记当前遍历的节点为 cur。

 1、cur.left 为 null，保存 cur 的值，更新 cur = cur.right

 2、cur.left 不为 null，找到 cur.left 这颗子树最右边的节点记做 last

 2.1 last.right 为 null，那么将 last.right = cur，更新 cur = cur.left

 2.2 last.right 不为 null，说明之前已经访问过，第二次来到这里，表明当前子树遍历完成，保存 cur 的值，更新 cur = cur.right
 */

int main(){

}
