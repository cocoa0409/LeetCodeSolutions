//
//  二分查找-sqrt-69.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/18.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <stdio.h>
int mySqrt(int x) {
    if(x==0 or x==1) return x;
    int left=1;
    int right=x/2+1;
    int mid;
    while(right-left>1){
        mid=(left+right)/2;
        if(mid<=x/mid) left=mid;
        else right=mid;
    }
    return left;
}
