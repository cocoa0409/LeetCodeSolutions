int nthUglyNumber(int n) {
    vector<int> Ugly(1,1);
    int q2=0,
        q3=0,
        q5=0;
    int N2,N3,N5;
    for(int i=1;i<n;i++){
        N2=Ugly[q2]*2;
        N3=Ugly[q3]*3;
        N5=Ugly[q5]*5;
        if(N2<=N3 and N2<=N5){
            Ugly.push_back(N2);
            q2++;
            if(N2==N3) q3++;
            if(N2==N5) q5++;
        }
        else if(N3<=N2 and N3<=N5){
            Ugly.push_back(N3);
            q3++;
            if(N3==N2) q2++;
            if(N3==N5) q5++;
        }
        else if(N5<=N2 and N5<=N3){
            Ugly.push_back(N5);
            q5++;
            if(N5==N2) q2++;
            if(N5==N3) q3++;
        }
    }
    return Ugly.back();
    
}
