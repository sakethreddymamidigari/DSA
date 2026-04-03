#include<bits/stdc++.h>
using namespace std;
int buyAndSellStock(vector<int> arr, int n){
    // TC: O(n)
    // SC: O(1)
    int mini=arr[0], profit=0;
    for(int i=1;i<n;i++){
        mini=min(mini,arr[i-1]);
        int cost=arr[i]-mini;
        profit=max(profit,cost);
    }
    return profit;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<buyAndSellStock(arr,n);
}