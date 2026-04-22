#include<bits/stdc++.h>
using namespace std;

bool subsetSum1(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
    // TC: O(n*target)
    // SC: O(n*target+n)
    if(target==0) return true;
    if(i==0) return (nums[0]==target);
    if(dp[i][target]!=-1) return dp[i][target];
    bool notTake=subsetSum1(i-1,target,nums,dp);
    bool take=false;
    if(nums[i]<=target) take=subsetSum1(i-1,target-nums[i],nums,dp);
    return dp[i][target]=take | notTake;
}


bool subsetSum2(int n,int target,vector<int> &nums){
    // TC: O(n*target)
    // SC: O(n*target)
    vector<vector<bool>> dp(n,vector<bool> (target+1,false));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(nums[0]<=target) dp[0][nums[0]]=true;
    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            bool notTake=dp[i-1][t];
            bool take=false;
            if(nums[i]<=t) take=dp[i-1][t-nums[i]];
            dp[i][t]= notTake | take;
        }
    }
    return dp[n-1][target];
}

bool subsetSum3(int n,int target,vector<int> &nums){
    // TC: O(n*target)
    // SC: O(target)
    vector<bool> front(target+1,0), cur(target+1,0);
    front[0]=cur[0]=true;

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            bool notTake=front[t];
            bool take=false;
            if(nums[i]<=t) take=front[t-nums[i]];
            cur[t]= notTake | take;
        }
        front=cur;
    }
    return front[target];
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    // Memoization
    // vector<vector<int>> dp(n,vector<int> (target+1,-1));
    // cout<<subsetSum1(n-1,target,nums,dp);

    // Tabulation
    // cout<<subsetSum2(n,target,nums);

    // Space Optimization
    // cout<<subsetSum3(n,target,nums);
}