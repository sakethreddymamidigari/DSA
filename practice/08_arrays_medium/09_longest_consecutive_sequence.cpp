#include<bits/stdc++.h>
using namespace std;

bool ls(vector<int> nums,int n, int x){
    for(int i=0;i<n;i++){
        if(nums[i]==x) return true;
    }
    return false;
}

int longestConsecutiveSequence1(vector<int> nums, int n){
    // Brute force approach
    // TC: O(n^2)
    // SC: O(1)

    int maxi=1;
    for(int i=0;i<n;i++){
        int x=nums[i],cnt=1;
        while(ls(nums,n,x+1)==true){ // line 4: linear searching the x+1 in nums
            cnt++;
            x=x+1;
            maxi=max(maxi,cnt);
        }
    }
    return maxi;
}

int longestConsecutiveSequence2(vector<int> nums, int n){
    // Better solution
    // TC: O(nlogn+n)
    sort(nums.begin(),nums.end());
    int maxi=1,cnt=1;
    for(int i=1;i<n;i++){
        if(nums[i-1]==nums[i]-1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else if(nums[i-1]!=nums[i]-1 && nums[i-1]!=nums[i]) cnt=1;
    }
    return maxi;
}
int longestConsecutiveSequence3(vector<int> nums, int n){
    // Optimal solution
    // TC: O(n) in avg case
    // TC: O(n^2) if collision occures in unordered_set (not an optimal solution)
    // SC: O(n) for set
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }
    int maxi=1;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            maxi=max(maxi,cnt);
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<longestConsecutiveSequence3(nums,n);
}