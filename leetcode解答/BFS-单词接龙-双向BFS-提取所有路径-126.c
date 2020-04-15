//
//  BFS-单词接龙-双向BFS-提取所有路径-126.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/30.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    if (wordDict.count(endWord)==false){
        return res;//Not FOUND 404
    }
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    unordered_map<string, vector<string>> prerelation;
    unordered_map<string, vector<string>> bridge;
    int step = 1;
    bool breakflag=false;
    for (; !beginSet.empty();){
        unordered_set<string> tempSet;
        ++step;
        for (auto s : beginSet) {
            wordDict.erase(s);
        }
        for (auto s : beginSet) {
            for (int i = 0; i < s.size(); ++i){
                 string str = s;
                 for (char c = 'a'; c <= 'z'; ++c){
                     str[i] = c;
                     if (wordDict.count(str) == false){
                         continue;
                     }
                     if (endSet.count(str)==true){
                         breakflag=true;
                         bridge[s].push_back(str);//记录两部分的连接关系关系
                     }
                     tempSet.insert(str);
                     if(breakflag==false){
                         prerelation[str].push_back(s);//记录转换关系
                     }
                 }
            }
        }
        if(breakflag==true) break;
        if (tempSet.size() < endSet.size()){
            beginSet = tempSet;
        } else {
            beginSet = endSet;
            endSet = tempSet;
        }
    }
    

    if(bridge.size()==0) return res;
    for(auto links:bridge){
        string bg=links.first;
        for(auto ed: links.second){
            res.push_back(vector<string>{bg,ed});
        }
    }
    queue<vector<string>> dupres;
    for(auto re:res){
        dupres.push(re);
    }
    
    while(prerelation.count(dupres.front()[0])==true or prerelation.count(dupres.front()[dupres.front().size()-1])==true ){
        
        vector<string> newlink=dupres.front();
        dupres.pop();
        string bg=newlink[0];
        string ed=newlink[newlink.size()-1];
        if(prerelation.count(bg)==true){
            for(string newbg : prerelation[bg]){
                vector<string> newlinkwithbg=newlink;
                newlinkwithbg.insert(newlinkwithbg.begin(), newbg);
                dupres.push(newlinkwithbg);
            }
        }
        else{
            if(prerelation.count(ed)==true){
               for(string newed : prerelation[ed]){
                   vector<string> newlinkwithed=newlink;
                   newlinkwithed.insert(newlinkwithed.end(), newed);
                   dupres.push(newlinkwithed);
               }
            }
        }
    }
    res.clear();
    while(dupres.empty()==false){
        vector<string> link=dupres.front();
        dupres.pop();
        if(link[0]==endWord){
            reverse(link.begin(), link.end());
        }
        res.push_back(link);
    }
    return res;
}
int main(){
    vector<string> wordList{"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear","cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried","hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry","igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women","issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel","diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake","balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore","felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse","joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke","scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party","brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole","suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped","heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes","loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts","yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer","peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract","calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai","waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds","finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty","marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"};
    findLadders("magic", "pearl", wordList);
}
