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
        out<<i<<"   ";
    }
    out<<endl;
    return out;
}
int binarySearch(vector<int>& nums,int start,int end,int target){
    if(start==end) return target<=nums[start]?start:start+1;
    int mid=(start+end)/2;
    if(target==nums[mid]) return mid;
    else if(target>nums[mid]) return binarySearch(nums, mid+1, end, target);
    else return binarySearch(nums, start, mid, target);
}


int searchInsert(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size()-1, target);
}

int main(){
    vector<int> vec={5,7,8,10};
    cout<<searchInsert(vec, 9);
}
