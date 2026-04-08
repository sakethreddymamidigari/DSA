// printing the rth row elements

#include<bits/stdc++.h>
using namespace std;

/*  Brute force 
    TC: O(r*r)
    SC: O(r)
    Adding r elements by calculating nCr: n=r-1 ,r=c-1
*/

vector<int> generateRow(int r){
    // Optimal solution
    // TC: O(r)
    // SC: O(r)
    vector<int> ans;
    ans.push_back(1);
    int sum=1;
    for(int i=1;i<r;i++){
        sum=sum*(r-i);
        sum=sum/i;
        ans.push_back(sum);
    }
    return ans;
}

int main(){
    int r;
    cin>>r;
    vector<int> ans=generateRow(r);
    for(int i=0;i<r;i++) cout<<ans[i]<<" ";
}