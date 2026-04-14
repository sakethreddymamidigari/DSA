/*
    Min days to prepare b bouquets using distinct and adjacent f flowers each bouquets
    iTh flower bloomes in flowers[i]th day

    TC: O(n*log(high-low+1)+n)
    SC: O(1)

    Input:
    n=11 b=3 f=3(flowers in each bouquets)
    7 7 7 7 13 11 50 12 7 5 14

    Output:
    13

    7 7 7
    7 13 11
    12 7 5
    at min 13 days to requied bloome 9 flowers
*/

#include<bits/stdc++.h>
using namespace std;


// O(n)
pair<int,int> minMax(vector<int> flowers,int n){
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,flowers[i]);
        maxi=max(maxi,flowers[i]);
    }
    return {mini,maxi};
}

// O(n)
int countBouquets(vector<int> flowers,int n,int f,int day){
    int cnt=0,bCnt=0;
    for(int i=0;i<n;i++){
        if(flowers[i]<=day) cnt++;
        else{
            bCnt+=cnt/f;
            cnt=0;
        }
    }
    bCnt+=cnt/f;
    return bCnt;
}

// O(log(high-low+1))
int minDaysToMakeBouquets(vector<int> flowers,int n, int b,int f){
    int low=minMax(flowers,n).first, high=minMax(flowers,n).second;
    while(low<high){
        int mid=(low+high)/2;
        if(countBouquets(flowers,n,f,mid)<b) low=mid+1;
        else high=mid;
    }
    return low;
}

int main(){
    int n,b,f;
    cin>>n>>b>>f;
    vector<int> flowers(n);
    for(int i=0;i<n;i++) cin>>flowers[i];
    if(b*f>n) cout<<-1;
    else cout<<minDaysToMakeBouquets(flowers,n,b,f);
}