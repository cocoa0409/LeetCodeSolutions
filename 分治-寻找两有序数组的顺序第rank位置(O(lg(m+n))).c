class Solution {
public:
double locate(vector<int> & nums,int s,int e,int value){
    // nums[floor(locate返回值)]<value<nums[ceil(locate返回值)]
    if(s==e){
        if(value<nums[s])
            return s-0.5;
        else if (value>nums[s])
            return s+0.5;
        else
            return s;
    }
    int p=(e+s)/2;
    int numvalue=nums[p];
    if(value<numvalue){
        return locate(nums,s,p,value);
    }
    else if(value>numvalue){
        return locate(nums,p+1,e,value);
    }
    else
        return p;
}

int findRecursive(vector<int>& nums1, vector<int>& nums2,int N_s,int N_e,int M_s,int M_e,int rank){
//跳出条件
    if(N_e-N_s==-1){
        return nums2[M_s+rank-1];
    }
    if(M_e-M_s==-1){
        return nums1[N_s+rank-1];
    }
    int Npivot=(N_e+N_s)/2;
    int Mpivot=(M_e+M_s)/2;
    double Npviot_in_nums2 = locate(nums2, M_s, M_e, nums1[Npivot]);
    double Mpviot_in_nums1 = locate(nums1, N_s, N_e, nums2[Mpivot]);
    int N_left_count,N_middle_count,N_right_count;
    int M_left_count,M_middle_count,M_right_count;
    if(Npivot<Mpviot_in_nums1){
        N_left_count=Npivot-N_s+1;
        N_middle_count=floor(Mpviot_in_nums1)-Npivot;
        N_right_count=N_e-floor(Mpviot_in_nums1);
    }
    else if(Npivot>Mpviot_in_nums1){
        N_left_count=floor(Mpviot_in_nums1)-N_s+1;
        N_middle_count=Npivot-floor(Mpviot_in_nums1);
        N_right_count=N_e-Npivot;
    }
    else{
        assert(Npivot==Mpviot_in_nums1);
        N_left_count=Npivot-N_s;
        N_middle_count=0;
        N_right_count=N_e-Npivot+1;
        
    }
    if(Mpivot<Npviot_in_nums2){
        M_left_count=Mpivot-M_s+1;
        M_middle_count=floor(Npviot_in_nums2)-Mpivot;
        M_right_count=M_e-floor(Npviot_in_nums2);
    }
    else if(Mpivot>Npviot_in_nums2){
        M_left_count=floor(Npviot_in_nums2)-M_s+1;
        M_middle_count=Mpivot-floor(Npviot_in_nums2);
        M_right_count=M_e-Mpivot;
    }
    else{
        assert(Mpivot==Npviot_in_nums2);
        M_left_count=Mpivot-M_s;
        M_middle_count=1;
        M_right_count=M_e-Mpivot;
        
    }
    //cout<<"N_left_count="<<N_left_count<<"  N_middle_count="<<N_middle_count<<"  N_right_count="<<N_right_count<<endl;
      //  cout<<"M_left_count="<<M_left_count<<"  M_middle_count="<<M_middle_count<<"  M_right_count="<<M_right_count<<endl;
    assert(N_left_count+N_middle_count+N_right_count==N_e-N_s+1);
    assert(M_left_count+M_middle_count+M_right_count==M_e-M_s+1);
    
    if(rank<=N_left_count+M_left_count){
        return findRecursive(nums1, nums2, N_s, N_s+N_left_count-1, M_s, M_s+M_left_count-1, rank);
    }
    else if(rank<=N_left_count+M_left_count+N_middle_count+M_middle_count){
        return findRecursive(nums1, nums2, N_s+N_left_count, N_s+N_left_count+N_middle_count-1, M_s+M_left_count, M_s+M_left_count+M_middle_count-1, rank-(N_left_count+M_left_count));
    }
    else{
        return findRecursive(nums1, nums2, N_s+N_left_count+N_middle_count, N_s+N_left_count+N_middle_count+N_right_count-1, M_s+M_left_count+M_middle_count, M_s+M_left_count+M_middle_count+M_right_count-1, rank-(N_left_count+M_left_count+N_middle_count+M_middle_count));
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double med=findRecursive(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, (nums1.size()+nums2.size())/2+1);
    if((nums1.size()+nums2.size())%2==1)
        return med;
    else{
        med+=findRecursive(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, (nums1.size()+nums2.size())/2);
        med/=2;
        return med;
    }
}
};
