//
//  动态规划-无重复字符的最长字串(O(n)).c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/8.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int lengthOfLongestSubstring(std::string s) {
    if(s=="")
        return 0;
    std::string pre_result="";
    std::string near_result="";
    pre_result=pre_result+s[0];
    near_result=near_result+s[0];
    int index;
    for(int i=1;i<s.size();i++){
        index=near_result.find(s[i]);
        if(index<near_result.size()){
            near_result=near_result.substr(index+1)+s[i];
        }
        else{
            near_result=near_result+s[i];
            if(near_result.size()>pre_result.size()){
                pre_result=near_result;
            }
        }
    }
    return pre_result.size();
}


