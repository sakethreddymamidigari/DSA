#include<bits/stdc++.h>
using namespace std;

void primeCheck(int n){
    int count=0;
    //O(sqrt(n))
    for(int i=1;i*i<=n;i++){
            if(n%i==0){
                count+=2;
                }
            }
    if(count==2) cout<<"True";
    else cout<<"False";
}
int main(){
    int n;
    cin>>n;
    primeCheck(n);
}