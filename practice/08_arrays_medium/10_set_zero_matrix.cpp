#include<bits/stdc++.h>
using namespace std;

// APPROACH : 1
void setones(vector<vector<int>> &matrix,int n,int m, int i, int j){
    // setMatrixzeroes1(vector<vector<int>> &matrix,int n, int m){
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
            if(matrix[i][j]==0) setones(matrix,n,m,i,j); // line 4
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==-1) matrix[i][j]=0;
        }
    }
    return ;
    
}


// APPROACH : 2
void setMatrixzeroes2(vector<vector<int>> &matrix,int n, int m){
    // Better solution using 2 array(row,col) to keep track of 0's in matrix
    // TC: O(2(n*m))
    // SC: O(n+m)
    vector<int> row(n);
    vector<int> col(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    return;
}

// APPROACH : 3
void setMatrixzeroes3(vector<vector<int>> &matrix,int n, int m){
    // Optimal solution using 0th row and col to keep track of 0's in matrx
    // TC: O(2(n*m))
    // SC: O(1)
    int col=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0) matrix[0][j]=0;
                else col=0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }
    if (matrix[0][0]==0) for(int j=0;j<m;j++) matrix[0][j]=0;
    if(col==0) for(int i=0;i<n;i++) matrix[i][0]=0;

    return;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    setMatrixzeroes3(matrix,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}