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

void combinationProc(vector<int>& candidates,int target,vector<int>& curans, vector<vector<int>> &ans){
    if(candidates.size()==0) return;
    if(target<candidates[0]) return;
    for(int i:candidates){
        if(curans.size()!=0 and i<curans.back()){
            continue;
        }
        if(i<target){
            curans.push_back(i);
            combinationProc(candidates, target-i, curans, ans);
            curans.pop_back();
        }
        else if(i==target){
            curans.push_back(i);
            ans.push_back(curans);
            curans.pop_back();
            return;
        }
        else return;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> curans;
    combinationProc(candidates, target, curans, ans);
    return ans;
}

int main(){
    vector<int> vec={2,3,5};
    vector<vector<int>> ans =combinationSum(vec, 8);
    cout<<vec;
    cout<<ans;
}
