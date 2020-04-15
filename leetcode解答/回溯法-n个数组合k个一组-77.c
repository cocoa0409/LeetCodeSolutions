//
//  回溯法-n个数组合k个一组-77.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
void combineProc(vector<vector<int>> &ans,vector<int> &subans,int begin,int end,int k){
    if(k==0) {ans.push_back(subans); return;}
    if(begin>end) return;
    subans.push_back(begin);
    combineProc(ans, subans, begin+1, end, k-1);
    subans.pop_back();
    combineProc(ans, subans, begin+1, end, k);
}


vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> subans;
    combineProc(ans, subans, 0, n, k);
    return ans;
}
