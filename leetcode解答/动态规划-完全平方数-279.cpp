int numSquares(int n) {
    vector<int> DP(n+1,INT_MAX);
    DP[0]=0;
    for(int i=1;i<=n+1;i++){
        for(int num=floor(sqrt(i));num>0;num--){
            DP[i]=min(DP[i- pow(num,2)]+1,DP[i]);
        }
    }
    return DP[n];
}
