//
//  DFS-电话号码转可能排列字符.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/13.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

void add(string str,string digits,unordered_map<char, string> & table,vector<string>& res,int k){
    if(str.size()==digits.size()){
        res.push_back(str);
        return;
    }
    string tmp=table[digits[k]];
    for(char c:tmp){
        str+=c;
        add(str,digits,table,res,k+1);
        str.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    unordered_map<char, string> table{
        {'0', " "}, {'1',"*"}, {'2', "abc"},
        {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
        {'9',"wxyz"}};
    vector<string> res;
    if(digits == "") return res;
    add("",digits,table,res,0);
    return res;
}
