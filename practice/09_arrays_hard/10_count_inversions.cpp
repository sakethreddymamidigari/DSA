/*
    Count inversions
    
*/

#include<bits/stdc++.h>
using namespace std;
void cntInversions(vector<int> &arr, int low , int mid, int high, int &cnt){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
            cnt++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void divArray(vector<int> &arr,int low,int high,int &cnt) {
    if(low>=high) return;
    int mid=(low+high)/2;
    divArray(arr,low,mid,cnt);
    divArray(arr,mid+1,high,cnt);
    cntInversions(arr,low,mid,high,cnt);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    divArray(arr,0,n-1,cnt);
    cout<<cnt;
}