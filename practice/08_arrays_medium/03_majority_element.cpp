#include<bits/stdc++.h>
using namespace std;

int majorityElement1(vector<int> arr,int n){
    // Brute force approach
    // TC: O(n^2)
    // SC: O(1)
    int mEle=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]) cnt++;
        }
        if(cnt>n/2) mEle=arr[i];
    }
    return mEle;
}

int majorityElement2(vector<int> arr,int n){
    // Better approach using Hashmap
    // O(2*n)
    // O(n)
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(auto it:freq){
        if(it.second >n/2) return  it.first;
    }
    return -1;
}

int majorityElement3(vector<int> arr,int n){
    // Otptimal approach by checking the dominating element
    // TC: O(2*n)
    // SC: O(1)
    int mEle;
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(cnt1==0){
            cnt1++;
            mEle=arr[i];
        }
        else if(arr[i]==mEle) cnt1++;
        else cnt1--;
    }
    int cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==mEle) cnt2++;
    }
    if(cnt2>n/2) return mEle;
    return -1;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<majorityElement3(arr,n);
}