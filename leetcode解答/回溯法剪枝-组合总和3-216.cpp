int RestMaxSum(int restk){
    int res=(9+(10-restk))*restk/2;
    return res;
}


void combinationSum3Proc(vector<vector<int>> & res,vector<int> & cur,int & k,int & n){
    int curSum=accumulate(cur.begin(), cur.end(), 0);
    
    if(curSum > n) return;
    
    if(cur.size()==k){
        if(curSum==n){
            res.push_back(cur);
            return;
        }
        else{
            return;
        }
    }
    
    if(curSum + RestMaxSum(k-cur.size()) <n)
        return;
    
    int curBack;
    if(cur.size()==0) curBack=0;
    else curBack=cur.back();
    
    for(auto i=curBack+1;i<=10-(k-cur.size());i++){
        cur.push_back(i);
        combinationSum3Proc(res, cur, k, n);
        cur.pop_back();
    }
    return;
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    combinationSum3Proc(res, cur, k, n);
    return res;
}
