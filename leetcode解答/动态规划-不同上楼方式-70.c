//
//  动态规划-不同上楼方式-70.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
int climbStairs(int n) {
    vector<int> ans(n+1,0);
    ans[0]=ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-2]+ans[i-1];
    }
    return ans[n];
}
