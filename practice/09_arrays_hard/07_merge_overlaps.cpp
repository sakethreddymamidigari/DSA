/* 
merging the overlapping interval

inputs

n=8
[1,3] [2,6] [8,9] [9,11] [8,10] [2,4] [15,18] [16,17]


output

[1,6] [8,11] [15,18]

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlaps1(vector<vector<int>> nums,int n){
    // Brute force 
    // TC: O(2n)
    // SC: O(m)   m=ans.size()
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        int start=nums[i][0];
        int end=nums[i][1];
        if(!ans.empty() && end<=ans.back()[1]) continue;

        for(int j=i+1;j<n;j++){
            if(nums[j][0]<=end)  end = max(nums[j][1],end);
            else break;
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> mergeOverlaps2(vector<vector<int>> nums,int n){
    // Optimal solution
    // TC: O(n)
    // SC: O(m)   m=ans.size()
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || nums[i][0]>ans.back()[1]) ans.push_back(nums[i]);
        else ans.back()[1]=max(ans.back()[1],nums[i][1]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2));
    for(int i=0;i<n;i++) for(int j=0;j<2;j++) cin>>nums[i][j];
    vector<vector<int>>ans=mergeOverlaps2(nums,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<2;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }

}