// Remove duplicates in a sorted array
#include<bits/stdc++.h>
using namespace std;
set<int> removeDups1(vector<int> arr, int n) {
    // brute force approach using set
    // O(nlogn)
    set<int> arr1;
    for(int i=0;i<arr.size();i++) arr1.insert(arr[i]);
    return arr1;
}

void removeDups2(vector<int> &arr, int &n){
    // optimal solution using two pointers
    // O(n)
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    n=i+1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // Method 1
    /*
    set<int> result=removeDups1(arr,n);
    for(auto x:result){
        cout<<x<<" ";
    }
    */

    // Method 2
    removeDups2(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}