
//
//  动态规划 or 回溯法-交错字符串-97.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
ostream &operator<<(ostream &out, vector<bool>& nums){
    for(bool i:nums){
        out<<i<<" ";
    }
    out<<endl;
    return out;
}
ostream &operator<<(ostream &out,vector<vector<bool>>& board){
    for(vector<bool> i:board){
        out<<i<<endl;
    }
    return out;
}

//递归方法
bool isInterleave(string s1, string s2, string s3) {
    if(s1.size()==0) return s2==s3;
    if(s2.size()==0) return s1==s3;
    if(s1[0]==s2[0]){
        if(s1[0]==s3[0]) return isInterleave(s1.substr(1), s2, s3.substr(1)) or isInterleave(s1, s2.substr(1), s3.substr(1));
        else return false;
    }
    else{
        if(s1[0]==s3[0]) return isInterleave(s1.substr(1), s2, s3.substr(1));
        else if(s2[0]==s3[0]) return isInterleave(s1, s2.substr(1), s3.substr(1));
        else return false;
    }
}
//动态规划方法
bool isInterleave2(string s1, string s2, string s3) {
    if(s1==s2 and s2==s3 and s3=="") return true;
    if(s1=="") return s2==s3;
    if(s2=="") return s1==s3;
    if(s1.size()+s2.size() != s3.size())return false;

    vector<vector<bool>> ans(s1.size()+1,vector<bool>(s2.size()+1,false));
    for(int i=1;i<s1.size()+1;i++){
        if(s1.substr(0,i)==s3.substr(0,i)) ans[i][0]=true;
    }
    for(int j=1;j<s2.size()+1;j++){
        if(s2.substr(0,j)==s3.substr(0,j)) ans[0][j]=true;
    }
    
    for(int i=1;i<s1.size()+1;i++){
        for(int j=1;j<s2.size()+1;j++){
            if(s1[i-1]==s3[i+j-1] and ans[i-1][j]==true) {ans[i][j]=true; continue;}
            if(s2[j-1]==s3[i+j-1] and ans[i][j-1]==true) {ans[i][j]=true; continue;}
        }
    }
    return ans[s1.size()][s2.size()];
}
int main(){
    cout<<isInterleave2("aabcc", "dbbca", "aadbbcbcac");
    
}

