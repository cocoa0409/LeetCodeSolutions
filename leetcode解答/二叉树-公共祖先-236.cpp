struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr) return nullptr;

    if(root==p) return p;
    else if(root==q) return q;
    else{
        TreeNode * l=lowestCommonAncestor(root->left, p, q);
        TreeNode * r=lowestCommonAncestor(root->right, p, q);
        if((l==p and r==q) or (l==q and r==p)) return root;
        else{
            if(l!=nullptr) return l;
            if(r!=nullptr) return r;
        }
    }
    return nullptr;
}
