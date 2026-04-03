#include<bits/stdc++.h>
using namespace std;
int upperBound(vector<int> nums,int low, int high, int t){
    // Upper bound is the smallest index such that nums[ind]>=t
    // TC: O(logn)
    // SC: O(1)
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>t){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(10);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<upperBound(nums,0,n-1,t);
}
