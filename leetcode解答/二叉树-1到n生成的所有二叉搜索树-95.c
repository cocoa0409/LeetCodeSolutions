//
//  二叉树-1到n生成的所有二叉搜索树-95.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * TreeDuplicate(TreeNode * head){
    TreeNode * anshead= new TreeNode(head->val);
    if(head->left!=nullptr) anshead->left=TreeDuplicate(head->left);
    if(head->right!=nullptr) anshead->right=TreeDuplicate(head->right);
    return anshead;
}
TreeNode * findParent(TreeNode * head,int curnum){
    TreeNode *tmp=head;
    while(1){
        assert(curnum!=tmp->val);
        if(curnum<tmp->val){
            if(tmp->left==nullptr){
                break;
            }
            else{
                tmp=tmp->left;
            }
        }
        else if(tmp->val<curnum){
            if(tmp->right==nullptr){
                break;
            }
            else{
                tmp=tmp->right;
            }
        }
    }
    return tmp;//tmp为curnum的父节点
}

TreeNode * TreeInsertProc(TreeNode * head,int curnum){
    TreeNode *tmp=findParent(head, curnum);
    if(tmp->val<curnum) tmp->right = new TreeNode(curnum);
    else tmp->left = new TreeNode(curnum);
    return tmp;//tmp为curnum的父节点
}

bool validiteration(int curnum,int nextnum,unordered_map<int, bool> &stat){
    if(curnum<nextnum) return true;
    int minv=INT_MAX;
    int maxv=INT_MIN;
    for(auto iter=stat.begin();iter!=stat.end();iter++){
        if(iter->first==curnum) continue;
        if(minv>iter->first) minv=iter->first;
        if(maxv<iter->first) maxv=iter->first;
    }
    if(maxv<nextnum or curnum<minv) return true;
    return false;
}

void generateTreesProc(vector<TreeNode*> &ans, TreeNode * head,int n,int curnum,int size,unordered_map<int, bool> &stat){
    assert(stat.count(curnum)==false);
    if(curnum>n or stat.count(curnum)==true) return;
    if(size==0){
        head=new TreeNode(curnum);//此curnum为头节点的情况
        stat[head->val] = true;//记录
        for(int i=1;i<=n;i++){
            if(stat.count(i)==false){
                generateTreesProc(ans, head, n, i, 1, stat);
            }
        }
        if(size+1==n){//输出步骤
            TreeNode * duphead=TreeDuplicate(head);
            ans.push_back(duphead);
        }
        stat.erase(head->val);//消除记录
        head=nullptr;
        generateTreesProc(ans, head, n, curnum+1, 0, stat);//下一个val为头节点的情况
    }
    else{
        TreeNode * curnumParent= TreeInsertProc(head, curnum);//将curnum加入至head的树中
        stat[curnum] = true;//记录
        for(int i=1;i<=n;i++){
//加入后续记录，此时需要考虑重复问题，观察到，3-1-2-5 与 3-1-5-2重复
//我们发现本步加入<下步加入时，正常处理即可；
//当本步加入>下步加入时，必须要保证   两个值在目前已经加入的节点集合的两端才导致不同效果
            if(stat.count(i)==false and ((curnum<i)or findParent(head, i)->val==curnum)){
                generateTreesProc(ans, head, n, i, size+1, stat);
            }
        }
        
        if(size+1==n){//输出步骤
            TreeNode * duphead=TreeDuplicate(head);
            ans.push_back(duphead);
        }
        
        if(curnum<curnumParent->val) {curnumParent->left=nullptr; delete curnumParent->left;}
        else{ curnumParent->right=nullptr; delete curnumParent->right;}
        stat.erase(curnum);//消除记录
    }
}


vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans;
    if(n==0) return ans;
    TreeNode * head=nullptr;
    unordered_map<int, bool> stat;
    generateTreesProc(ans, head, n, 1, 0, stat);
    return ans;
}

int main(){
    vector<TreeNode*> ans=generateTrees(4);
    cout<<ans.size();

}
