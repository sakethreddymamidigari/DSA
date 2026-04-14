
#include<bits/stdc++.h>
using namespace std;

int minInRotatedSortedArray1(vector<int> nums, int n,int t){
/*     
       printing how many sorted array is rotated(without duplicates)
       TC: O(logn)
       SC: O(1)

       inputs:
       n=10
       arr=[7 8 9 10 1 2 3 4 5 6]

       output:
       4
*/
    int low=0,high=n-1,ans=INT_MAX,index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<nums[high]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
                break;
            }
        }
        if(nums[low]<nums[mid]){
            if(nums[low]<ans){
                ans=nums[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<minInRotatedSortedArray1(nums,n,t);
}