#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> dp(n,1),hash(n);
    int maxi=-1,lastInd=-1;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<=i;prev++){
            if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]) {
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastInd=i;
        }
    }

    vector<int> lis;
    lis.push_back(nums[lastInd]);
    while(lastInd!=hash[lastInd]){
        lastInd=hash[lastInd];
        lis.push_back(nums[lastInd]);
    }
    reverse(lis.begin(),lis.end());
    for(auto it:lis) cout<<it<<" ";
}