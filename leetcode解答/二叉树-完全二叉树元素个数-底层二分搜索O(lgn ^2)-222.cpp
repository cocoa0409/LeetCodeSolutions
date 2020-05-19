struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode * root) {
    if(root==nullptr) return 0;
    int layer=1;
    
    TreeNode * it=root;
    while(it->right!=nullptr){
        it=it->right;
        layer++;
    }
    //此时layer记录的是完全二叉树的完整层 2^layer -1 个
    
    //二分搜索
    int minT=0;
    int maxT=pow(2,layer);
    while(minT<maxT){
        int midT=(minT+maxT)/2;
        //根据midT顺树根向下找
        it=root;
        int accumulate=0;
        for(auto j=1;j<=layer;j++){
            if(midT<accumulate+pow(2,layer-j)){
                it=it->left;
            }
            else{
                it=it->right;
                accumulate+=pow(2,layer-j);
            }
        }
        if(it==nullptr){
            maxT=midT;
        }
        else{
            minT=midT+1;
        }
    }
    assert(minT==maxT);
    return pow(2,layer)-1+minT;
}
