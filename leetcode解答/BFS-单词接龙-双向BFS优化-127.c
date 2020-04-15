//
//  BFS-单词接龙-双向BFS优化-127.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/29.
//  Copyright © 2020 兆吉 王. All rights reserved.
//


#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//bool connectWord(string w1,string w2){
////    if(w1.size()!=w2.size()) return false;
//    int difcont=0;
//    for(int i=0;i<w1.size();i++)if(w1[i]!=w2[i])if(++difcont>1) return false;
//    return true;
//}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    if (wordDict.count(endWord)==false){
        return 0;//Not FOUND 404
    }
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    int step = 1;
    for (; !beginSet.empty();){
        unordered_set<string> tempSet;
        ++step;
        for (auto s : beginSet) {
            wordDict.erase(s);
        }
        for (auto s : beginSet) {
            for (int i = 0; i < s.size(); ++i){
//                for(auto nexts: wordDict){
//                    if(!connectWord(s, nexts)) continue;
//                    if(endSet.count(nexts)==true){
//                        return step;
//                    }
//                    tempSet.insert(nexts);
//                }

                 string str = s;
                 for (char c = 'a'; c <= 'z'; ++c){
                     str[i] = c;
                     if (wordDict.count(str) == false){
                         continue;
                     }
                     if (endSet.count(str)==true){
                         return step;
                     }
                     tempSet.insert(str);
                 }
            }
        }
        if (tempSet.size() < endSet.size()){
            beginSet = tempSet;
        } else {
            beginSet = endSet;
            endSet = tempSet;
        }
    }
    return 0;
}



int main(){
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit", "cog", wordList);
}
                
