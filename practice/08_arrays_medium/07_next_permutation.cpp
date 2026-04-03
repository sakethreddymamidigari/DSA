#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums, int n){
    // TC: O(2*n)
    // SC: O(1)
    int ind=-1;
    // checking the pivot index
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            ind=i;
            break;
        }
    }

    // if pivot not found then the reverse the nums
    if(ind==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    else{
        // else swap if nums[pivot] with smallest value such that the value>nums[pivot]
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        // reversing the all element after pivot index which are in reverse sorted order after swap
        reverse(nums.begin()+ind+1,nums.end());
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    nextPermutation(nums,n);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
}