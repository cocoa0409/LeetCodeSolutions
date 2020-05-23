vector<int> singleNumber(vector<int>& nums) {
    int bitmask=0;
    for(const auto & num:nums){
        bitmask ^= num;
    }
    int diff=bitmask & -bitmask;
    
    int x=0;
    for(const auto & num:nums){
        if(num & diff){
            x ^= num;
        }
    }
    
    int y=bitmask ^ x;
    
    vector<int> res;
    res.push_back(x);
    res.push_back(y);
    return res;
}
