/*
    Merge two sorted arrays without using extra space

    Input:
    5 6
    1 3 5 6 8
    2 4 7 9 10 11

    Output:
    1 2 3 4 5
    6 7 8 9 10 11
*/

#include<bits/stdc++.h>
using namespace std;
/*
    Brute force
    TC: O(2(n+m))
    SC: O(n+m)
    adding all elements to another arrays in sorted ordered, then adding elements back to two arrays in same order
*/


// Approach 2

void mergeArrays1(vector<int> &nums1, vector<int> &nums2, int n, int m){
    // Optimal solution 1
    // TC: O(min(n,m)+nlogn+mlogm)
    // SC: O(1)
    int i=n-1,j=0;
    while(i>=0 && j<m){
        if(nums1[i]>nums2[j]){
            swap(nums1[i],nums2[j]);
            i--;
            j++;
        }
        else break;
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    return ;
}

// Approach 3
// Using gap method

void swapElements(vector<int> &nums1, vector<int> &nums2, int i, int j){
    if(nums1[i]>nums2[j]) swap(nums1[i],nums2[j]);
}

void mergeArrays2(vector<int> &nums1, vector<int> &nums2, int n, int m){
    // otpimal solution 2
    // TC:O(logn*(n+m))
    // SC: O(1)
    int len=n+m;
    int gap=len/2 +len%2;
    while(gap>0){  // logn
        int left=0;
        int right=left+gap;
        while(right<len){   // (n+m) 

            if(left<n && right>=n)   swapElements(nums1,nums2,left,right-n);  // l in nums1 && r in nums2

            else if(left>=n)    swapElements(nums2,nums2, left-n,right-n);    // l && r in nums2

            else    swapElements(nums1,nums1, left,right);                    // l && r in nums1
            left++, right++;
        }
        if(gap==1) break;
        gap=gap/2+gap%2;
    }
    
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0;i<n;i++) cin>>nums1[i];
    for(int j=0;j<m;j++) cin>>nums2[j];
    mergeArrays2(nums1,nums2,n,m);
    for(int i=0;i<n;i++) cout<<nums1[i]<<" ";
    cout<<endl;
    for(int j=0;j<m;j++) cout<<nums2[j]<<" ";
}