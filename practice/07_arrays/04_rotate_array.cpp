#include<bits/stdc++.h>
using namespace std;

void leftRotateBy1(vector<int> &arr, int n,int d){
    // Left rotating an array by 1 element
    // O(n)
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return;
}
void leftRotateByD1(vector<int> &arr, int n,int d){
    // Left rotating an array by "D" element
    // Brute force approach using extra space O(d)
    // TC: O(d+n-d+d)==>O(n+d)
    // SC:O(d)
    d=d%n;
    vector<int> temp(arr.begin(),arr.begin()+d);  // O(d)
    for(int i=d;i<n;i++){                         // O(n-d)
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){                       // O(d)
        arr[i]=temp[i-(n-d)];
    }
}
void leftRotateByD2(vector<int> &arr, int n,int d){
    // Left rotating an array by "D" element
    // Optimal approach without using any extra spaces
    // TC:O(d+n-d+n) ==> O(2*n)
    // SC:O(1)
    d=d%n;
    reverse(arr.begin(), arr.begin()+d); // O(d)
    reverse(arr.begin()+d, arr.end());   // O(n-d)
    reverse(arr.begin(), arr.end());     // O(n)
}
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    leftRotateByD2(arr,n,d);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}