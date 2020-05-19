int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    vector<vector<int>> DP(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
    int maxe=0;
    for(int i=1;i<=matrix.size();i++){
        for(int j=1;j<=matrix[0].size();j++){
            if(matrix[i-1][j-1]=='0') continue;
            else{
                int MaxEdge=min(DP[i-1][j],DP[i][j-1])+1;
                MaxEdge=min(DP[i-1][j-1]+1,MaxEdge);
                DP[i][j]=MaxEdge;
                maxe=max(maxe,MaxEdge);
            }
        }
    }
    return pow(maxe,2);

}
