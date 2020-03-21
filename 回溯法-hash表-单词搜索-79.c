//
//  回溯法-hash表-单词搜索-79.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
struct hashfunc {
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &i) const {
        return hash<T>()(i.first) ^ hash<U>()(i.second);
    }
};

bool existProc(unordered_map<char, vector<pair<int,int>>>& stat,string word,int p,pair<int,int> lastpos,unordered_map<pair<int,int>, int,hashfunc> &banpos){
    if(p>=word.size()) return true;
    vector<pair<int,int>> potpos=stat[word[p]];
    
    for(int i=0;i<potpos.size();i++){
        if(banpos.count(potpos[i])) continue;
        if((lastpos==pair<int,int>{-1,-1}) or (lastpos.first==potpos[i].first and abs(lastpos.second-potpos[i].second)==1) or (lastpos.second==potpos[i].second and abs(lastpos.first-potpos[i].first)==1)){
            banpos[potpos[i]]=p;//记录此坐标为已访问坐标
            bool res = existProc(stat, word, p+1, potpos[i],banpos);//基于此访问后续
            if(res==true) return true;
            banpos.erase(potpos[i]);
        }
    }
    return false;
}



bool exist(vector<vector<char>>& board, string word) {
    unordered_map<char, vector<pair<int,int>>> stat;
    for(int i =0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(stat.count(board[i][j])==0) stat[board[i][j]]={{i,j}};
            else stat[board[i][j]].push_back({i,j});}}
    unordered_map<pair<int,int>, int,hashfunc> banpos;
    return existProc(stat, word, 0,{-1,-1}, banpos);
}







int main(){
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    
    cout<<exist(board, "ABCB");
}
