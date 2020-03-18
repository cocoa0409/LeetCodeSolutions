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

int findrows(vector<vector<int>>& matrix, int target){
    int mid;
    int begin=0,end=matrix.size()-1;
    if(target<matrix[0][0]) return 0;
    while(begin!=end){
        mid=(begin+end)/2;
        if(target==matrix[mid][0]) return mid;
        else if(target<matrix[mid][0]) end=mid;
        else if(target>=matrix[mid][0]) begin=mid+1;
    }
    if(target<matrix[begin][0])return begin-1;
    return begin;
}

bool findcolumns(vector<int>& matrix,int target){
    int mid;
    int begin=0,end=matrix.size()-1;
    while(begin!=end){
        mid=(begin+end)/2;
        if(target==matrix[mid]) return true;
        else if(target<matrix[mid]) end=mid;
        else if(target>=matrix[mid]) begin=mid+1;
    }
    if(target==matrix[begin])return true;
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0 or matrix[0].size()==0) return false;
    int rowind=findrows(matrix, target);
    return findcolumns(matrix[rowind], target);
}
int main(){
    vector<vector<int>> m{{1,3,5},{10,11,16},{23,30,34}};
    cout<<searchMatrix(m, 38);
}
