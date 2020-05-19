int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int Sum1=(C-A)*(D-B),
        Sum2=(G-E)*(H-F);
    
    if(max(A,E)>=min(C,G) or max(B,F)>=min(D,H)) return Sum1+Sum2;
    
    return Sum1-(min(C,G)-max(A,E)) * (min(D,H)-max(B,F))+Sum2;
}
