//
//  二分查找-旋转1次的近有序数组查询元素是否存在-33.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
int binsearch(vector<int>& nums, int target,int l,int r){
    if(l==r) return nums[l]==target?l:-1;
    int mid=(l+r)/2;
    if(nums[mid]==target) return mid;
    if(nums[l]<=nums[mid]){//左侧有序
        if(nums[l]<=target and target<=nums[mid]){//左侧有序
            return binsearch(nums, target, l, mid);
        }
        else return binsearch(nums,target,mid+1,r);
    }
    else{//右侧有序
        if(nums[mid]<=target and target<=nums[r]){
            return binsearch(nums,target,mid+1,r);
        }
        else return binsearch(nums, target, l, mid);
    }
}


int search(vector<int>& nums, int target) {
    if(nums.size()==0) return -1;
    return binsearch(nums, target, 0, nums.size()-1);
}
