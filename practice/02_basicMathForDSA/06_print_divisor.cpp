#include<bits/stdc++.h>
using namespace std;

//O(sqrt(n)+no.of factors)
void divisors(int n){
    vector<int> frnt;
    vector<int> rev;
    //O(sqrt(n))
    for(int i=1;i*i<=n;i++){
        if (n%i==0){
            frnt.push_back(i);
            if(n/i!=i){
                rev.push_back(n/i);
            }
            
            }
        }
    // O((no.of factors)/2)
    for(int x:frnt){
        cout<<x<<" ";
    }
    // size() returns the stored value, so takes O(1)
    //O((no.of factor)/2)
    for(int i=rev.size()-1;i>=0;i--){
        cout<<rev[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    divisors(n);
}