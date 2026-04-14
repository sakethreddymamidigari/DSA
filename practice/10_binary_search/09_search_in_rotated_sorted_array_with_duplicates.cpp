
#include<bits/stdc++.h>
using namespace std;

bool searchInRotatedSortedArray1(vector<int> nums, int n,int t){
/*     
       searching an element in rotated sorted array(with duplicates)
       TC: O(logn) on an avg cases but at worst case O(n/2)
       SC: O(1)

       inputs:
       n=10 t=2
       arr=[6 8 9 10 1 2 4 4 6 6]

       output:
       1(true)
*/
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==t) return true;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=t && t<=nums[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(nums[mid]<=t && t<=nums[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return false;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<searchInRotatedSortedArray1(nums,n,t);
}