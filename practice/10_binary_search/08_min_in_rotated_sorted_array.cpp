
#include<bits/stdc++.h>
using namespace std;

int minInRotatedSortedArray1(vector<int> nums, int n,int t){
/*     
       searching minimum in rotated sorted array(without duplicates)
       TC: O(logn)
       SC: O(1)

       inputs:
       n=10
       arr=[7 8 9 10 1 2 3 4 5 6]

       output:
       1
*/
    int low=0,high=n-1,ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<nums[high]){
            ans=min(ans,nums[low]);
            break;
        }
        if(nums[low]<nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<minInRotatedSortedArray1(nums,n,t);
}