//
//  main.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/7.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> ans(m,vector<int>(n,1));
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            ans[i][j]=ans[i-1][j]+ans[i][j-1];
        }
    }
    return ans[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<double>> ans(obstacleGrid.size(),vector<double>(obstacleGrid[0].size(),1));
    int i;
    for(i=0;i<obstacleGrid.size();i++)
        if(obstacleGrid[i][0]==1) break;
    for(int j=i;j<obstacleGrid.size();j++)ans[j][0]=0;
    
    for(i=0;i<obstacleGrid[0].size();i++)
        if(obstacleGrid[0][i]==1) break;
    for(int j=i;j<obstacleGrid[0].size();j++)ans[0][j]=0;
    
    for(int i=1;i<obstacleGrid.size();i++){
        for(int j=1;j<obstacleGrid[0].size();j++){
            if(obstacleGrid[i][j]==1) ans[i][j]=0;
            else{
             ans[i][j]=(obstacleGrid[i-1][j]==1?0:ans[i-1][j])+(obstacleGrid[i][j-1]==1?0:ans[i][j-1]);
            }
        }
    }
    return ans[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}



int main(){
    
}
