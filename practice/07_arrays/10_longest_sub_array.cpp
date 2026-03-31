// finding the longest sub array with sum =k
// for positives and (positives and negetives)
#include<bits/stdc++.h>
using namespace std;

int longestSubArray1(vector<int> arr, int n,int k){
    // Brute force approach
    // TC: O(n^2)
    // SC: O(1)
    int maxLen=0;

    for(int i=0;i<n;i++){
        int sum=0;

        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k)  maxLen=max(maxLen,j-i+1);
        }
    }
    return maxLen;
}

int longestSubArray2(vector<int> arr, int n, int k){
    // Better if only positives 
    // Optimal if positives and negetives elements in the array
    // TC: O(n*logn) if ordered_map else O(n) if unordered_map on average case
    // SC: O(n)
    map<long long,int> preHashmap;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) maxLen=max(maxLen,i+1);
        long long rem=sum-k;
        if(preHashmap.find(rem)!=preHashmap.end()){
            int len=i-preHashmap[rem];
            maxLen=max(maxLen,len);
        }
        if(preHashmap.find(sum)==preHashmap.end()) preHashmap[sum]=i;  //O(logn)
    }
    return maxLen;
}

int longestSubArray3(vector<int> arr, int n, int k){
    // Optimal solution if only positive elements in the array
    // TC: O(2*n)
    // SC: O(1)
    long long sum=0;
    int maxLen=0,left=0,right=0;
    while(right<n){
        sum+=arr[right];
        while(left<right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k) {
            maxLen=max(maxLen,right-left+1);
        }
        right++;
    }
    return maxLen;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<longestSubArray3(arr,n,k);
}