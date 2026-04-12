
#include<bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray1(vector<int> nums, int n,int t){
/*     
       searching an element in rotated sorted array(without duplicates)
       TC: O(logn)
       SC: O(1)

       inputs:
       n=10 t=9
       arr=[7 8 9 10 1 2 3 4 5 6]

       output:
       2
*/
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==t) return mid;
        if(nums[low]<=nums[mid]){
            if(nums[low]<=t && t<=nums[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(nums[mid]<=t && t<=nums[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<searchInRotatedSortedArray1(nums,n,t);
}