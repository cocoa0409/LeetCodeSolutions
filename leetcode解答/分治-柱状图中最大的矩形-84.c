//
//  分治-柱状图中最大的矩形-84.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
int largestRectangleAreaProc(vector<int>& heights,int l,int r){
    if(l>r) return 0;
    if(l==r) return heights[l];
    int smlind=l;
    vector<int> smlindq;
    smlindq.push_back(smlind);
    for(int i=l+1;i<=r;i++){
        if(heights[i]<heights[smlind]){
            smlind=i;
            smlindq.clear();
            smlindq.push_back(i);
        }
        else if(heights[i]==heights[smlind]){
            smlindq.push_back(i);
        }
        
    }
    smlind=smlindq[smlindq.size()/2];
    
    if(smlind==l){
        return max((r-l+1)*heights[smlind],largestRectangleAreaProc(heights, l+1, r));
    }
    else if(smlind==r){
        return max((r-l+1)*heights[smlind],largestRectangleAreaProc(heights, l, r-1));
    }
    else{
        return max( max( (r-l+1)*heights[smlind],largestRectangleAreaProc(heights, smlind+1, r) ) , largestRectangleAreaProc(heights, l, smlind-1) );
    }
    
}

int largestRectangleArea(vector<int>& heights) {
    return largestRectangleAreaProc(heights, 0, heights.size()-1);
}
