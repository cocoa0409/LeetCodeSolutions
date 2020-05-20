struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr) return nullptr;
    TreeNode * newroot= new TreeNode(root->val);
    newroot->left=invertTree(root->right);
    newroot->right=invertTree(root->left);
    return newroot;
}
