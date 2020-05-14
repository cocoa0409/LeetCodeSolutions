class Solution {
public:
    int n,m;
    void connect(vector<vector<int>>& father,int i,int j,int _i,int _j){//连接
        //循环不变式:每个群落有且仅有1个-1值,且所有群落点均可以通过下列约化操作找到该-1处
        while(father[i][j]!=-1){
            int mid=father[i][j];
            i=mid/m;j=mid-i*m;
        }
        while(father[_i][_j]!=-1){
            int mid=father[_i][_j];
            _i=mid/m;_j=mid-_i*m;
        }
        if(i!=_i||j!=_j){
            father[i][j]=_i*m+_j;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        if(!n)return 0;
        m=grid[0].size();
        if(!m)return 0;
        vector<int> mid(m,-1);
        vector<vector<int>> father(n,mid);
        //一遍遍历建立并查集
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    if(i-1>=0&&grid[i-1][j]=='1')connect(father,i,j,i-1,j);
                    if(j-1>=0&&grid[i][j-1]=='1')connect(father,i,j,i,j-1);
                    if(i+1<n&&grid[i+1][j]=='1')connect(father,i,j,i+1,j);
                    if(j+1<m&&grid[i][j+1]=='1')connect(father,i,j,i,j+1);
                }
            }
        }
        int res=0;
        //二次遍历记录并查集的个数
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&father[i][j]==-1){
                    res++;
                }
            }
        }
        return res;
    }
};
