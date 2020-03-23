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
void subsetsProc(vector<vector<int>> &ans,vector<int> &subans,vector<int>& nums,int i,int total){
    if(i==total) {ans.push_back(subans);return;}
    int nexti=i;
    while(nums[nexti]==nums[i]) nexti++;
    int j=i;
    while(j!=nexti){
        subans.push_back(nums[j]);
        subsetsProc(ans, subans,nums, nexti, total);
        j++;
    }
    j=i;
    while(j!=nexti){
        subans.pop_back();
        j++;
    }
    subsetsProc(ans, subans,nums, nexti, total);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subans;
    sort(nums.begin(), nums.end());
    subsetsProc(ans, subans, nums,0, nums.size());
    return ans;
}


int main(){
    vector<int> a{4,4,4,1,2,3,4};
    vector<vector<int>>ans=subsetsWithDup(a);
    cout<<ans;
}
