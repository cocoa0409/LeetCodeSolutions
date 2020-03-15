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

ostream &operator<<(ostream &out, vector<pair<int,int>>& ans){
    for(pair<int,int> i:ans){
        out<<'<'<<(i.first==INT_MIN?-1:i.first)<<','<<(i.second==INT_MAX?-1:i.second)<<'>'<<" ";
    }
    out<<endl;
    return out;
}



ostream &operator<<(ostream &out, vector<int>& nums){
    for(int i:nums){
        out<<i<<"   ";
    }
    out<<endl;
    return out;
}

int findMax(vector<int>& vec) {
    int max = -999;
    for (auto v : vec) {
        if (max < v) max = v;
    }
    return max;
}

vector<int> findStatus(string s){
    vector<int> ans;
    ans.push_back(0);
    vector<char> queue;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            queue.push_back('(');
            ans.push_back(queue.size());
        }
        else if(s[i]==')' and queue.size()!=0){
            if(queue.back()=='('){
                queue.pop_back();
                ans.push_back(queue.size());
            }
        }
        else{
            assert(queue.size()==0);
            ans.push_back(0);
        }
    }
    return ans;
}

int longestValidParentheses(string s) {
    vector<int> rec=findStatus(s);
    int maxStatus=findMax(rec);
    int i;
    vector<pair<int, int>> ans;
    for(i=0;i<=maxStatus;i++) ans.push_back(pair<int,int>(INT_MIN,INT_MAX));
    int preValue=0;
    int longestSerial=0;
    
    for(i=0;i<rec.size();i++){
        if(rec[i]==0){
            if(i<rec.size()-1 and rec[i+1]==0){
                ans[preValue]=pair<int,int>(INT_MIN,INT_MAX);
                ans[rec[i]].second=i;
                if(ans[rec[i]].first!= INT_MIN and ans[rec[i]].second!= INT_MAX){ longestSerial=(ans[rec[i]].second-ans[rec[i]].first)>longestSerial?(ans[rec[i]].second-ans[rec[i]].first):longestSerial;}
                preValue=0;
                ans[preValue]=pair<int,int>(INT_MIN,INT_MAX);
                continue;
            }
        }
        if(ans[rec[i]].first==INT_MIN)  ans[rec[i]].first=i;
        else {
            ans[rec[i]].second=i;
            if(ans[rec[i]].first!= INT_MIN and ans[rec[i]].second!= INT_MAX){ longestSerial=(ans[rec[i]].second-ans[rec[i]].first)>longestSerial?(ans[rec[i]].second-ans[rec[i]].first):longestSerial;}
        }
        if(rec[i]>preValue){
            assert(preValue==rec[i]-1);
            preValue=rec[i];
        }
        else if(rec[i]<preValue){
            assert(preValue==rec[i]+1);
            ans[preValue]=pair<int,int>(INT_MIN,INT_MAX);
            preValue=rec[i];
        }
    }
    
    cout<<rec<<ans;
    return longestSerial;
}




int main(){
    string s=")(((((()())()()))()(()))(";
    cout<<longestValidParentheses(s);
}
