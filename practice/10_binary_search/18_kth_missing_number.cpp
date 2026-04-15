/*
    finding the kth positive missing element in the given arr
    TC: O(logn)
    SC: O(1)

    Input:
    n=5 k=5
    2 3 4 7 11

    Output:
    9
    missing nums are:
    1st=1
    2nd=5
    3rd=6
    4th=8
    5th=9
*/

#include<bits/stdc++.h>
using namespace std;

int kThMissingNum(vector<int> nums,int n,int k){
    // O(logn)
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=nums[mid]-(mid+1);
        if(missing<k) low=mid+1;
        else high=mid-1;
    }
    return low+k;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<kThMissingNum(nums,n,k);
}