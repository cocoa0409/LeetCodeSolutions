//
//  排序-多指针原址替代计数排序-75.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

void doubleExchange(vector<int>& nums,int i,int j){
    int tmp= nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
}

void tripleExchange(vector<int>& nums,int i,int j,int k){
    //i - 0新位  j - 1新位 k - 2
    doubleExchange(nums, k, i);
    doubleExchange(nums, k, j);
}


void sortColors(vector<int>& nums) {
    if(nums.size()<=1) return;
    int zero,one,two;//记为如果新来一个 0 1 2 分别需要放到什么位置
    zero=one=two=0;
    int pt=0;
    while(pt<nums.size()){
        assert(pt==two);
        if(nums[pt]==0){
            if(zero!=one) tripleExchange(nums, zero,one,pt);
            else doubleExchange(nums, zero, pt);
            zero++;one++;two++;
        }
        else if(nums[pt]==1){
            doubleExchange(nums, one, pt);
            one++;two++;
        }
        else two++;
        pt++;
    }
}
