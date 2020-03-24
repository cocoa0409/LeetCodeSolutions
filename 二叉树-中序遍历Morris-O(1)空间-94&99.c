//
//  二叉树-中序遍历Morris-O(1)空间-94&99.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.

/*
 
 Morrise中序遍历
 
 
 我们知道，左子树最后遍历的节点一定是一个叶子节点，它的左右孩子都是 null，我们把它右孩子指向当前根节点存起来，这样的话我们就不需要额外空间了。这样做，遍历完当前左子树，就可以回到根节点了。

 当然如果当前根节点左子树为空，那么我们只需要保存根节点的值，然后考虑右子树即可。

 所以总体思想就是：记当前遍历的节点为 cur。

 1、cur.left 为 null，保存 cur 的值，更新 cur = cur.right

 2、cur.left 不为 null，找到 cur.left 这颗子树最右边的节点记做 last

 2.1 last.right 为 null，那么将 last.right = cur，更新 cur = cur.left

 2.2 last.right 不为 null，说明之前已经访问过，第二次来到这里，表明当前子树遍历完成，保存 cur 的值，更新 cur = cur.right
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;  // 游标
    while(cur != NULL){
        if(cur->left != NULL){  // 进入左子树
            // 找到cur的前驱结点，分两种情况
            // 1、cur的左子结点没有右子结点，那cur的左子结点就是前驱
            // 2、cur的左子结点有右子结点，就一路向右下，走到底就是cur的前驱
            TreeNode* predecessor = cur->left;
            while(predecessor->right != NULL && predecessor->right != cur){
                predecessor = predecessor->right;
            }

            // 前驱还没有指向自己，说明左边还没有遍历，将前驱的右指针指向自己，后进入cur->left
            if(predecessor->right == NULL){
                predecessor->right = cur;
                cur = cur->left;
            }else{
                // 前驱已经指向自己了，说明cur的左子树遍历完毕
                ans.push_back(cur->val);
                //恢复前驱的右指针
                predecessor->right = NULL;
                //进入cur->right
                cur = cur->right;
            }
        }else{  // 左子树为空时，记录，然后进入右子树
            ans.push_back(cur->val);
            cur = cur->right;
        }
    }
    return ans;
}
