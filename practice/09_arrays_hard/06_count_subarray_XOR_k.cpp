// print the count of subarrays who XOR of elements equal to k

#include<bits/stdc++.h>
using namespace std;

int subArrayXOR(vector<int> nums,int n,int k){
    // TC: O(n)
    // SC: O(n)
    int cnt=0,xr=0;
    unordered_map<int,int> prev;
    prev[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^nums[i];
        int x=xr^k;
        cnt+=prev[x];
        prev[xr]++;
    }
    return cnt;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<subArrayXOR(nums,n,k);
}