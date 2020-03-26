//
//  动态规划-杨辉三角-118.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/27.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> yanghui(numRows);
    if(numRows==0) return yanghui;
    yanghui[0].push_back(1);
    if(numRows==1) return yanghui;
    yanghui[1].push_back(1);
    yanghui[1].push_back(1);
    if(numRows==2) return yanghui;
    for(int i=2;i<numRows;i++){
        yanghui[i].push_back(1);
        for(int j=1;j<yanghui[i-1].size();j++){
            yanghui[i].push_back(yanghui[i-1][j-1]+yanghui[i-1][j]);
        }
        yanghui[i].push_back(1);
    }
    return yanghui;
}

vector<int> getRow(int rowIndex) {
    rowIndex++;
    vector<int> yh(rowIndex,1);
    if(rowIndex<=2) return yh;
    for(int i=3;i<=rowIndex;i++){
        int pre=yh[0];
        int cur=yh[1];
        for(int j=1;j<=i-2;j++){
            yh[j]=pre+cur;
            pre=cur;
            cur=yh[j+1];
        }
    }
    return yh;
}
