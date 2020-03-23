//
//  单调栈-矩阵转化为柱状图后计算最大矩形.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

class Solution {
public:
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size()==0 or matrix[0].size()==0) return 0;
    vector<vector<int>> stat(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int j=0;j<matrix[0].size();j++){
        int count=0;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][j]=='0') count=0;
            else stat[i][j]=++count;
        }
    }
    int maxArea=0;
    for(int i=0;i<matrix.size();i++) maxArea=max(maxArea,largestRectangleArea(stat[i]));
    return maxArea;
}

int largestRectangleArea(vector<int>& heights) {
    vector<pair<int,int>> MonoStack;
    pair<int,int> tmp;
    int maxArea=INT_MIN;
    
    MonoStack.push_back({-1,-1});
    for(int i=0;i<heights.size();i++){
        if(heights[i]>=MonoStack.back().first) MonoStack.push_back({heights[i],i});
        else{
            while(heights[i]<MonoStack.back().first){
                tmp=MonoStack.back();
                MonoStack.pop_back();
                maxArea=max(maxArea,(i-MonoStack.back().second-1)*tmp.first);
            }
            MonoStack.push_back({heights[i],i});
        }
    }//到尾了
    while(MonoStack.back()!=pair<int,int>{-1,-1}){
        tmp=MonoStack.back();
        MonoStack.pop_back();
        maxArea=max(maxArea, tmp.first*((int)heights.size()-1 -MonoStack.back().second));
    }
    return maxArea;
}
};
