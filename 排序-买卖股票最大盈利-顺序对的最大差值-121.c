//
//  排序-买卖股票最大盈利-顺序对的最大差值-121.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/27.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;
    
    int minV=prices[0];
    int maxV=prices[0];
    int curMax=0;
    for(int i=1;i<prices.size();i++){
        if(maxV<prices[i]) maxV=prices[i];
        if(minV>prices[i]){
            curMax=max(curMax,maxV-minV);
            maxV=minV=prices[i]
        }
    }
    return max(curMax,maxV-minV);
}
