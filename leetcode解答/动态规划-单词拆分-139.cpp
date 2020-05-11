//
//  动态规划-单词拆分-139.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
/*
 动态规划的思想是以空间换时间
 记录下部分子问题的解
 */
bool wordBreakjudge(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1,false);
    dp[0]=true;
    for(auto i=1;i!=s.size()+1;i++){
        for(auto j=i-1;j!=-1;j--){
            if(dp[j]==true and find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                dp[i]=true;
            }
        }
    }
    return dp[s.size()];
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<vector<string>> dp(s.size()+1);
    if(wordBreakjudge(s,wordDict)==false) return dp[s.size()];//先判断是否有解
    dp[0].emplace_back("");
    for(auto i=1;i!=s.size()+1;i++){
        for(auto j=i-1;j!=-1;j--){
            if(dp[j].size()!=0 and find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                if(j==0){
                    dp[i].emplace_back(s.substr(j,i-j));
                }
                else{
                    for(auto it=dp[j].begin();it!=dp[j].end();it++){
                        dp[i].emplace_back(*it+string(" ")+s.substr(j,i-j));
                    }
                }
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    string A="catsandog";
    vector<string> wordDict={"cats","dog","sand","and","cat"};
    
    wordBreak(A, wordDict);
    
}
