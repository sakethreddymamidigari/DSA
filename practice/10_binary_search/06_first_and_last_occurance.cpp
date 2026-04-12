#include<bits/stdc++.h>
using namespace std;

pair<int,int> firstAndLast1(vector<int> nums, int n,int t){
    // TC: 2*O(logn)
    // SC: O(1)
    auto lb=lower_bound(nums.begin(),nums.end(),t)-nums.begin();
    if(lb == n || nums[lb]!=t) return {-1,-1};
    auto ub=upper_bound(nums.begin(),nums.end(),t)-nums.begin();
    return {lb,ub-1};
}

pair<int,int> firstAndLast2(vector<int> nums, int n, int t){
    // TC: 2*O(logn)
    // SC: O(1)
    int low=0,high=n-1;
    int first=-1,last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==t){
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]>t) high=mid-1;
        else low=mid+1;
    }
    low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==t){
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]>t) high=mid-1;
        else low=mid+1;
    }
    return {first, last};

}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>> nums[i];
    pair<int,int> num = firstAndLast1(nums,n,t);
    cout<<num.first<<" "<<num.second;
}