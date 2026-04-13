
#include<bits/stdc++.h>
using namespace std;

int uniqueInSortedArray1(vector<int> nums, int n){
    /*     
        printing the unique element in a sorted array
        TC: O(logn)
        SC: O(1)

        inputs:
        n=11
        arr=[1 1 2 2 3 3 4 4 5 6 6]

        output:
        5
    */
    int low=1,high=n-2;
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        if(((mid%2==1) && nums[mid]==nums[mid-1]) || ((mid%2==0) && nums[mid]==nums[mid+1])) low=mid+1;
        else high=mid-1;
    }
        
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<uniqueInSortedArray1(nums,n);
}