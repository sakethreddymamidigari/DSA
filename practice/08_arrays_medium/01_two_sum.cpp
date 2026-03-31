#include<bits/stdc++.h>
using namespace std;
bool twoSum1(vector<int> arr, int n, int k){
    // Brute force approach
    // TC: ~O(n^2)
    // SC: O(1)
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k) return true;
        }
    }
    return false;
}

bool twoSum2(vector<int> arr, int n, int k){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int rem=k-arr[i];
        if(mp.find(rem)!=mp.end()) return true;
        mp[arr[i]]=i;
    }
    return false;
}

bool twoSum3(vector<int> arr, int n, int k){
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==k) return true;
        else if(arr[i]+arr[j]>k) j--;
        else i++;
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<twoSum3(arr,n,k);
}