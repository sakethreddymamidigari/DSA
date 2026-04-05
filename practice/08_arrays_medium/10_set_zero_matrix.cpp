#include<bits/stdc++.h>
using namespace std;
void setones(vector<vector<int>> &matrix,int n,int m, int i, int j){
    for(int i=0;i<n;i++){
        if (matrix[i][j]!=0) matrix[i][j]=-1;
    }
    for(int j=0;j<m;j++) {
        if(matrix[i][j]!=0) matrix[i][j]=-1;
    }
    return;
}
void setMatrixzeroes1(vector<vector<int>> &matrix,int n, int m){
    // Brute force
    // TC: O((n*m)*(n+m)+(n+m))
    // SC: O(1)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0) setones(matrix,n,m,i,j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1) matrix[i][j]=0;
        }
    }
    return ;
    
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    setMatrixzeroes1(matrix,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}