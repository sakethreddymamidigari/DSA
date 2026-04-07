#include<bits/stdc++.h>
using namespace std;
void rotateMatrix1(vector<vector<int>> &matrix, int n){
    // TC: O(n*n)
    // SC: O(1)
    for(int i=0;i<n-1;i++){  // O(n/2)
        for(int j=i+1;j<n;j++){  // O(n/2)
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++) reverse(matrix[i].begin(),matrix[i].end()); // O(n*n)
    return;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>matrix[i][j];
    rotateMatrix1(matrix,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}