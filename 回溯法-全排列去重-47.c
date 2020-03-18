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
void backtrackingUnique(vector<vector<int>> &ans,vector<int>& nums,int position){
    if(position==nums.size()-1) ans.push_back(nums);
    unordered_map<int, bool> h{};
    for(int i=position;i<nums.size();i++){
        if(nums[i]==nums[position] and i!=position)
            continue;
        if(h[nums[i]]==true) continue;
        h[nums[i]]=true;
        swap(nums,position,i);
        backtrackingUnique(ans, nums, position+1);
        swap(nums,position,i);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrackingUnique(ans, nums, 0);
    return ans;

}

int main(){
    unordered_map<int, bool> h{};
    h[221]=true;
    cout<<h[21];
}
