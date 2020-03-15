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
        out<<endl;
    }
    return out;
}
void reverse(vector<int>& nums,int s,int e) {
    int tmp;
    int nsize=e-s;
    int ns=(nsize-1)/2;
    for(int i=0;i<=ns;i++){
        //swap i and nums.size()-1-i
        tmp=nums[s+i];
        nums[s+i]=nums[s+nsize-i];
        nums[s+nsize-i]=tmp;
    }
}

void nextPermutation(vector<int>& nums) {
    if(nums.size()<=1)
        return;
    
//从nums.size()-1开始
    int i=nums.size()-1;
    for(;i>0;i--){
        if(nums[i-1]>=nums[i]) continue;
        break;//i-1与i有大小关系 nums[i-1]<nums[i],nums[i]到nums[size-1]为倒序排列
    }
    //如果i=0,说明完全倒序,则正序排列即可
    if(i==0){
        reverse(nums,0,nums.size()-1);
        return;
    }
    //或者reverse nums[i]到nums[size-1],然后将nums[i-1]与比其大的最小数字交换
    else{
        reverse(nums,i,nums.size()-1);
        int j=i;
        while(j<nums.size()-1 and nums[i-1]>=nums[j]){
            j++;
        }//跳出时满足 nums[i-1]<=nums[j]
        int tmp=nums[i-1];
        nums[i-1]=nums[j];
        nums[j]=tmp;
    }
}


int main(){
    vector<int> a={1,5,1};
    nextPermutation(a);
    cout<<a;
}
