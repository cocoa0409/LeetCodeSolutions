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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.size()<4){
        return ans;
    }
    sort(nums.begin(), nums.end());
    int i,j,l,r;
    for(i=0;i<nums.size()-3;i++){
        if(i>0 and nums[i]==nums[i-1])continue;
        if(nums[i]>target and nums[i]>0 ) break;
        for(j=i+1;j<nums.size()-2;j++){
            if(j>i+1 and nums[j]==nums[j-1])continue;
            if(nums[i]+nums[j]>target and nums[j]>0 ) break;
            l=j+1;
            r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]+nums[j]<target) l++;
                else if(nums[l]+nums[r]+nums[i]+nums[j]>target) r--;
                else{
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r and nums[l]== nums[l-1]) l++;
                    while(l<r and nums[r]== nums[r+1]) r--;
                }
            }
        }
    }
    return ans;
}



int main(){
    vector<int> a={-1,0,-5,-2,-2,-4,0,1,-2};
    fourSum(a, -9);
}
