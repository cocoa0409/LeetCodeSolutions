//
//  位运算-移位+且or或-只出现n次的数字-137.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i = 0;i < 32;++i){
        int sum = 0;
        for(int j = 0;j < nums.size();++j){
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    return res;
}
