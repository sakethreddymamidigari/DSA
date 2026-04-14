//  finding the value which is equal to n when its power rised to m
//  ie value^m==n

#include<bits/stdc++.h>
using namespace std;
/*
    TC: O(m*logn)
    SC: O(1)
*/
int power(int mid, int n, int m){
    int ans=1;
    for(int i=1;i<=m;i++){
        ans*=mid;
        if(ans>n) return 2;
        else if(ans==n) return 1;
    }
    return 0;
}

int nThSqrt(int n,int m){
    int low=1,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        int pValue=power(mid,n,m);
        if(pValue==1) return mid;
        else if(pValue==2) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<nThSqrt(n,m);
}