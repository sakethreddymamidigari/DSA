/*
    find the row with max no.of ones in row sorted matrix with 0's and 1's

    Input:
    4 5
    0 0 0 0 1
    0 1 1 1 1
    0 0 1 1 1
    0 1 1 1 1

    Output:
    1
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> matrix, int m){
    int low=0,high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(matrix[mid]>=1) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    int maxi=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt=m-lowerBound(matrix[i],m);
        if(cnt>maxi){
            maxi=cnt;
            ind=i;
        }
    }
    cout<<ind;
}