double myPow(double x, int n) {
    if(n==0) return 1;
    if(n==1) return x;
    else if(n==-1) return 1/x;
    if(n%2==0){
        double res=myPow(x,n/2);
        return res*res;
    }
    else{
        double res=myPow(x,(n-1)/2);
        return res*res*x;
    }

}
