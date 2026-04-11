#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums, int n){
    // Optimal solution
    // TC: O(n)
    // SC: O(1)
    int pre=1,suf=1,ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suf==0) suf=1;
        pre*=nums[i];
        suf*=nums[n-i-1];
        ans=max(ans,max(pre,suf));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<maxProduct(nums,n);

}