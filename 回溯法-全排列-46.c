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

void swap(vector<int>& nums,int i,int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
}
void backtracking(vector<vector<int>> &ans,vector<int>& nums,int position){
    if(position==nums.size()-1) ans.push_back(nums);
    for(int i=position;i<nums.size();i++){
        swap(nums,position,i);
        backtracking(ans, nums, position+1);
        swap(nums,position,i);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(ans, nums, 0);
    return ans;
}


int main(){
    cout<<isMatch("adceb", "*a*b");
}
