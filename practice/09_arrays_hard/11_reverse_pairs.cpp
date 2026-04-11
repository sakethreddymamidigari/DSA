/*
    Reverse Pairs
    arr[i]>2*arr[j]  &&  i>j

    Input:
    7
    40 25 19 12 9 6 2

    Output:
    15

    Optimal Solution
    TC: O(2*nlogn)
    SC: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low , int mid, int high){
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

void cntPairs(vector<int> arr,int low,int mid,int high, int &cnt){
    int right=mid+1;
    for(int left=low;left<=mid;left++){
        while(right<=high && arr[left]>2*arr[right]) right++;
        cnt+=right-(mid+1);
    }
    return;
}

void divArray(vector<int> &arr,int low,int high,int &cnt) {
    if(low>=high) return;
    int mid=(low+high)/2;
    divArray(arr,low,mid,cnt);
    divArray(arr,mid+1,high,cnt);
    cntPairs(arr,low,mid,high,cnt);
    merge(arr,low,mid,high);
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