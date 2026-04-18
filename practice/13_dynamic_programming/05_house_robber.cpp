/*
    maximum sum of non adjacent element
*/

#include<bits/stdc++.h>
using namespace std;

int houseRobber1(vector<int> &house, vector<int> &dp, int n){
    // memoization method
    // TC: O(n)
    // SC: O(2n)
    if(n==0) return house[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=house[n]+houseRobber1(house,dp,n-2);
    int notPick=houseRobber1(house,dp,n-1);
    return dp[n]=max(pick,notPick);
}

int houseRobber2(vector<int> &house,vector<int> &dp, int n){
    // Tabulation
    // TC: O(n)
    // SC: O(n)
    dp[0]=house[0];
    for(int i=1;i<n;i++){
        int pick=house[i];
        if(i>1) pick+=dp[i-2];
        int notPick=dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];

}

int houseRobber3(vector<int> &house, int n){
    // Space Optmization
    // TC: O(n)
    // SC: O(1)
    int prev1=house[0],prev2=0;
    for(int i=0;i<n;i++){
        int pick=house[i];
        if(i>1) pick+=prev2;
        int notPick=prev1;
        int current=max(pick,notPick);
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    vector<int> house(n);
    for(int i=0;i<n;i++) cin>>house[i];
    vector<int> dp(n,-1);
    // cout<<houseRobber1(house,dp,n-1); // Memoization
    // cout<<houseRobber2(house,dp,n);   // Tabulation
    cout<<houseRobber3(house,n);        // Space Optimization
}