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


void generateProc(vector<string> &ans,string cur,int l,int r){
    if(l==0 and r==0){
        ans.push_back(cur);
    }
    assert(l<=r);
    if(l>0 and l<=r){
        generateProc(ans,cur+'(',l-1,r);
    }
    if(l<r){
        generateProc(ans,cur+')',l,r-1);
    }
    
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateProc(ans, "", n, n);
    return ans;
}


int main(){
}
