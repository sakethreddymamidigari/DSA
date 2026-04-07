#include<bits/stdc++.h>
using namespace std;

int frogJumpWithK1(vector<int> heights,vector<int> &dp,int n,int k){
    if(n==0) return n;
    if(dp[n]!=0) return dp[n];
    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int jumpk=frogJumpWithK1(heights,dp,n-i,k)+abs(heights[n]-heights[n-i]);
            mini=min(mini,jumpk);
        }
    }
    return dp[n]=mini;



}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    vector<int> dp(n);
    cout<<frogJumpWithK1(heights,dp,n-1,k);
}