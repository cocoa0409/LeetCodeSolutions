//
//  回溯法-幂集-78.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
void subsetsProc(vector<vector<int>> &ans,vector<int> &subans,vector<int>& nums,int i,int total){
    if(i==total) {ans.push_back(subans);return;}
    subans.push_back(nums[i]);
    subsetsProc(ans, subans,nums, i+1, total);
    subans.pop_back();
    subsetsProc(ans, subans,nums, i+1, total);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> subans;
    subsetsProc(ans, subans, nums,0, nums.size());
    return ans;
}
