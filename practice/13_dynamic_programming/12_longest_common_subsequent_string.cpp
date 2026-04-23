#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequentString1(int n1,int n2,string s1,string s2,vector<vector<int>> &dp){
    if(n1==0 || n2==0) return 0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(s1[n1-1]==s2[n2-1]) return dp[n1][n2]=1+longestCommonSubsequentString1(n1-1,n2-1,s1,s2,dp);
    return dp[n1][n2]= max(longestCommonSubsequentString1(n1-1,n2,s1,s2,dp),longestCommonSubsequentString1(n1,n2-1,s1,s2,dp));
}

int longestCommonSubsequentString2(int n1,int n2,string s1,string s2){
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));

    for(int i=0;i<=n1;i++) dp[i][0]=0;
    for(int i=0;i<=n2;i++) dp[0][i]=0;

    for(int i=1;i<=n1;i++){

        for(int j=1;j<=n2;j++){

            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return dp[n1][n2];
}

int longestCommonSubsequentString3(int n1,int n2,string s1,string s2){
    vector<int> dp(n2+1,0);

    for(int i=1;i<=n1;i++){

        for(int j=1;j<=n2;j++){

            if(s1[i-1]==s2[j-1]) dp[j]=1+dp[j-1];
            else dp[j]= max(dp[j],dp[j-1]);

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
    // cout<<longestCommonSubsequentString1(n1,n2,s1,s2,dp);
    
    // Tabulation
    // cout<<longestCommonSubsequentString2(n1,n2,s1,s2);

    // Space Optimization
    cout<<longestCommonSubsequentString3(n1,n2,s1,s2);

}