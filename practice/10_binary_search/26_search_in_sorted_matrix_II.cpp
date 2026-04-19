/*
    searching an element in sorted matrix
    each row and colomns are sorted individually

    TC: O(n+m)
    SC: O(1)

    Input:
    n=4 m=5 target=6
    1  4  7  11  15
    2  5  8  12  19
    2  6  9  16  22
    18 21 23 26  30

    Output:
    true


*/

#include<bits/stdc++.h>
using namespace std;

bool searchSortedMatrix(vector<vector<int>> matrix,int n,int m, int target){
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]>target) col--;
        else row++;
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