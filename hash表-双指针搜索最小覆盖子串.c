//
//  hash表-双指针搜索最小覆盖子串.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/20.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
//76
#include <stdio.h>
string minWindow(string s, string t) {
// 记录最短子串的开始位置和长度
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;

    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for (char c : t) needs[c]++;
    
    int match = 0;
    while(right<s.size()){
        char c1=s[right];
        if(needs.count(c1)){//如果需要c1
            window[c1]++;//如果有重复的，记录其出现次数
            if(window[c1] == needs[c1]) match++;
        }
        right++;
        
        while (match == needs.size()) {
            if(right - left < minLen){
                start=left; minLen=right-left;
            }
            char c2=s[left];
            if(needs.count(c2)){//如果需要c2
                window[c2]--;
                if(window[c2]<needs[c2]) match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX?"":s.substr(start,minLen);
}
