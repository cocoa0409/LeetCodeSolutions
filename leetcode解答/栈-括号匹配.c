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

bool compare(char comp,char c){
    if((comp=='{' and c=='}') or (comp=='[' and c==']') or (comp=='(' and c==')') )
        return true;
    return false;
}
void judge(vector<char>& Q, char c){
    if(Q.size()==0){
        Q.push_back(c);
        return;
    }
    char comp=Q.back();
    if(compare(comp,c))
        Q.pop_back();
    else
        Q.push_back(c);
}
bool isValid(string s) {
    vector<char> Q;
    for(char c: s){
        judge(Q, c);
    }
    if(Q.size()==0)
        return true;
    return false;
}


int main(){
    string s ="({[()]})";
    cout<<isValid(s);
}
