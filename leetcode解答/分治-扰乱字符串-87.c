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


bool isScramble(string s1, string s2) {
    if(s1.size()==1 and s2.size()==1) return s1[0]==s2[0];
    unordered_map<char, int> stat;
    unordered_map<char, int> descstat;
    bool dcflag;
    bool ans;
    for(int i=0;i<s1.size()-1;i++){
        stat[s1[i]]++;//一共i+1个元素
        dcflag=true;
        descstat=stat;
        for(int j=0;j<=i;j++){
            if(descstat.count(s2[j])==true) descstat[s2[j]]--;
            else dcflag=false;
            if(descstat[s2[j]]==0) descstat.erase(s2[j]);
        }
        if(dcflag==true){
            ans=isScramble(s1.substr(0,i+1), s2.substr(0,i+1)) and isScramble(s1.substr(i+1), s2.substr(i+1));
            if(ans==true) return true;
        }
        dcflag=true;
        descstat=stat;
        for(int j=0;j<=i;j++){
            if(descstat.count(s2[s2.size()-1-j])==true) descstat[s2[s2.size()-1-j]]--;
            else dcflag=false;
            if(descstat[s2[s2.size()-1-j]]==0) descstat.erase(s2[s2.size()-1-j]);
        }
        if(dcflag==true){
            ans=isScramble(s1.substr(0,i+1), s2.substr(s2.size()-1-i)) and isScramble(s1.substr(i+1), s2.substr(0,s2.size()-1-i));
            if(ans==true) return true;
        }
    }
    return false;
}

bool isScramble2(string s1, string s2) {
    if(s1.size()==1 and s2.size()==1) return s1[0]==s2[0];
    int i,j,m;
    vector<vector<vector<bool>>> stat(s1.size()+1,vector<vector<bool>>(s1.size(),vector<bool>(s1.size(),false)));
    for(m=1;m<s1.size()+1;m++){
        for(i=0;i<s1.size()-m+1;i++){
            for(j=0;j<s1.size()-m+1;j++){
                if(m==1){
                    if(s1[i]==s2[j]) stat[m][i][j]=true;
                    continue;
                }
                for(int k=1;k<=m-1;k++){
                    stat[m][i][j]=stat[m][i][j] or (stat[m-k][i][j] and stat[k][i+m-k][j+m-k]) or (stat[m-k][i][j+k] and stat[k][i+m-k][j]);
                }
            }
        }
    }
    return stat[s1.size()][0][0];
}

int main(){
    string a="123456789";
    cout<<a.substr(2,3)<<"  "<<a.substr(2);
}
