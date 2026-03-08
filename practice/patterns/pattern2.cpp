#include <bits/stdc++.h>
using namespace std;
void pattern1(int n){
    for(int i=1;i<=n;i++){
        // spaces
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        //stars
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        // spaces
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        pattern1(n);
    }

}