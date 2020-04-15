//
//  排序-归并排序的归并-88.c
//  LeetCodePlayground
//
//  Created by 兆吉 王 on 2020/3/23.
//  Copyright © 2020 兆吉 王. All rights reserved.
//
//归并排序子过程
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1;
    int j=0;
    for(;i>=0;i--) nums1[i+n]=nums1[i];
    i=n;
    int k=0;
    while(i!=m+n and j!=n){
        if(nums1[i]<=nums2[j]) nums1[k++]=nums1[i++];
        else nums1[k++]=nums2[j++];
    }
    if(i==m+n) while(j!=n) nums1[k++]=nums2[j++];
    else while(i!=m+n) nums1[k++]=nums1[i++];
}
