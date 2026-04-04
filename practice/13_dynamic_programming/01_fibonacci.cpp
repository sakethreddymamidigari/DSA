#include<bits/stdc++.h>
using namespace std;
int fibonacci1(int n,vector<int> &dp){
    // Using memoization(top down approach)
    // TC: O(n)
    // SC: O(2*n)::{O(n) recursion stack space + O(n) for vector dp}
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacci1(n-1,dp)+fibonacci1(n-2,dp);
}

int fibonacci2(int n,vector<int> dp){
    // Using tabulation(bottom up approach)
    // TC: O(n)
    // SC: O(n) 
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int fibonacci3(int n){
    // Memory optimization 
    // TC: O(n)
    // SC: O(1)
    int prev1=0,prev2=1;
    for(int i=2;i<=n;i++){
        int sum=prev1+prev2;
        prev1=prev2;
        prev2=sum;
    }
    return  prev2;
}

int main(){
    int n;
    cin>>n;
    //vector<int> dp(n+1,-1);
    //cout<<fibonacci1(n,dp)<<fibonacci2(n,dp);
    cout<<fibonacci3(n);
}