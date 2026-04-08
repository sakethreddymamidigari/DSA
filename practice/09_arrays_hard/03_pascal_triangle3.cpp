// printing r rows of pascal triangle

#include<bits/stdc++.h>
using namespace std;

/*  Brute force
    TC: O(n^3)
    SC: O(n^2)
    by using nCr method to calculate each element in each row of triangle 
*/

vector<int> generateRow(int r){
    // Optimal solution
    // TC: (r^2)
    // SC: (r^2)
    vector<int> row;
    row.push_back(1);
    int sum=1;
    for(int i=1;i<r;i++){
        sum=sum*(r-i);
        sum=sum/i;
        row.push_back(sum);
    }
    return row;
}


int main(){
    int r;
    cin>>r;
    vector<vector<int>> ans;
    for(int i=1;i<=r;i++){
        ans.push_back(generateRow(i));
    }
    // O(r)
    for(int i=0;i<r;i++){
        for(int j=0;j<=i;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}