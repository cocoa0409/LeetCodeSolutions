bool isPowerOfTwo(int n) {
    if(n==0) return false;
    while(true){
        if(n%2!=0){
            if(n==1) return true;
            else return false;
        }
        else{
            n>>=1;
        }
    }
}
