int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),1));
    int tmp=0;
    for(int i=0;i<grid.size();i++){
        tmp+=grid[i][0];
        ans[i][0]=tmp;
    }
    tmp=0;
    for(int i=0;i<grid[0].size();i++){
        tmp+=grid[0][i];
        ans[0][i]=tmp;
    }
    for(int i=1;i<grid.size();i++){
        for(int j=1;j<grid[0].size();j++){
            ans[i][j]=min(ans[i-1][j],ans[i][j-1])+grid[i][j];
        }
    }
    return ans[grid.size()-1][grid[0].size()-1];
    
}
