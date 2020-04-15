//
//  动态规划-编辑距离-72.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
//编辑距离 基本思路是将所有操作转换到最后一位操作；
//如果最后一位相同word1[i]==word2[j]无需操作，那么edit[i][j]=edit[i-1][j-1];
//如果word1[i]!=word2[j]最后一位操作了，那么显然是
//删：edit[i][j]=edit[i-1][j]+1; 把i-1变到j后 +1删除操作
//增：edit[i][j]=edit[i][j-1]+1  把i变到j-1后 +1增加操作
//改：edit[i][j]=edit[i-1][j-1]+1; 把i-1变到j-1后 由于word1[i]!=word2[j] +1改操作
int minDistance(string word1, string word2) {
    vector<vector<int>> edit(word1.size()+1,vector<int>(word2.size()+1,0));
    for(int i=0;i<word1.size()+1;i++) edit[i][0]=i;
    for(int j=0;j<word2.size()+1;j++) edit[0][j]=j;
    
    for(int i=1;i<word1.size()+1;i++){
        for(int j=1;j<word2.size()+1;j++){
            if(word1[i-1]==word2[j-1]) edit[i][j]=edit[i-1][j-1];
            else edit[i][j]=1+min(min(edit[i-1][j],edit[i][j-1]),edit[i-1][j-1]);
        }
    }
    return edit[word1.size()][word2.size()];
}
