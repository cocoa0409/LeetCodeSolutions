//
//  二叉树-1到n的二叉搜索树的个数-卡特兰数-96.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/24.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
int numTrees(int n) {
    if(n==0) return 0;
    
    vector<int> stat;
    stat.push_back(1);
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum+=stat[j]*stat[i-j-1];
        }
        stat.push_back(sum);
    }
    return stat.back();
}
