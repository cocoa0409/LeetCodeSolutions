//
//  main.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/7.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
ostream &operator<<(ostream &out, vector<int>& nums){
    for(int i:nums){
        out<<i<<" ";
    }
    out<<endl;
    return out;
}
ostream &operator<<(ostream &out,vector<vector<int>>& board){
    for(vector<int> i:board){
        out<<i<<endl;
    }
    return out;
}

bool isMatch(string s, string p) {
    int psiz=p.size();
    int ssiz=s.size();
    vector<vector<bool>>dp(psiz+1,vector<bool>(ssiz+1,false));
    dp[0][0]=true;
    for(int i=1;i<=psiz;i++){
        if(p[i-1]=='*' and dp[i-1][0]==true ) dp[i][0]=true;
        for(int j=1;j<=ssiz;j++){
            if(p[i-1]=='?') dp[i][j]=dp[i-1][j-1]; //?匹配任意单个字符
            else if(p[i-1]=='*') dp[i][j]=(dp[i-1][j] or dp[i][j-1] or dp[i-1][j-1]);//*匹配任意字符串
            else{
                if(p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=false;
            }
        }
    }
    return dp[psiz][ssiz];

}



int main(){
    cout<<isMatch("adceb", "*a*b");
}
