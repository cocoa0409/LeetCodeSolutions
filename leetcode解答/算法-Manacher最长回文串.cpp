/*
 将所有回文串的长度转换为奇数
 */
string ManacherTransform(string s){
    string s_new;
    s_new.push_back('$');
    for(auto it=s.begin();it!=s.end();it++){
        s_new.push_back('#');
        s_new.push_back(*it);
    }
    s_new.push_back('#');
    s_new.push_back('\0');
    return s_new;
}
string ManacherClearup(string s){
    string s_new;
    for(auto it=s.begin();it!=s.end();it++){
        if(*it=='$' or *it=='#') continue;
        s_new.push_back(*it);
    }
    return s_new;
}

/*
 https://segmentfault.com/a/1190000008484167#item-4
 Manacher算法：判断s中最长的回文串
 */
string Manacher(string s){
    
    string s_new=ManacherTransform(s);
    
    vector<size_t> P(s_new.size(),0);
    size_t mx = 0;
    size_t id;
    
    for(size_t i=1;i<s_new.size();i++){
        if(i<mx){
            P[i] = min( P[2*id-i] , mx-i );
        }
        else{
            P[i]=1;
        }
        while(s_new[i-P[i]]==s_new[i+P[i]]){
            P[i]++;
        }
        if( mx < i+P[i] ){
            mx = i+P[i];
            id=i;
        }
    }
    
    auto it = max_element(P.begin(), P.end());
    id = distance(P.begin(), it);//获取下标
    
    int MaxPalindromeLength = *it - 1;
    string Palindrome = ManacherClearup(s_new.substr(id-(*it)+1,2*(*it)-1));
    return Palindrome;
}
