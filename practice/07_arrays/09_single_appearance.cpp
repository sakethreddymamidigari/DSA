#include<bits/stdc++.h>
using namespace std;
int singleAppearance1(vector<int> arr,int n){
    // Brute force
    // TC: O(n^2)
    // SC: O(1)
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==arr[i]) cnt++;
        }
        if(cnt<2) return arr[i];
    }
}

int singleAppearance2(vector<int> arr,int n){
    // Better solution using hash array
    // TC: O(n+n+k) k=max element in the i/p array
    // SC: O(k)
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }

    vector<int> freq(maxi+1,0);

    for(int i=0;i<n;i++) freq[arr[i]]++;

    for(int i=0;i<=maxi;i++){
        if(freq[i]==1) return i;
    }
    return -1;
}

int singleAppearance3(vector<int> arr,int n){
    // Optimal solution using XOR
    // TC: O(n)
    // SC: O(1)
    int XOR1=0;
    for(int i=0;i<n;i++) XOR1^=arr[i];
    return XOR1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<singleAppearance3(arr,n);

}