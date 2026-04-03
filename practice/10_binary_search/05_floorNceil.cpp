#include<bits/stdc++.h>
using namespace std;
pair<int,int> floorAndCeil(vector<int> nums,int low, int n, int t){
    // Finding the floor and ceil in an array
    // Floor is the largest index such nums[ind]<=t
    // Ceil is the smallest index such nums[ind]>=t
    // TC: O(logn)
    // SC: O(1)
    int high=n-1;
    int floor=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]<=t){
            floor=nums[mid];
            low=mid+1;
        }
        else high=mid-1;
    }
    low=0, high=n-1;
    int ceil=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=t){
            ceil=nums[mid];
            high=mid-1;
        }
        else low=mid+1;
    }
    return {floor,ceil};
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(10);
    for(int i=0;i<n;i++) cin>>nums[i];
    pair<int,int> res= floorAndCeil(nums,0,n-1,t);
    cout<<res.first<<" "<<res.second;
}
