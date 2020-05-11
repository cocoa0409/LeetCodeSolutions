//
//  算法-加油站环形旅游-134.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/4/21.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
/*
 A->...->B-1->B->...->A
 
 加油站问题：只要保证总油量>总路程即可找到起点
 证明：假设从A点出发，可到达B-1点，无法到达B点；这说明从B点出发，可以到达A点，又可以到达B-1点
 而且由于总油量>总路程，到达B-1点后剩余的油量一定支持我们到达B点
 
 局部性：从A点出发，最多可到B-1点，无法到达B点；这说明巡回旅游不可能从A..B-1点出发！
 */
    if(accumulate(gas.begin(), gas.end(), 0)-accumulate(cost.begin(), cost.end(), 0)<0)
        return -1;
    size_t s_size=gas.size();
    int remgas=0;
    size_t start=0;
    for(size_t i=0;i<s_size;i++){
        remgas+=gas[i];
        remgas-=cost[i];
        if(remgas<0){
            start=i+1;
            remgas=0;
        }
    }
    return start;
}
