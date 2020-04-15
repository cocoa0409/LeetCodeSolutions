//
//  图-最短路径-三角形图-贪心or动态规划-120.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/27.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int minimumTotal(vector<vector<int>>& triangle) {
    int nums=triangle.size();
    if(nums==0) return 0;
    if(nums==1) return triangle[0][0];
    vector<int> count(nums,0);
    vector<int> mirror;
    count[0]=triangle[0][0];
    for(int i=2;i<=nums;i++){
        mirror=count;
        for(int j=0;j<i;j++){
            if(j>0 and j<i-1){
                count[j]=min(mirror[j-1],mirror[j])+triangle[i-1][j];
            }
            else if(j==0) count[j]=mirror[j]+triangle[i-1][j];
            else count[j]=mirror[j-1]+triangle[i-1][j];
        }
    }
    int minP=INT_MAX;
    for(int i=0;i<nums;i++){
        minP= count[i]<minP?count[i]:minP;
    }
    return minP;
}
