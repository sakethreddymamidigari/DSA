#include<bits/stdc++.h>
using namespace std;
int secondLargestEle1(vector<int> &arr,int n){
    // brute force approach using sort function
    // O(nlogn + n)
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>0;i--){
        if(arr[i]!=arr[i-1]) return arr[i-1];
    }
}

int secondLargestEle2(vector<int> &arr,int n){
    // optimal solution
    // O(n)
    int largest=arr[0];
    int slarge=0;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slarge=largest;
            largest=arr[i];
        }
        else if(arr[i]!=largest && arr[i]>slarge){
            slarge=arr[i];
        }
    }
    return slarge;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<< secondLargestEle2(arr,n);
}