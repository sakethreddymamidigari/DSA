// Get the max profit by unlimited Transaction but each transaction contains a fixed fee 
#include<bits/stdc++.h>
using namespace std;

int buyAndSellStocks1(int i, int n, int buy, vector<int> price,int fee,vector<vector<int>> &dp){
    if (i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=0;
    if(buy){
        profit=max(-price[i]+buyAndSellStocks1(i+1,n,0,price,fee,dp),
                                                buyAndSellStocks1(i+1,n,1,price,fee,dp));
    }
    else profit=max(price[i]-fee+buyAndSellStocks1(i+1,n,1,price,fee,dp),
                                                buyAndSellStocks1(i+1,n,0,price,fee,dp));
    return dp[i][buy]=profit;
}


int buyAndSellStocks2(int n,int fee,vector<int> price){
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy) profit=max(-price[i]+dp[i+1][0],dp[i+1][1]);
            else profit=max(price[i]-fee+dp[i+1][1],dp[i+1][0]);
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}

int buyAndSellStocks3(int n,int fee,vector<int> price){
    vector<int> dp(2,0), cur(2,0);
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy) profit=max(-price[i]+dp[0],dp[1]);
            else profit=max(price[i]-fee+dp[1],dp[0]);
            cur[buy]=profit;
        }
        dp=cur;
    }
    return dp[1];
}

int main(){
    int n,fee;
    cin>>n>>fee;
    vector<int> price(n);
    for(int i=0;i<n;i++) cin>>price[i];

    // Memoization
    // vector<vector<int>> dp(n,(vector<int> (2,-1)));
    // cout<<buyAndSellStocks1(0,n,1,price,fee,dp);

    // Tabulation
    // cout<<buyAndSellStocks2(n,fee,price);

    // Space Optimization
    cout<<buyAndSellStocks3(n,fee,price);
}