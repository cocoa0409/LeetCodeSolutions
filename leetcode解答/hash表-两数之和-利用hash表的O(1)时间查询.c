//
//  hash表-两数之和-利用hash表的O(1)时间查询.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/8.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::map<int, int> maps;
    for(int i=0;i<nums.size();i++)
    {
        maps.insert(std::pair<int, int>(nums[i],i));
    }
    std::map<int, int>::iterator iter;
    for(int i=0;i<nums.size();i++)
    {
        iter = maps.find(target-nums[i]);
        if(iter!=maps.end()&&i!=iter->second)
        {
            return std::vector<int>{i,iter->second};
        }
    }
    return std::vector<int>(0,0);
}
