//
//  矩阵-对称替代旋转-48.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/17.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
void rotate(vector<vector<int>>& matrix) {
    int sum,i,j,tmp;
    for(sum=0;sum<=matrix.size()*2-2;sum++){
        for(i=0;i<matrix.size();i++){
            j=sum-i;
            if(j>=0 and j<i){
                tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
    }
    for(i=0;i<matrix.size();i++){
        for(j=0;j<=(matrix.size()-1)/2;j++){
            tmp=matrix[i][j];
            matrix[i][j]=matrix[i][matrix.size()-1-j];
            matrix[i][matrix.size()-1-j]=tmp;
        }
    }
}
