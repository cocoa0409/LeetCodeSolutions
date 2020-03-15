//
//  main.cpp
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/7.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
ostream &operator<<(ostream &out, vector<char>& nums){
    for(char i:nums){
        out<<i<<" ";
    }
    out<<endl;
    return out;
}
ostream &operator<<(ostream &out,vector<vector<char>>& board){
    for(vector<char> i:board){
        out<<i<<"endl";
    }
    return out;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> count(9, 0); //分别记录1-9出现的情况 bit 0-8:squart; bit 9-17: row; bit 18-26: column
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int val = board[i][j] - '0';
            int squart_num = int(i / 3) * 3 + j / 3;
            if (val > 0 && val < 10){
                val--;
                if (((count[val] >> squart_num) & 1) || ((count[val] >> (9 + i)) & 1)\
                    || ((count[val] >> (18 + j)) & 1) ) //第squart_num九宫格、第i行、第j列均未出现过
                    return false;
                count[val] += (1 << squart_num) + (1 << (i + 9)) + (1 << (j + 18));
            }
        }
    }
    return true;
}

vector<int> initializeCount(vector<vector<char>>& board){
    vector<int> count(9, 0); //分别记录1-9出现的情况 bit 0-8:squart; bit 9-17: row; bit 18-26: column
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int val = board[i][j] - '0';
            int squart_num = int(i / 3) * 3 + j / 3;
            if (val > 0 && val < 10){
                val--;
//                if (((count[val] >> squart_num) & 1) || ((count[val] >> (9 + i)) & 1)\
//                    || ((count[val] >> (18 + j)) & 1) ) //第squart_num九宫格、第i行、第j列均未出现过
//                    return false;
                count[val] += (1 << squart_num) + (1 << (i + 9)) + (1 << (j + 18));
            }
        }
    }
    return count;
}

bool fillingvalues(vector<vector<char>>& board,vector<int> count,int i,int j){
    if(board[i][j]!='.'){
        if(i==8 and j==8) return true;
        if(j==8) return fillingvalues(board, count, i+1, 0);
        else return fillingvalues(board, count, i, j+1);
    }
    
    int squart_num = int(i / 3) * 3 + j / 3;
    bool fg;
    for(int val=0;val<9;val++){
        fg=false;
        if ((((count[val] >> squart_num) & 1) || ((count[val] >> (9 + i)) & 1)\
            || ((count[val] >> (18 + j)) & 1))==false ){//第squart_num九宫格、第i行、第j列均未出现过
            board[i][j]='0'+val+1;
            count[val] += (1 << squart_num) + (1 << (i + 9)) + (1 << (j + 18));//代表i,j处填充了val+1
            if(i==8 and j==8) return true;
            if(j==8) fg=fillingvalues(board, count, i+1, 0);
            else fg=fillingvalues(board, count, i, j+1);
            if(fg==true) return true;
            else {
                board[i][j]='.';
                count[val] -= (1 << squart_num) + (1 << (i + 9)) + (1 << (j + 18));//代表i,j处消去了val
            }
        }
        else continue;
    }
    return false;
}



void solveSudoku(vector<vector<char>>& board) {
    vector<int> count=initializeCount(board);
    bool flag=fillingvalues(board, count, 0, 0);
    assert(flag==true);
}

int main(){
    vector<int> vec={5,7,8,10};
    cout<<(char)6
}
