// print all the unique combination of three element whose sum equal to 0

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum1(vector<int> nums, int n){
    // Brute force
    // TC: O((n^3)*logm)
    // SC: 2*O(3m)   [m=no.of triplets]
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> threeSum2(vector<int> nums, int n){
    // Better solution
    // TC: O(n^2*logm)
    // SC: 2*O(3m)  [m=no.of triplets]
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        unordered_set<int> hashSet;
        for(int j=i+1;j<n;j++){
            int sum=-(nums[i]+nums[j]);
            if(hashSet.find(sum)!=hashSet.end()){
                vector<int> temp={nums[i],nums[j],sum};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }

    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> threeSum3(vector<int> nums, int n){
    // Optimal solution
    // TC: O((n^2)+nlogn)
    // SC: O(m)   [m=no.of triplets]
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum>0) k--;
            else if(sum<0) j++;
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<int>> ans=threeSum3(nums,n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}