#include<bits/stdc++.h>
using namespace std;
int secondLargestEle1(vector<int> &arr,int n){
    // brute force approach using sort function
    // O(nlogn)
    sort(arr.begin(),arr.end());
    return arr[n-2];
}

int secondLargestEle2(vector<int> &arr,int n){
    // optimal solution by single pass
    // O(n)
    int largest=INT_MIN;
    int slargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]!=largest && arr[i]>slargest) slargest=arr[i];
    }
    return slargest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<< secondLargestEle2(arr,n);
}