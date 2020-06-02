class MedianFinder {
public:
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;
    
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        lo.push(num);  //这个元素压入lo
        
        hi.push(lo.top()); //从lo中选择最大的元素，这是为了避免刚才压入的元素比hi最小值大
        lo.pop();
        
        if(lo.size()<hi.size()){ //现在顺序维持好了，只需要保证size关系
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if(lo.size()==hi.size()) return double(lo.top()+hi.top())/2;
        else return lo.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
