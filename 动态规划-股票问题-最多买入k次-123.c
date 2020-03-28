//
//  动态规划-股票问题-最多买入k次-123.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/28.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

/*
 M[n][k][0]表示第n天，已经交易了k次（买入一次算交易一次），当前未持股
 M[n][k][1]表示第n天，已经交易了k次，当前持股
 转移方程
 M[n][k][0]=max(M[n-1][k][0],M[n-1][k][1]+prices[n-1])  prices[n-1]为第n天卖出价钱
 M[n][k][1]=max(M[n-1][k][1],M[n-1][k-1][0]-prices[n-1])
 */
int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;
    int TradingTimes=2;
    vector<vector<vector<int>>> M(prices.size()+1,vector<vector<int>>(TradingTimes+1,vector<int>(2,INT_MIN)));
    for(int n=0;n<=prices.size();n++){
//        for(int k=0;k<=TradingTimes;k++){
            M[n][0][0]=0;
//        }
    }
    for(int n=1;n<=prices.size();n++){
        for(int k=1;k<=TradingTimes;k++){
//如果两个转移前状态都不可能实现 则本状态一定无法实现
            if(M[n-1][k][0]==INT_MIN and M[n-1][k][1]==INT_MIN)
                M[n][k][0]=INT_MIN;
            else
                M[n][k][0]=max(M[n-1][k][0],M[n-1][k][1] + prices[n-1]);
//如果两个转移前状态都不可能实现 则本状态一定无法实现
            if(M[n-1][k][1]==INT_MIN and M[n-1][k-1][0]==INT_MIN)
                M[n][k][0]=INT_MIN;
            else
                M[n][k][1]=max(M[n-1][k][1],M[n-1][k-1][0] - prices[n-1]);
        }
    }
    return max(M[prices.size()][0][0],max(M[prices.size()][1][0],M[prices.size()][2][0]));
}
int main(){
    vector<int> p{1,4,2};
    cout<<maxProfit(p);
}
