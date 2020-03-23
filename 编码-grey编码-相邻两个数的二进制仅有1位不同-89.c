//
//  编码-grey编码-相邻两个数的二进制仅有1位不同-89.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
//反射法
vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    if(n==0) return res;
    res.push_back(1);
    for(int i=2;i<=n;i++){
        for(int j=res.size()-1;j>=0;j--){
            res.push_back(res[j]+pow(2,i-1));
        }
    }
    return res;
}
