#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> nums,int low, int high, int t){
    // TC: O(logn)
    // SC: O(1)
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==t) return mid;
    else if(nums[mid]>t) binarySearch(nums,mid+1,high,t);
    else binarySearch(nums,low,mid-1,t);
    return -1;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(10);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<binarySearch(nums,0,n-1,t);
}