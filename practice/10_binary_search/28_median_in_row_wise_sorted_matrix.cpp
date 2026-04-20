/*
    find the median of row wise sorted matrix
    whose size n*m and n and m are odd intergers
    so n*m is also odd
    
    TC: O(log(max-min)*n*logm)
    SC: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> row, int m,int value){  // log(m)
    // applying upper bound for each col
    int low=0,high=m-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(row[mid]<=value) low=mid+1;
        else high=mid-1;
    }

    return low;
}

int cntLesser(vector<vector<int>> &matrix,int n,int m,int mid){   // n
    int cnt=0;

    for(int i=0;i<n;i++){ // checking no.of values lesser than or equal to mid in row
        cnt+=upperBound(matrix[i],m,mid);
    }
    return cnt;
}

int findMedianInMatrix(vector<vector<int>> &matrix, int n, int m){
    int low=INT_MAX, high=INT_MIN;
    
    for(int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }

    int req=(n*m)/2;

    while(low<=high){     // log(max-min)
        int mid=low+(high-low)/2;
        int cnt=cntLesser(matrix,n,m,mid);
        if(cnt<=req) low=mid+1;
        else high=mid-1;
    }

    return low;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    cout<<findMedianInMatrix(matrix,n,m);
}