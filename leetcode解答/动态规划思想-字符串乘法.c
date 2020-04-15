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
ostream &operator<<(ostream &out, vector<int>& nums){
    for(int i:nums){
        out<<i<<" ";
    }
    out<<endl;
    return out;
}
ostream &operator<<(ostream &out,vector<vector<int>>& board){
    for(vector<int> i:board){
        out<<i<<endl;
    }
    return out;
}


string multiply(string num1, string num2) {
    if(num1=="0" or num2=="0")
        return "0";
    
    int n2size=num2.size();
    int n1size=num1.size();
    vector<int> result;
    int tmp,ind=0;
    string ans="";
    for(int i=n1size+n2size-2;i>=0;i--){
        tmp=0;
        for(int j=0;j<n2size;j++) if(i-j>=0 and i-j<n1size) tmp+=(num1[i-j]-'0')*(num2[j]-'0');
        tmp+=ind;
        if(tmp/10>0){
            ind=tmp/10;
            tmp=tmp%10;
        }
        else ind=0;
        ans=(char)('0'+tmp) + ans;
    }
    if(ind!=0) ans=(char)('0'+ind) + ans;
    return ans;
}

int main(){
    cout<<multiply("123","456");
}
