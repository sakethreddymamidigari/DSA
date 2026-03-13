#include<bits/stdc++.h>
using namespace std;
void hashKey(string &s,int q){
    int hash[256]={0};
    for(int i=0;i<s.size();i++) hash[s[i]]++;
    char a;
    while(q--){
        cin>>a;
        cout<<a<<" "<<hash[a]<<endl;
    }
}

int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    hashKey(s,q);
}