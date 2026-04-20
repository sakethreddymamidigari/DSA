#include<bits/stdc++.h>
using namespace std;

int uniquePathsInGrid1(int n,int m, vector<vector<int>> &dp){
    // Memoization 
    // TC: O(n*m)
    // SC: O((n+m)+n*m)
    if(n==0 && m==0) return 1;
    if(n<0 || m<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int up=uniquePathsInGrid1(n-1,m,dp);
    int left=uniquePathsInGrid1(n,m-1,dp);
    return dp[n][m]=up+left;
}

int uniquePathsInGrid2(int n,int m, vector<vector<int>> &dp){
    // Tabulation
    // TC: O(n*m)
    // SC: O(n*m)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
}

int uniquePathsInGrid3(int n,int m){
    // Space Optimization
    // TC: O(n*m)
    // SC: O(m)
    vector<int> prevDP(m);
    for(int i=0;i<n;i++){
        vector<int> cur(m);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) cur[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=prevDP[j];
                if(j>0) left=cur[j-1];
                cur[j]=left+up;
            }
        }
        prevDP=cur;
    }
    return prevDP[m-1];
}

int main(){
    int n,m;
    cin>>n>>m;
    // vector<vector<int>> dp(n,vector<int> (m,-1));  for Memoization and tabulation
    // cout<<uniquePathsInGrid1(n-1,m-1, dp);   // Memoization
    // cout<<uniquePathsInGrid2(n,m,dp);        // Tabulation
    cout<<uniquePathsInGrid3(n,m);
    
}