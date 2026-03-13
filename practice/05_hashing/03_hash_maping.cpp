#include<bits/stdc++.h>
using namespace std;
void hashKey(int n,int arr[],int q){
    map<int,int> mapp;
    for(int i=0;i<n;i++) mapp[arr[i]]++;
    int num;
    while(q--){
        cin>>num;
        cout<<num<<" "<<mapp[num]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    hashKey(n,arr, q);
}