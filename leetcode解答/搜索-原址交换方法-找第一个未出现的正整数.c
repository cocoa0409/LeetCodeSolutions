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
void swap(vector<int>& nums,int i,int j){
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
}

int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]>=1 and nums[i]<=nums.size() and nums[nums[i]-1]!=nums[i]){
            swap(nums,i,nums[i]-1);
            while(nums[i]>=1 and nums[i]<=i  and nums[nums[i]-1]!=nums[i] ){
                swap(nums,i,nums[i]-1);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1) return i+1;
    }
    return n+1;
}

int main(){
    vector<int> nums={1,1};
    cout<<firstMissingPositive(nums);
    cout<<nums;
}
