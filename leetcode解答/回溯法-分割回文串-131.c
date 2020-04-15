//
//  回溯法-分割回文串-131.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/13.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

bool justify(string s,int b,int e){
    while(b<e){
        if(s[b]!=s[e])
            return false;
        else{
            b++;e--;
        }
    }
    return true;
}

vector<string> genpartition(string s,vector<int> & _cres){
    vector<string> _subres;
    int begin=0;
    for(int next:_cres){
        _subres.emplace_back(s.begin()+begin,s.begin()+next+1);
        begin=next+1;
    }
    return _subres;
}


void partitionProc(string s,vector<vector<string>>& _res,vector<vector<int>> &_pstat,vector<int> & _cres,int beginidx,int endindex){
    if(beginidx==endindex+1){
        _res.emplace_back(genpartition(s, _cres));
        return;
    }
    
    if(_pstat[beginidx].size()==0) return;
    
    for(int nextidx:_pstat[beginidx]){
        _cres.insert(_cres.end(), nextidx);//加入此nextidx
        partitionProc(s,_res, _pstat, _cres, nextidx+1, endindex);
        _cres.erase(_cres.end()-1);//删除此nextidx
    }
    
    
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> _res;
    if(s.size()==0) return _res;
    
    vector<vector<int>> _pstat(s.size());
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(s[i]==s[j]){
                if(justify(s, i, j)){
                    _pstat[i].push_back(j);
                }
            }
        }
    }
    vector<int> _cres;
    partitionProc(s, _res, _pstat, _cres, 0, s.size()-1);
    return _res;
    
}

int main(){
    vector<int> a{1,2,3,4,5,6};
    a.erase(a.end()-1);
    cout<<a.back();
    
    
    
    string s="aab";
    partition(s);

}
