#include<bits/stdc++.h>
using namespace std;

int minimumFallingPath1(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    // TC: O(n*m)
    // SC: O(n+(n*m))
    if(j<0 || j>=matrix[0].size())  return -1e9;
    if(i==0) return matrix[0][j];

    if (dp[i][j]!=-1) return dp[i][j];

    int u=matrix[i][j]+ minimumFallingPath1(i-1,j,matrix,dp);
    int b=matrix[i][j]+ minimumFallingPath1(i-1,j-1,matrix,dp);
    int f=matrix[i][j]+ minimumFallingPath1(i-1,j+1,matrix,dp);

    return dp[i][j]= max(u,max(b,f));
}

int minimumFallingPath2(int n,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    // TC: O(n*m)
    // SC: O(n*m)

    for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int u=matrix[i][j]+dp[i-1][j];

            int b=matrix[i][j];
            if(j-1>=0) b+=dp[i-1][j-1];
            else b+-1e9;

            int f=matrix[i][j];
            if(j+1<m) f+=dp[i-1][j+1];
            else  f+=-1e9;

            dp[i][j]=max(u,max(f,b));
        }
    }
    
    int maxi=-1e9;
    for(int j=0;j<m;j++) maxi=max(maxi,dp[n-1][j]);
    return maxi;
}

int minimumFallingPath3(int n, int m,vector<vector<int>> &matrix){
    // TC: O(n*m)
    // SC: O(2m)
    vector<int> prev(m,0), cur(m,0);

    for(int j=0;j<m;j++) prev[j]=matrix[0][j];

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int u=matrix[i][j]+prev[j];

            int b=matrix[i][j];
            if(j-1>=0) b+=prev[j-1];
            else b+-1e9;

            int f=matrix[i][j];
            if(j+1<m) f+=prev[j+1];
            else  f+=-1e9;

            cur[j]=max(u,max(f,b));
        }
        prev=cur;
    }
    
    int maxi=-1e9;
    for(int j=0;j<m;j++) maxi=max(maxi,prev[j]);
    return maxi;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    vector<vector<int>> dp(n,vector<int> (m,-1));
    /* Memoization
    int maxi=-1e9;
    for(int j=0;j<m;j++) maxi=max(maxi,minimumFallingPath1(n-1,j,matrix,dp));
    cout<<maxi;
    */

    // Tabulation cout<<minimumFallingPath2(n,m,matrix,dp);

    cout<<minimumFallingPath3(n,m,matrix);


    
}