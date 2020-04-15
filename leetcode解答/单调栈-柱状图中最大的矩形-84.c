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
//单调增栈
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

int main(){
    vector<int> a={2,1,5,6,2,3};
    largestRectangleArea(a);
}
