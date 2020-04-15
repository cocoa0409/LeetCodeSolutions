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
using namespace std;
string convert(string s, int numRows) {
    if(numRows==1)
        return s;
    int len=s.size();
    string res;
    int index;
    for(int i=0;i<=numRows-1;i++){
        index=i;
        if(index>len-1)
            break;
        res+=s[index];
        while(1){
            if(2*(numRows-1-i)-1>0){
                index+=2*(numRows-1-i);
                if(index>len-1)
                    break;
                else
                    res+=s[index];
            }
            
            if(2*(i)-1>0){
                index+=2*(i);
                if(index>len-1)
                    break;
                else
                    res+=s[index];
            }
        }
    }
    return res;
}



int main(int argc, const char * argv[])
{
    string s="A";
    cout<<convert(s, 1);

    
}
