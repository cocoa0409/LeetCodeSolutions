class TrieNode{
public:
    char _s;
    unordered_map<char,TrieNode *> _childrens;
    TrieNode(){}
    TrieNode(char s){_s=s;}
    
    void insert(string word){
        if(word.size()==0){
            if(_childrens.count('.')==1){//已经有这个单词了 找到末尾标记
                return;
            }
            else{
                _childrens['.']=new TrieNode('.');//加入终止标记 表示这个单词
                return;
            }
        }
        
        if(_childrens.count(word[0])==1){//有第一个字符
            _childrens[word[0]]->insert(word.substr(1));//递归加入
        }
        else{//没有第一个字符
            _childrens[word[0]]=new TrieNode(word[0]);
            _childrens[word[0]]->insert(word.substr(1));//递归加入
        }
    }
    
    bool search(string word){
        if(word.size()==0){
            if(_childrens.count('.')==1){//已经有这个单词了 找到末尾标记
                return true;
            }
            else{
                return false;
            }
        }
        if(_childrens.count(word[0])==1){//有第一个字符
            return _childrens[word[0]]->search(word.substr(1));//递归查找
        }
        else{//没有第一个字符
            return false;
        }
        
    }
    
    bool startsWith(string prefix){
        if(prefix.size()==0){
            return true;
        }
        
        if(_childrens.count(prefix[0])==1){//有第一个字符
            return _childrens[prefix[0]]->startsWith(prefix.substr(1));//递归查找
        }
        else{
            return false;
        }
        
        
    }
};




class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode * root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root->insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return root->search(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return root->startsWith(prefix);
    }
};

int main(){
    Trie * trie = new Trie();

    trie->insert("apple");
    trie->search("apple");   // 返回 true
    trie->search("app");     // 返回 false
    trie->startsWith("app"); // 返回 true
    trie->insert("app");
    trie->search("app");     // 返回 true
}
