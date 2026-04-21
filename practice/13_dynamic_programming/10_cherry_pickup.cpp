#include<bits/stdc++.h>
using namespace std;

int exploreAliceAndBobPaths1(int i,int j1,int j2,int r,int c,vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp){
    // Memoization
    if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;
    if(i==r-1){
        if(j1==j2) return matrix[i][j1];
        else return matrix[i][j1]+matrix[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2) value=matrix[i][j1];
            else value=matrix[i][j1]+matrix[i][j2];
            value+=exploreAliceAndBobPaths1(i+1,j1+dj1,j2+dj2,r,c,matrix,dp);
            maxi=max(maxi,value);
        }
    }

    return dp[i][j1][j2]=maxi;
}

int exploreAliceAndBobPaths2(int n,int m,vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp){
    // Tabulation
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j2]=matrix[n-1][j1];
            else dp[n-1][j1][j2]=matrix[n-1][j1]+matrix[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){

                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){

                        int value=0;
                        if(j1==j2) value=matrix[i][j1];
                        else value=matrix[i][j1]+matrix[i][j2];
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) value+=dp[i+1][j1+dj1][j2+dj2];
                        else value+=-1e8;
                        maxi=max(maxi,value);

                    }
                }

                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

int exploreAliceAndBobPaths3(int n,int m,vector<vector<int>> &matrix){
    // Space Optimization
    vector<vector<int>> front(m,vector<int> (m,0)),current(m,vector<int> (m,0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) front[j1][j2]=matrix[n-1][j1];
            else front[j1][j2]=matrix[n-1][j1]+matrix[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){

                int maxi=-1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){

                        int value=0;
                        if(j1==j2) value=matrix[i][j1];
                        else value=matrix[i][j1]+matrix[i][j2];
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) value+=front[j1+dj1][j2+dj2];
                        else value+=-1e8;
                        maxi=max(maxi,value);

                    }
                }
                current[j1][j2]=maxi;
            }
        }
        front =current;
    }
    return front[0][m-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
    // cout<<exploreAliceAndBobPaths1(0,0,m-1,n,m,matrix,dp);

    // cout<<exploreAliceAndBobPaths2(n,m,matrix,dp);

    cout<<exploreAliceAndBobPaths3(n,m,matrix);
}