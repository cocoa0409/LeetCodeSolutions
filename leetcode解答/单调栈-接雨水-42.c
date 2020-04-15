//
//  单调栈-接雨水-42.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/22.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
//单调减栈
int trap(vector<int>& height) {
    vector<pair<int, int>> MonoStack;
    pair<int,int> tmp;
    int Volumn=0;
    for(int i=0;i<height.size();i++){
        if(MonoStack.size()==0 or height[i]<=MonoStack.back().first) MonoStack.push_back({height[i],i});
        else{
            while(height[i]>MonoStack.back().first){
                tmp=MonoStack.back();
                MonoStack.pop_back();
                if(MonoStack.size()==0) break;
                int minh=min(MonoStack.back().first,height[i]);
                Volumn+=(minh-tmp.first)*(i-MonoStack.back().second-1);
            }
            MonoStack.push_back({height[i],i});
        }
    }
    return Volumn;
}
