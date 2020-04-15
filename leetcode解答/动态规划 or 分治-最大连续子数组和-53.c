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

int maxSubArray(vector<int>& nums) {
    int dpi=nums[0];//dpi代表以i结尾的子列的最大和
    int curmax=dpi;
    for(int i=1;i<nums.size();i++){
        dpi=max(nums[i],dpi+nums[i]);
        curmax=max(dpi,curmax);
    }
    return curmax;
}
int maxSubArrayProc(vector<int> & nums,int begin,int end){
    if(begin==end) return nums[begin];
    int mid=(begin+end)/2;
    int leftpart= maxSubArrayProc(nums, begin, mid);
    int rightpart= maxSubArrayProc(nums, mid+1, end);
    int crossmaxl=nums[mid];
    int crosssum=nums[mid];
    for(int i=mid-1;i>=begin;i--){
        crosssum+=nums[i];
        if(crosssum>crossmaxl) crossmaxl=crosssum;
    }
    int crossmaxr=nums[mid+1];
    crosssum=nums[mid+1];
    for(int i=mid+2;i<=end;i++){
        crosssum+=nums[i];
        if(crosssum>crossmaxr) crossmaxr=crosssum;
    }
    return max(max(leftpart,rightpart),crossmaxl+crossmaxr);
    
}

int maxSubArray2(vector<int>& nums) {
    return maxSubArrayProc(nums, 0, nums.size()-1);
}

int main(){
    vector<vector<string>> anss;
    cout<<anss.size();
}
