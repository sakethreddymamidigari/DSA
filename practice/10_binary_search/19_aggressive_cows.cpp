/*
    arrenge c cows in n stall with minimum space between any two to be maximum
    TC: O(n*logm) m=max(stalls)
    SC: O(1)

    Input:
    6 3
    1 3 5 7 9 11

    Output:
    4
    
    At [0 5 9] or [0 5 11] or [0 7 11] or [3 7 11]

*/

#include<bits/stdc++.h>
using namespace std;

bool arrengeCows(vector<int> stalls,int n,int c,int mid){
    int cows=1,last=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-last>=mid){
            cows++;
            last=stalls[i];
        }
        if(cows==c) return true;
    }
    return false;
}

int aggressiveCows(vector<int> stalls,int n,int c){
    sort(stalls.begin(),stalls.end());
    int low=0,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arrengeCows(stalls,n,c,mid)==1) low=mid+1;
        else high=mid-1;
    }
    return high;
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> stalls(n);
    for(int i=0;i<n;i++) cin>>stalls[i];
    cout<<aggressiveCows(stalls,n,c);
}