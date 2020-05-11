struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    TreeNode * node =root;
    TreeNode * tmp;
    while(node!=nullptr){
        if(node->left==nullptr){
            res.push_back(node->val);
            node=node->right;
            continue;
        }
        else{
            tmp=node->left;
            while(tmp->right!=nullptr){
                if(tmp->right==node){
                    break;
                }
                tmp=tmp->right;
            }
            if(tmp->right==node) {
                tmp->right=nullptr;
                node=node->right;
                continue;
            }
            else{
                res.push_back(node->val);
                tmp->right=node;
                node=node->left;
            }
            
        }
    }
    return res;
}
