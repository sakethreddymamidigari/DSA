#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> dp1(n,1),dp2(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i] && 1+dp1[prev]>dp1[i]) {
                dp1[i]=1+dp1[prev];
            }
        }
    }

    int maxi=1;
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]) {
                dp2[i]=1+dp2[prev];
            }
        }
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }

    cout<<maxi;

}
