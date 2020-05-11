struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    TreeNode * node =root;
    TreeNode * tmp;
    while(node!=nullptr){
        if(node->right==nullptr){
            res.push_back(node->val);
            node=node->left;
            continue;
        }
        else{
            tmp=node->right;
            while(tmp->left!=nullptr){
                if(tmp->left==node){
                    break;
                }
                tmp=tmp->left;
            }
            if(tmp->left==node) {
                tmp->left=nullptr;
                node=node->left;
                continue;
            }
            else{
                res.push_back(node->val);
                tmp->left=node;
                node=node->right;
            }
            
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}
