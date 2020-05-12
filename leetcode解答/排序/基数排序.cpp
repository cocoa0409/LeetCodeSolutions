//
//  基数排序.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/5/12.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int RadixSort(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int maxVal = * std::max_element(nums.begin(), nums.end());

    int exp = 1;                                 // 1, 10, 100, 1000 ...
    int radix = 10;                              // base 10 system

    vector<int> aux(nums.size());

    /* LSD Radix Sort */
    while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
        vector<int> count(radix, 0);

        for (int i = 0; i < nums.size(); i++)    // Counting sort
            count[(nums[i] / exp) % 10]++;

        for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
            count[i] += count[i - 1];

        for (int i = nums.size() - 1; i >= 0; i--)
            aux[--count[(nums[i] / exp) % 10]] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = aux[i];

        exp *= 10;
    }
}
