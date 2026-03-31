#include<bits/stdc++.h>
using namespace std;

void sort0s1s2s1(vector<int> &arr,int n){
    // Brute force using sort
    // TC: O(nlogn)
    // SC: O(1)
    sort(arr.begin(),arr.end());
}

void sort0s1s2s2(vector<int> &arr, int n){
    // Better solution by counting 0's, 1's, 2's
    // TC: O(2n)
    // SC: O(1)
    int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
    }
    for(int i=0;i<n;i++){
        if(i<cnt0) arr[i]=0;
        else if(i<cnt0+cnt1) arr[i]=1;
        else arr[i]=2;
    }
}

void sort0s1s2s3(vector<int> &arr, int n){
    // Optimal approach using Dutch flag
    // TC: O(n)
    // SC: O(1)
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[low],arr[high]);
            high--;
        }
    }
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort0s1s2s3(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}