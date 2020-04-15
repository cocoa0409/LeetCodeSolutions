bool isValidNQueens(int n,vector<bool> &count,int i,int j) {
    int rowc=i;//0~n-1 行  n~2n-1 列 2n~4n-2 /  4n-1~6n-3
    int coluc=n+j;
    int leftc=2*n+i+j;
    int rightc=4*n-1+i-j+n-1;
    if(count[rowc]==false and count[coluc]==false and count[leftc]==false and count[rightc]==false){
        return true;
    }
    return false;
}

void fillingQueens(vector<vector<string>> &anss,vector<string> &board,int n,vector<bool> &count,int i,int j,int totalcount){
    if(i>=n or j>=n) return;
    if(i>totalcount) return;
    int rowc=i;
    int coluc=n+j;
    int leftc=2*n+i+j;
    int rightc=4*n-1+i-j+n-1;
    
    if(isValidNQueens(n,count,i,j)){
        board[i][j]='Q';
        count[rowc]=count[coluc]=count[leftc]=count[rightc]=true;
        if(totalcount+1==n) anss.push_back(board);
        else if(j==n-1) fillingQueens(anss,board, n, count, i+1 , 0,totalcount+1);
        else fillingQueens(anss,board, n, count, i, j+1,totalcount+1);
        board[i][j]='.';//撤销操作
        count[rowc]=count[coluc]=count[leftc]=count[rightc]=false;
    }
    if(j==n-1) fillingQueens(anss,board, n, count, i+1 , 0,totalcount);
    else fillingQueens(anss,board, n, count, i, j+1,totalcount);
    
}



vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> anss;
    string s;
    for(int i=0;i<n;i++) s+='.';
    vector<string> board(n,s);
    vector<bool> count(6*n-2,false);
    fillingQueens(anss, board, n, count, 0, 0, 0);
    return anss;
}






int main(){
    vector<vector<string>> anss;
    anss=solveNQueens(4);
    cout<<anss.size();
}
