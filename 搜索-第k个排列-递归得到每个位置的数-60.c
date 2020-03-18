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
int nfactorial(int n){
    if(n==0) return 0;
    int ans=1;
    while(n!=0){
        ans*=n;
        n--;
    }
    return ans;
}
string getPermutationProc(int n, vector<int> &count,int k){
    int i=0;
    string ans;
    if(n==1){
        while(1) {
            if(count[i]!=0) return ans=(count[i]+'0');
            i++;
        }
    }
    int roundcount=k/nfactorial(n-1);
    int round=roundcount;
    i=0;
    while(1){
        if(count[i]!=0){
            round--;
            if(round==-1) break;
        }
        i++;
    }
    ans=(count[i]+'0');
    count[i]=0;
    return ans+getPermutationProc(n-1, count,k-roundcount*nfactorial(n-1) );
}


string getPermutation(int n, int k) {
    vector<int> count;
    for(int i=1;i<=n;i++) count.push_back(i);
    return getPermutationProc(n, count, k-1);
}


int main(){
    cout<<getPermutation(3, 4);
}
