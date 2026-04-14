/*
    finding the minimum bananas to eat per hour to complete
    all the piles in given time(hrs)
    TC:O(n*log(maxi))
    SC:O(1)

    input:
    n=4 hours=10
    bananas=[3 6 7 11]

    output:
    3
    ceils(3/3+6/3+7/3+11/3)==> 1+2+3+4==>10

*/

#include<bits/stdc++.h>
using namespace std;

// finding the pile with max bananas
int maxi(vector<int> bananas, int n){
    int maxi=0;
    for(int i=0;i<n;i++) maxi=max(maxi,bananas[i]);
    return maxi;
}

// finding total hours required to eat all bananas with a speed of eating mid bananas in hour  
int findHours(vector<int> bananas,int n, int mid){
    int hours=0;
    for(int i=0;i<n;i++){
        hours+=ceil((double)bananas[i]/(double)mid);
    }
    return hours;
}


int kokoEatingBananas(vector<int> bananas,int n,int hours){
    // TC: O(n*log(maxi)+n)
    int low=0,high=maxi(bananas,n); // O(n)
    while(low<=high){
        int mid=(low+high)/2;
        if(findHours(bananas,n,mid)<=hours) high=mid-1; // O(n)
        else low=mid+1;
    }
    return low;
}

int main(){
    int n,hours;
    cin>>n>>hours;
    vector<int> bananas(n);
    for(int i=0;i<n;i++) cin>>bananas[i];
    cout<<kokoEatingBananas(bananas,n,hours);
}