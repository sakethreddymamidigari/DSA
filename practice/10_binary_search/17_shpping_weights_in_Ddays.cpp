/*
    finding the minimum capacity require for shipping n weights in d days
    weights should be loaded in the same order as given
    // TC: O(n+n*logm) m=sum of total wieghts - max weight in weights
    // SC: O(1)

    Input:
    n=10 days=5
    1 2 3 4 5 6 7 8 9 10

    Output:
    15


    day 1: 1 2 3 4 5
    day 2: 6 7
    day 3: 8
    day 4: 9
    day 5: 10
*/

#include<bits/stdc++.h>
using namespace std;

pair<int,int> minAndSum(vector<int> weights, int n){  // O(n)
    int maxi=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,weights[i]);
        sum+=weights[i];
    }

    return {maxi,sum};
}

int checkShippingDays(vector<int> weights, int n,int cap){ //O(n)
    int days=1,load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i]>cap){
            days++;
            load=weights[i];
        }
        else load+=weights[i];
    }
    return days;
}

int minShipCapacity(vector<int> weights, int n, int d){  //O(logm)
    pair<int,int> lowHigh=minAndSum(weights,n);
    int low=lowHigh.first, high=lowHigh.second;
    cout<<low<<" "<<high<<endl;
    while(low<high){
        int mid=low+(high-low)/2;
        if(checkShippingDays(weights,n,mid)<=d) high=mid;
        else low=mid+1;
    }
    return low;
}

int main(){
    int n,d;
    cin>>n>>d;
    vector<int> weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    cout<<minShipCapacity(weights,n,d);
}