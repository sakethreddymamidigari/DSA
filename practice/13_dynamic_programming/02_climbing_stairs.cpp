#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n,vector<int> &dp){
    // Using memoization(top down approach)
    // TC: O(n)
    // SC: O(2*n)::{O(n) recursion stack space + O(n) for vector dp}
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=climbStairs(n-1,dp)+climbStairs(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<climbStairs(n,dp);
}