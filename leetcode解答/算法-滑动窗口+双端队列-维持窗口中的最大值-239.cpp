vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    int i=0;
    for(;i<k-1;i++){//更新k-1个窗口
        if(dq.empty()) dq.push_back(i);
        else{
            while(dq.empty()==false and nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    
    vector<int> res;
    for(;i<nums.size();i++){//每加入一个元素 均要考虑第一个元素是否需要弹出
        if(dq.front()+k==i) dq.pop_front();
        while(dq.empty()==false and nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(nums[dq.front()]);
    }
    return res;
}
