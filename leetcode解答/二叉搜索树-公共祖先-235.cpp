struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode * sp=root;
    while(true){
        if(sp==p or sp==q) return sp;
        else if((p->val - sp->val) * (q->val - sp->val) < 0 ) return sp;
        else{
            if(p->val < sp->val) sp=sp->left;
            else sp=sp->right;
        }
    }
    return nullptr;
}
