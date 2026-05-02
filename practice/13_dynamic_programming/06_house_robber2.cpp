#include<bits/stdc++.h>
using namespace std;
// Similar to house robber 1 but houses are in circle
// Either first or last house need to excluded in every ans
int houseRobber1(vector<int> &house, int n){
    //  Excluding last element
    int prev1=house[0],prev2=0;
    for(int i=0;i<n;i++){
        int pick=house[i];
        if(i>1) pick+=prev2;
        int notPick=prev1;
        int current=max(pick,notPick);
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}

int houseRobber2(vector<int> &house, int n){
    // Excluding first element
    int prev1=house[1],prev2=0;
    for(int i=2;i<n;i++){
        int pick=house[i];
        if(i>2) pick+=prev2;
        int notPick=prev1;
        int current=max(pick,notPick);
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    vector<int> house(n);
    for(int i=0;i<n;i++) cin>>house[i];
    vector<int> dp(n,-1);
    // cout<<houseRobber1(house,dp,n-1); // Memoization
    // cout<<houseRobber2(house,dp,n);   // Tabulation
    int first=houseRobber1(house,n-1);        // Space Optimization
    int last=houseRobber2(house,n);
    cout<<max(first,last);
}
