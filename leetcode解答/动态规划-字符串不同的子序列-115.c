//
//  动态规划-字符串不同的子序列-115.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/26.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int numDistinct(string s, string t) {
    if(s.size()<t.size()) return 0;
    if(t.size()==0)return 0;
    vector<vector<long>> M(t.size()+1,vector<long>(s.size()+1,0));
    unordered_map<char, vector<int>> sStat;
    for(int i=0;i<s.size();i++){
        sStat[s[i]].push_back(i);
    }
    for(int j=0;j<s.size()+1;j++) M[0][j]=1;
    for(int i=1;i<t.size()+1;i++){
        for(int j=i;j<s.size()+1;j++){
            if(t[i-1]!=s[j-1]){
                for(int pos:sStat[t[i-1]]){
                    if(pos<=j-1) M[i][j]+=M[i-1][pos];
                    else break;
                }
            }
            else{
                M[i][j]=M[i-1][j-1]+M[i][j-1];
            }
        }
    }
    return M[t.size()][s.size()];
}


int numDistinct(string s, string t) {
    if(s.size()<t.size()) return 0;
    if(t.size()==0)return 0;
    vector<vector<long>> M(t.size()+1,vector<long>(s.size()+1,0));
    // unordered_map<char, vector<int>> sStat;
    // for(int i=0;i<s.size();i++){
    //     sStat[s[i]].push_back(i);
    // }
    for(int j=0;j<s.size()+1;j++) M[0][j]=1;
    for(int i=1;i<t.size()+1;i++){
        for(int j=i;j<s.size()+1;j++){
            if(t[i-1]!=s[j-1]){
            //     for(int pos:sStat[t[i-1]]){
            //         if(pos<=j-1) M[i][j]+=M[i-1][pos];
            //         else break;
            //     }
            M[i][j]=M[i][j-1];
            }
            else{
                M[i][j]=M[i-1][j-1]+M[i][j-1];
            }
        }
    }
    return M[t.size()][s.size()];
}
