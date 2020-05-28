int missingNumber(vector<int>& nums) {
    int idealSum=0;
    int realSum=0;
    for(int i=0;i<nums.size();i++){
        idealSum ^= i;
        realSum  ^= nums[i];
    }
    idealSum ^= nums.size();
    
    return idealSum^realSum;
}
