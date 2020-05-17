class Solution {
public:
vector<int> getNext(string s){
    vector<int> ans;
    ans.push_back(-1);
    int i=0,j=-1;
    while(i<s.size()){
        if(j==-1 or s[i] == s[j]){
            i++;
            j++;
            ans.push_back(j);
        }
        else{
            j=ans[j];
        }
    }
    return ans;
}

int strStr(string haystack, string needle) {
    if(needle=="") return 0;
    if(haystack=="") return -1;
    int i=0,j=0;
    vector<int> next=getNext(needle);
    cout<<haystack.size()<<" "<<needle.size();
    while(i<(int)haystack.length() and j<(int)needle.length()){
        if(j==-1 or haystack[i]==needle[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==needle.size())
        return i-j;
    else
        return -1;
}
};
