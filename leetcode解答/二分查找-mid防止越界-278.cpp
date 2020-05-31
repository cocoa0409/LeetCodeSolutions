
int firstBadVersion(int n) {
    int beg = 1,
        end = n;
    int mid;
    while(beg!=end){
        mid = beg  + (end-beg)/2;
        if(isBadVersion(mid)) end=mid;
        else beg=mid+1;
    }
    return beg;
}
