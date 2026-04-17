/*
    minimize the max distance between any two gas distance by placing k gas station in between them


    Input:
    n=4 m=5
    dist=[1 12 17 22]

    Output:
    2.75

*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1
long double gasStations1(vector<int> &dist, int n, int k){
    // Brute force
    // TC: O(k*n)
    // SC: O(n)

    vector<int> howMany(n-1,0);
    for(int gS=0;gS<k;gS++){
        long double maxDist=-1;
        int ind=-1;
        for(int i=0;i<n-1;i++){
            long double diff=dist[i+1]-dist[i];
            long double secLen=diff/(long double)(howMany[i]+1);
            if(secLen>maxDist){
                maxDist=secLen;
                ind=i;
            }
        }
        howMany[ind]++;
    }

    long double maxDist=-1;
    for(int i=0;i<n-1;i++){
        long double diff=dist[i+1]-dist[i];
        long double secLen=diff/(long double)(howMany[i]+1);
        maxDist=max(maxDist,secLen);
    }
    return maxDist;
}

// Approach 2
long double gasStations2(vector<int> &dist, int n, int k){
    // Optimal Solution
    // TC: O(klongn +nlogn);
    // SC: O(2*n)

    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0;i<n-1;i++) pq.push({dist[i+1]-dist[i],i}); // O(nlogn)

    for(int i=0;i<k;i++){   // O(n)
        auto tp=pq.top(); pq.pop();
        int secInd=tp.second;
        howMany[secInd]++;
        long double intDiff=dist[secInd+1]-dist[secInd];
        long double newDiff=intDiff/(long double)(howMany[secInd]+1);
        pq.push({newDiff,secInd});  // O(logn)
    }

    return pq.top().first;
}

// Approach 3

long double maximumDist(vector<int> &dist,int n){
    long double maxi=0;
    for(int i=0;i<n-1;i++){
        maxi=max(maxi,(long double)dist[i+1]-dist[i]);
    }
    return maxi;
}

int countStation(vector<int> &dist,long double mid, int n){
    int cnt=0;
    for(int i=0;i<n-1;i++){
        int inBtwnDist=(dist[i+1]-dist[i])/mid;
        if((dist[i+1]-dist[i])/mid==inBtwnDist*mid)    inBtwnDist--;
        cnt+=inBtwnDist;
    }
    return cnt;
}


long double gasStations3(vector<int> &dist, int n, int k){
    // Optimal solution
    // TC: O(nlogm)  m=max distance between any two station in input
    // SC: O(1)
    long double low=0,high=maximumDist(dist,n);
    while(high-low>1e-6){
        long double mid=low+(high-low)/2;
        if (countStation(dist,mid,n)>k) low=mid;
        else high=mid;
    }
    return high;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> dist(n);
    for(int i=0;i<n;i++) cin>>dist[i];
    cout<<gasStations3(dist,n,k);
}