// print 4 element whose sum equal to the target

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums,int n,int t){
    // Optimal solution
    // TC: O(n^3+nlogn)
    // SC: O(4m)
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1,l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum+=nums[k]+nums[l];
                if(sum<t) k++;
                else if(sum>t) l--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<int>> ans=fourSum(nums,n,t);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}