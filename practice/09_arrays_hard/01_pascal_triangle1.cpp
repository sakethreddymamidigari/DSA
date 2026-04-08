// printing the (r,c)the element from pascals triangle: nCr==>n=r-1, r=c-2
#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int c){
    // Optimal Approach
    // TC: O(c)
    // SC: O(1)
    int sum=1;
    for(int i=0;i<c;i++){
        sum=sum*(n-i);
        sum=sum/(i+1);
    }
    return sum;
}

int main(){
    int r,c;
    cin>>r>>c;
    cout<<nCr(r-1,c-1);
}