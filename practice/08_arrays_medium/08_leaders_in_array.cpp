#include<bits/stdc++.h>
using namespace std;
vector<int> leadersInArray(vector<int> nums,int n){
    // TC: O(n)
    // SC: O(n)
    vector<int> ans;
    ans.push_back(nums[n-1]);
    for(int i=n-2;i>=0;i--){
        if(ans.back()<nums[i]) ans.push_back(nums[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> ans=leadersInArray(nums,n);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}