//
//  排序-双指针原址删除数组中的重复项-80.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
//关键点在于考虑什么值需要移动到sp处
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2)
    {
        return n;
    }
    int sp = 1;
    for(int fp = 2; fp < n; fp++)
    {
        if(nums[fp] != nums[sp - 1])
        {
            nums[++sp] = nums[fp];
        }
    }
    return sp + 1;
}
