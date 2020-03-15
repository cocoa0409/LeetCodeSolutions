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
int binarySearch(vector<int>& nums,int start,int end,int target,string Priority){
    if(start==end){
        if(nums[start]==target) return start;
        else return -1;
    }
    if(start>end) return -1;
    
    int mid=(start+end)/2;
    if(nums[mid]==target){
        if(Priority=="head"){
            int tmp=binarySearch(nums, start, mid-1, target, Priority);
            if(tmp==-1) return mid;
            else return min(mid,tmp);
        }
        else if(Priority=="tail"){
            int tmp=binarySearch(nums, mid+1, end, target, Priority);
            if(tmp==-1) return mid;
            else return max(mid,tmp);
        }
    }
    else if(nums[mid]<target){
        return binarySearch(nums, mid+1, end, target, Priority);
    }
    else{
        return binarySearch(nums, start, mid-1, target, Priority);
    }
    return -99;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    ans.push_back(binarySearch(nums, 0, nums.size()-1, target, "head"));
    ans.push_back(binarySearch(nums, 0, nums.size()-1, target, "tail"));
    return ans;

}
int main(){
    vector<int> vec={5,7,7,8,8,10};
    vector<int> ans = searchRange(vec, 3);
    cout<<ans;
}
