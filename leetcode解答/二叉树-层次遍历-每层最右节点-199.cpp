struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    queue<TreeNode *> Q;
    Q.push(root);
    
    TreeNode * tmp;
    int count=1;
    int nextcount=0;
    while(Q.size()!=0){
        tmp=Q.front();
        Q.pop();
        count--;
        if(tmp->left!=nullptr){
            Q.push(tmp->left);
            nextcount++;
        }
        if(tmp->right!=nullptr){
            Q.push(tmp->right);
            nextcount++;
        }
        
        if(count==0){
            res.push_back(tmp->val);
            count=nextcount;
            nextcount=0;
        }
    }
    return res;
}
