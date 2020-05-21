class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> S;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        vector<int> rev;
        while(S.empty()!=1){
            rev.push_back(S.top());
            S.pop();
        }
        S.push(x);
        for(auto it=rev.rbegin();it!=rev.rend();it++){
            S.push(*it);
        }

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ans = S.top();
        S.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        return S.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
