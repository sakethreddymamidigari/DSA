#include<bits/stdc++.h>
using namespace std;

int frogJumps1(vector<int> heights, int n, vector<int> &dp){
    // Brute force using MEMOIZATION
    // Using dp array to reduce multiple recursions
    // TC: O(n)
    // SC: O(2*n)
    if(n==0) return n;
    if(dp[n]!=0) return dp[n];
    int jump1=frogJumps1(heights,n-1,dp)+abs(heights[n]-heights[n-1]);
    int jump2=INT_MAX;
    if(n>1) jump2=frogJumps1(heights,n-2,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(jump1,jump2);

}

int frogJumps2(vector<int> heights, int n, vector<int> &dp){
    // Better solution using TABULATION
    // Using dp[i] to store the min cost to reach heights[i]
    // TC:O(n)
    // SC:O(n)
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int jump1= dp[i-1]+abs(heights[i]-heights[i-1]);
        int jump2=INT_MAX;
        if(i>1) jump2=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(jump1,jump2);
    }
    return dp[n];
}

int frogJump3(vector<int> heights,int n){
    // Optimal solution
    // TC: O(n)
    // SC: O(1)
    int prev1=0,prev2=0;
    for(int i=1;i<n;i++){
        int jump1=prev2+abs(heights[i]-heights[i-1]);
        int jump2=INT_MAX;
        if(i>1) jump2=prev1+abs(heights[i]-heights[i-2]);
        int mini=min(jump1,jump2);
        prev1=prev2;
        prev2=mini;
    }
    return prev2;

}

int main(){
    int n,m;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];

    // for Brute force and better approach
    // vector<int> dp(n);
    // cout<<frogJumps2(heights,n-1,dp);

    // for Optimal approach
    cout<<frogJump3(heights,n);
}