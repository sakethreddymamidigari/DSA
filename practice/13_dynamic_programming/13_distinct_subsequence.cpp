#include<bits/stdc++.h>
using namespace std;

int distinctSubsequence1(int n1,int n2, string &s1, string &s2, vector<vector<int>> dp){
    if(n2==0) return 1;
    if(n1==0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1-1]==s2[n2-1]) return dp[n1][n2]=distinctSubsequence1(n1-1,n2-1,s1,s2,dp)+distinctSubsequence1(n1-1,n2,s1,s2,dp);
    return dp[n1][n2]=distinctSubsequence1(n1-1,n2,s1,s2,dp);
}

int distinctSubsequence2(int n1,int n2,string &s1,string &s2){
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    for(int i=0;i<=n1;i++) dp[i][0]=1;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n1][n2];
    
}

int distinctSubsequence3(int n1,int n2,string &s1,string &s2){
    vector<int> dp(n2+1,0);
    dp[0]=1;
    for(int i=1;i<=n1;i++){
        for(int j=n2;j>=1;j--){
            if(s1[i-1]==s2[j-1]) dp[j]=dp[j-1]+dp[j];
            else dp[j]=dp[j];
        }
    }
    return dp[n2];
    
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    string s1,s2;
    cin>>s1>>s2;

    // Memoization
    // vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
    // cout<<distinctSubsequence1(n1,n2,s1,s2,dp);

    // Tabulation
    // cout<<distinctSubsequence2(n1,n2,s1,s2);

    // Space Optimization
    cout<<distinctSubsequence3(n1,n2,s1,s2);
}