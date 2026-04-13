#include<bits/stdc++.h>
using namespace std;

int sqrtN(int n){
    int low=0,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid<=n) low=mid+1;
        else high=mid-1;
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    cout<<sqrtN(n);
}