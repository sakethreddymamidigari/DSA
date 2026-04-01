// max sum of sub array sum using "KADANE'S ALGO"
#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> maxSumArray1(vector<int> arr, int n){
    // Brute force approach
    // TC: O(n^2)
    // SC: O(1)
    int maxSum=INT_MIN,left=0,right=0;
    for(int i=0;i<n;i++){
        int sum=0,start=i;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxSum){
                left=start;
                right=j;
                maxSum=sum;
            }
        }
    }
    return {left,right,maxSum};
}

tuple<int,int,int> maxSumArray2(vector<int> arr, int n){
    // Optimal approach using Kadane's Algo
    // TC: O(n)
    // SC: O(1)
    int sum=0,maxSum=INT_MIN,start,left=0,right=0;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum>maxSum){
            maxSum=sum;
            left=start;
            right=i;
        }
        if(sum<0) sum=0;
    }
    return {left,right,maxSum};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    auto[left,right,maxSum]=maxSumArray2(arr,n);
    cout<< left<<" "<<right<<","<<maxSum;

}