#include<bits/stdc++.h>
using namespace std;

void palindrome(int n){
    int rev=0;
    int dup=n;
    while (n>0){
        int lastDig=n%10;
        rev=(rev*10)+lastDig;
        n=n/10;
    }
    if( dup==rev) cout<<"True";
    else cout<<"False";
}
int main(){
    int n;
    cin>>n;
    palindrome(n);
}