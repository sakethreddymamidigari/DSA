#include<bits/stdc++.h>
using namespace std;

//runs for log10(n) times
void armStrong(int n){
    int cnt=0,res=0,temp=n;
    // counting the digits
    if (n==0){
        cnt=1;
    }
    else{
        cnt=log10(n)+1;
        }
    while(temp!=0){
        int last_dig=temp%10;
        int power=1;
        for(int i=0;i<cnt;i++){
            power*=last_dig;
        }
        res+=power;
        temp/=10;
    }
    if(res==n) cout<<"True";
    else cout<<"False";
}
int main(){
    int n;
    cin>>n;
    armStrong(n);
}