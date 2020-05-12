//
//  位运算-移位-翻转二进制-190.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/5/13.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

uint32_t reverseBits(uint32_t n) {
    uint32_t res=0;
    for(int i=1;i<=32;i++){
        res = res << 1;
        if(n%2!=0) res+=1;
        n = n >> 1;
    }
    return res;
}
