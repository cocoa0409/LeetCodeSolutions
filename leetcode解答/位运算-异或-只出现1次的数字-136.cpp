//
//  位运算-异或-只出现1次的数组-136.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int singleNumber(vector<int>& nums) {
    int res=0;
    for(auto it=nums.begin();it!=nums.end();it++){
        res^=*it;
    }
    return res;
}
