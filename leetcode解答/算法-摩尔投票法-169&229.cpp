//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

/*
 算法：
 每次删除2个不相同的数，最后留下的一定是出现次数超过1/2的数，
 这个思想可以推广到出现次数超过1/k次的元素有哪些。
 */

int majorityElement(vector<int>& nums) {
    //pairing阶段
    int candidate = -1;
    int count = 0;
    for (int num : nums) {
        if (num == candidate)
            ++count;
        else if (--count < 0) {
            candidate = num;
            count = 1;
        }
    }
    //counting阶段
    count=0;
    for (int num : nums){
        if(candidate==num) count++;
    }
    if(count>nums.size()/2) return candidate;
    else return -1;
}

//给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
/*
算法：
每次删除3个不相同的数，最后留下的一定是出现次数超过1/2的数，
这个思想可以推广到出现次数超过1/k次的元素有哪些。
*/
vector<int> majorityElement(vector<int>& nums) {
    //pairing阶段
    int candidate1 = -1;
    int count1 =0;
    int candidate2 = -1;
    int count2 =0;
    for(int num:nums){
        if( num == candidate1 ){
            count1++;
        }
        else if( num == candidate2 ){
            count2++;
        }
        else{
            if(count1==0){
                candidate1 = num;
                count1=1;
                continue;
            }
            if(count2==0){
                candidate2 = num;
                count2=1;
                continue;
            }
            count1--;
            count2--;
        }
    }
    //counting阶段
    count1=0;count2=0;
    for(int num :nums){
        if(candidate1==num) count1++;
        if(candidate2==num) count2++;
    }
    vector<int> res;
    if(count1>nums.size()/3) res.push_back(candidate1);
    if(count2>nums.size()/3) res.push_back(candidate2);
    return res;
}
