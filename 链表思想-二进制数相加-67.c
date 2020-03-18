//
//  链表思想-二进制数相加-67.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
string addBinary(string a, string b) {
    int aind=a.size()-1;
    int bind=b.size()-1;
    int ind=0;
    string ans="";
    while(aind!=-1 and bind!=-1){
        if(a[aind]=='1' and b[bind]=='1'){
            if(ind==1){
                ind=1;
                ans='1'+ans;
            }
            else if(ind==0){
                ind=1;
                ans='0'+ans;
            }
        }
        else if(a[aind]=='0' and b[bind]=='0'){
            if(ind==1) ans='1'+ans;
            else if(ind==0) ans='0'+ans;
            ind=0;
        }
        else{
            if(ind==1){
                ind=1;
                ans='0'+ans;
            }
            else if(ind==0){
                ind=0;
                ans='1'+ans;
            }
        }
        aind--;
        bind--;
    }
    if(bind==-1){
        while(aind!=-1){
            if(ind==1 and a[aind]=='1'){
                ans='0'+ans; ind=1;
            }
            else if(ind==0 and a[aind]=='0'){
                ans='0'+ans; ind=0;
            }
            else{
                ans='1'+ans; ind=0;
            }
            aind--;
        }
    }
    else{
        while(bind!=-1){
            if(ind==1 and b[bind]=='1'){
                ans='0'+ans; ind=1;
            }
            else if(ind==0 and b[bind]=='0'){
                ans='0'+ans; ind=0;
            }
            else{
                ans='1'+ans; ind=0;
            }
            bind--;
        }
    }
    if(aind==-1 and bind==-1){
        if(ind==1) ans='1'+ans;
        return ans;
    }
    
    return ans;
    
}
