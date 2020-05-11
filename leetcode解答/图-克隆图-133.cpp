//
//  图-克隆图-133.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
void cloneGraphProc(unordered_map<int,Node*>& _addr,Node* _ori,Node* _new){
    if(_ori->neighbors.size()==0) return;
    
    for(auto it=_ori->neighbors.begin();it!=_ori->neighbors.end();it++){
        if(_addr.count((*it)->val)==0){//未包含这个元素，则从这个元素开始探索
            _addr[(*it)->val]=new Node((*it)->val);//新建这个元素
            cloneGraphProc(_addr, *it, _addr[(*it)->val]);
        }
        _new->neighbors.push_back(_addr[(*it)->val]);//记录下链接
    }
}



Node* cloneGraph(Node* node) {
    if(node==nullptr) return nullptr;
    Node * head=new Node(node->val);
    unordered_map<int, Node*> _addr;
    _addr[node->val]=head;
    cloneGraphProc(_addr, node, head);
    return head;
}

