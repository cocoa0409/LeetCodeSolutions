class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        // 确定上下左右四条边的位置
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true)
        {
            for (int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if (++up > down) break;
            for (int i = up; i <= down; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if (--down < up) break;
            for (int i = down; i >= up; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>  a(n,vector<int>(n,0));
        int top=0,down=n-1,left=0,right=n-1;
        int count=1;
        while(1){
            for(int i=left;i<=right;i++){
                a[top][i]=count++;
            }
            top++;
            if(top>down) break;

            for(int i=top;i<=down;i++){
                a[i][right]=count++;
            }
            right--;
            if(right<left) break;

            for(int i=right;i>=left;i--){
                a[down][i]=count++;
            }
            down--;
            if(down<top) break;

            for(int i=down;i>=top;i--){
                a[i][left]=count++;
            }
            left++;
            if(left>right) break;
        }
        return a;


    }
};
