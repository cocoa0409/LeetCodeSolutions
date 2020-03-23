/////递归方法 超时超内存
void numDecodingsProc(vector<string> &ans, string s,string &subans,int pos){
    if(pos==s.size()){ ans.push_back(s); return;}
    if(s[pos]=='0') return;
    if(pos==s.size()-1 or( s[pos]>='3' and s[pos]<='9')){//如果是最后一位，或者是3到9，仅有1种选择
        subans+=char('A'+s[1]-'0'-1);
        numDecodingsProc(ans, s, subans, pos+1);
    }
    else{//s[pos]=='1' or '2'
        subans+=char('A'+s[1]-'0'-1);
        numDecodingsProc(ans, s, subans, pos+1);
        int count=(int)(s[pos]-'0')*10 +(int)(s[pos+1]-'0');
        if(10<=count and count<=26){
            subans=subans.substr(0,subans.size()-1);//去掉最后一位
            subans+=char('A'+count-1);
            numDecodingsProc(ans, s, subans, pos+2);
        }
    }
    
}
int numDecodings(string s) {
    if(s=="") return 0;
    vector<string> ans;
    string subans;
    numDecodingsProc(ans, s, subans, 0);
    return ans.size();
}

// /////////////////////////////////
void numDecodingsProc(int & res,string s,int pos){
    if(pos==s.size()){ res++; return;}
    if(s[pos]=='0') return;
    if(pos==s.size()-1 or( s[pos]>='3' and s[pos]<='9')){//如果是最后一位，或者是3到9，仅有1种选择
        numDecodingsProc(res,s, pos+1);
    }
    else{//s[pos]=='1' or '2'
        numDecodingsProc(res,s, pos+1);
        int count=(int)(s[pos]-'0')*10 +(int)(s[pos+1]-'0');
        if(10<=count and count<=26){
            numDecodingsProc(res,s, pos+2);
        }
    }
    
}
int numDecodings(string s) {
    if(s=="") return 0;
    int res=0;
    numDecodingsProc(res, s, 0);
    return res;
}

///////////////动态规划方法

class Solution {
public:
int numDecodings(string s) {
    if(s.size()==0 or s[0]=='0') return 0;
    vector<int> ans;
    ans.emplace_back(1);
    ans.emplace_back(1);
    for(int i=1;i<s.size();i++){
        if(s[i]=='0'){
            if(s[i-1]!='1' and s[i-1]!='2') return 0;
            ans.emplace_back(ans[ans.size()-1]);
            continue;
        }
        int count=(int)(s[i-1]-'0')*10 +(int)(s[i]-'0');
        if(10<=count and count<=26){
            if(i!=s.size()-1 and s[i+1]=='0' and (s[i-1]=='1' or s[i-1]=='2')){
                ans.emplace_back(ans[ans.size()-1]);
            }
            else{
            ans.emplace_back(ans[ans.size()-2]+ans[ans.size()-1]);
            }
        }
        else ans.emplace_back(ans[ans.size()-1]);
    }
    return ans.back();
}
};
