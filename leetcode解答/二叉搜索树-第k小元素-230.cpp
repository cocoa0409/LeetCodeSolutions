struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<bool,int> kthSmallestProc(TreeNode* root, int k){
    if(root==nullptr) return{false,0};
    auto lRes=kthSmallestProc(root->left, k);
    decltype(lRes) rRes;
    if(lRes.first==true) return {true,lRes.second};
    else{
        if(lRes.second==k-1) return {true,root->val};
        
        rRes=kthSmallestProc(root->right, k-lRes.second-1);
        
        if(rRes.first==true) return {true,rRes.second};
        else{
            return {false,lRes.second+1+rRes.second};
        }
    }
}

int kthSmallest(TreeNode* root, int k) {
    auto Res=kthSmallestProc(root, k);
    return Res.second;
}
