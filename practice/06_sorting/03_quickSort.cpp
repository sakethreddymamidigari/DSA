#include<bits/stdc++.h>
using namespace std;
int sort(vector<int> &arr, int low , int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>pivot && j>=low+1) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void qDivide(vector<int> &arr,int low,int high) {
    if(low<high){
        int pIndex= sort(arr,low,high);
        qDivide(arr,pIndex+1,high);
        qDivide(arr,low,pIndex-1);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    qDivide(arr,0,n-1);
    for(int x: arr) cout<<x<<" ";
}