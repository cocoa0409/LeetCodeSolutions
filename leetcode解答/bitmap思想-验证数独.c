class Solution {
public:
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
};
