/*
    print the missing and repeating element in the array
    
    Input:
    6
    2 1 4 6 2 5 

    Output:
    2,3
    2 is repeated twice
    3 is missing

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> repeatingAndMissing(vector<int> nums, int n){
    // Otpimal solution
    // TC: O(n)
    // SC: O(1)
    long long s1=0,s2=0;
    for(int i=0;i<n;i++){
        s1+=nums[i];
        s2+=nums[i]*nums[i];
    }
    long long s1N=(n*(n+1))/2;
    long long s2N=(n*(n+1)*(2*n+1))/6;
    long long val1=s1-s1N;
    long long val2=s2-s2N;
    val2=val2/val1;
    int x=(val1+val2)/2;
    int y=x-val1;

    return {x,y};
}



int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> ans = repeatingAndMissing(nums,n);
    cout<<ans[0]<<" "<<ans[1];
}