/*
    find the peak element in matrix and return its row and col
    an element greater than its adjacent(left,right,top & bottom) elements

    TC: O(nlogm)
    SC: O(1)

    Input:
    4 5
    1  4  7  11  15
    2  5  20  12  19
    2  6  9  16  22
    18 21 23 26  30

    Output:
    3 4
    
    both 20 30 are peak elements
    */

#include<bits/stdc++.h>
using namespace std;

int searchMax(vector<vector<int>> matrix,int n,int mid){
    int maxi=INT_MIN, ind=-1;
    for(int i=0;i<n;i++){
        if(matrix[i][mid]>maxi){
            ind=i;
            maxi=matrix[i][mid];
        }
    }
    return ind;
}

pair<int,int> findPeakInMatrix(vector<vector<int>> &matrix,int n,int m){
    int low=0,high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=searchMax(matrix,n,mid);
        int left=INT_MIN,right=INT_MIN;
        if(mid>0) left=matrix[row][mid-1];
        if(mid<m-1) right=matrix[row][mid+1];
        if(left < matrix[row][mid] && matrix[row][mid]>right) return {row,mid};
        else if(left > matrix[row][mid]) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    pair<int,int> position=findPeakInMatrix(matrix,n,m);
    cout<<position.first<<" "<<position.second;
}