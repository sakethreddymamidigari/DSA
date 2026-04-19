/*
    searching an element in sorted matrix
    
    TC: O(log(n*m))
    SC: O(1)

    Input:
    n=4 m=5 target=6
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    16 17 18 19 20

    Output:
    true


*/

#include<bits/stdc++.h>
using namespace std;

bool searchSortedMatrix(vector<vector<int>> matrix,int n,int m, int target){
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(matrix[mid/m][mid%m]==target) return true;
        else if(matrix[mid/m][mid%m]>target) high=mid-1;
        else low=mid+1;
    }
    return false;
}

int main(){
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    cout<<searchSortedMatrix(matrix,n,m,target);
}