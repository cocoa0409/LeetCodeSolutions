void binaryProc(TreeNode * root, vector<string> & ans,string & curPath){
    if(root==nullptr) return;
    string thisNode="";
    if(curPath.size()!=0){
        thisNode="->"+to_string(root->val);
        curPath+=thisNode;
    }
    else{
        thisNode=to_string(root->val);
        curPath =thisNode;
    }
    if(root->left==nullptr and root->right==nullptr){
        ans.push_back(curPath);
    }
    else{
        if(root->left!=nullptr){
            binaryProc(root->left, ans, curPath);
        }
        if(root->right!=nullptr){
            binaryProc(root->right, ans, curPath);
        }
    }
    curPath=curPath.substr(0,curPath.size()-thisNode.size());
    return;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string curPath;
    binaryProc(root, ans, curPath);
    return ans;
}
