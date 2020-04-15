//
//  动态规划-最长回文子串.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/12.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
bool testhuiwen(string s,int start,int end){
    while(s[start]==s[end]){
        start++;
        end--;
    }
    if(end<=start)
        return true;
    else
        return false;
}


pair<pair<int,int>,pair<int,int>> findlong(string s,int start,int end){
    //前面代表global 后面代表local
    if(start==end){
        //cout<<"string from "<<start<<" to "<<end<<endl;
        //cout<<"local: "<<s.substr(start,1)<<endl;
        //cout<<"global: "<<s.substr(start,1)<<endl;
        
        return pair<pair<int,int>,pair<int,int>>(pair<int,int>(start,end),pair<int,int>(start,end));
    }
    pair<pair<int,int>,pair<int,int>> preresult=findlong(s, start, end-1);
    pair<int,int> gresult=preresult.first;
    pair<int,int> lresult=preresult.second;
    bool flag=false;
    if(lresult.first!=0 and s[end]==s[lresult.first-1]){//先考虑加2位情况
        lresult.first--;
        lresult.second++;
        flag=true;
    }
    if(flag==false and s[end]==s[lresult.first]){//再考虑加1位情况
        int m=lresult.first;
        int n=end;
        while(m<n){
            if(s[m]!=s[n])
                break;
            m++;
            n--;
        }
        if(m>=n){
            lresult.second++;
            flag=true;
        }
    }
    if(flag==false){//无法增加，修改为原地重新
        int m=lresult.first;
        while(m<end){
            if(s[m]==s[end]){
                if(testhuiwen(s, m, end)){
                    lresult.first=m;
                    lresult.second=end;
                    break;
                }
            }
            m++;
        }
        if(m==end){
            lresult.first=end;
            lresult.second=end;
        }
    }
    if(gresult.second-gresult.first < lresult.second-lresult.first){
        gresult=lresult;
    }
    //cout<<"string from "<<start<<" to "<<end<<endl;
    //cout<<"local: "<<s.substr(lresult.first,lresult.second-lresult.first+1)<<endl;
    //cout<<"global: "<<s.substr(gresult.first,gresult.second-gresult.first+1)<<endl;
    return pair<pair<int,int>,pair<int,int>>(gresult,lresult);
}

string longestPalindrome(string s) {
    if(s.size()==0)
        return s;
    pair<pair<int,int>,pair<int,int>> res=findlong(s, 0, s.size()-1);
    return s.substr(res.first.first,res.first.second-res.first.first+1);

}
